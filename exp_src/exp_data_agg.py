# This file aggregates and plots data obtained from experimental runs on the APPJ

import sys
sys.dont_write_bytecode = True
import numpy as np
import matplotlib.pyplot as plt
import os
from scipy.io import loadmat,savemat

Fontsize = 15 # default font size for plots
Lwidth = 2 # default line width for plots

lines = {'linewidth' : Lwidth}
plt.rc('lines', **lines)
font = {'family' : 'serif',
        'serif'  : 'Times',
        'size'   : Fontsize}
plt.rc('font', **font)  # pass in the font dict as kwargs

# model = loadmat('../Model_ID/APPJmodel_2022_07_18_14h04m28s.mat')
model = loadmat('../Model_ID/APPJmodel_2022_07_22_11h40m51s.mat')
yss = np.ravel(model['yss'])
uss = np.ravel(model['uss'])
print(yss)

root = './ExperimentalData/'

# data_dirs = ['2022_07_08_11h47m56s','2022_07_07_16h45m45s']
# data_dirs = [['2022_07_08_17h17m03s']]
# data_dirs = [['2022_07_18_16h18m50s']]
# data_dirs = [['2022_07_18_16h49m15s']]
# data_dirs = [['2022_07_18_19h12m41s']]
# data_dirs = [['2022_07_21_11h30m25s']]
# data_dirs = [['2022_07_21_11h30m25s'],['2022_07_18_19h12m41s']]
data_dirs = [['2022_07_22_12h16m01s']]

dnn_data_save_file = './saved/dnn_trn_data_exp_data.mat'

exclude_data = []

Nreps = 10
ts = 0.5

alpha = 0.2
common_kwargs = {'alpha': alpha}
all_data_dnn_inputs = []
all_data_dnn_outputs = []

for dirs in data_dirs:
    fig1, (ax11, ax12, ax13) = plt.subplots(3,1, sharex=True) # figure for states
    ax11.axhline(1.5, color='r')
    ax12.axhline(47, color='r')
    fig2, (ax21, ax22) = plt.subplots(2,1, sharex=True) # figure for inputs

    count = 1
    for data_dir in dirs:
        for i in range(Nreps):
            if count in exclude_data:
                pass
            else:
                filename = root+data_dir+f'/Backup/Experiment_{i}.npy'
                common_kwargs['label'] = f'exp{count}'

                exp_data = np.load(filename, allow_pickle=True)
                exp_data = exp_data.item()

                bt = exp_data['badTimes']
                if bool(bt):
                    print(f'Data Directory: {data_dir}, Experiment Number: {i}, BadTimes: {bt}')

                # extract data
                CEM = exp_data['CEMsim'][:,:-1]
                data_mask = np.ravel(CEM>0)
                print(np.sum(data_mask))
                data_mask[0] = True
                CEM = np.ravel(CEM[:,data_mask])
                print(np.sum(data_mask))
                Ts = exp_data['Tsave'][data_mask]
                Is = exp_data['Isave'][data_mask]
                P = exp_data['Psave'][data_mask]
                q = exp_data['qSave'][data_mask]
                CEMref = exp_data['Yrefsim'][:,data_mask]
                print(Ts)

                n_extra = 3
                Ts = Ts[:-n_extra]
                Is = Is[:-n_extra]
                CEM = CEM[:-n_extra]
                P = P[:-n_extra]
                q = q[:-n_extra]

                all_data_dnn_inputs.append(np.stack([Ts-yss[0],Is-yss[1],CEM],axis=1))
                all_data_dnn_outputs.append(np.stack([P-uss[0],q-uss[1]],axis=1))

                t = np.arange(len(Ts))*ts
                tu = t[:-1]

                ax11.plot(t, CEM, **common_kwargs)
                ax12.plot(t, Ts, **common_kwargs)
                ax13.plot(t, Is, **common_kwargs)

                ax21.step(tu, P[:-1], **common_kwargs)
                ax22.step(tu, q[:-1], **common_kwargs)

            count+=1

    ax13.set_xlabel('Time (s)')
    ax22.set_xlabel('Time (s)')

    ax11.legend(fontsize='small', loc='upper right', bbox_to_anchor=(1.0,1.0))
    ax21.legend(fontsize='small', loc='upper right', bbox_to_anchor=(1.0,1.0))


    ax11.set_ylabel('CEM (min)'); ax11.set_ylim([-0.1,2.1])
    ax12.set_ylabel('Surface Temperature ($^\circ$C)'); ax12.set_ylim([30,60])

    ax21.set_ylabel('Power (W)'); ax21.set_ylim([1,5.5])
    ax22.set_ylabel('Flow Rate (SLM)'); ax22.set_ylim([1,5.5])

exp_dnn_inputs = np.concatenate(all_data_dnn_inputs,axis=0)
exp_dnn_outputs = np.concatenate(all_data_dnn_outputs,axis=0)

fig4, (ax41, ax42, ax43) = plt.subplots(3,1, sharex=True) # figure for dnn inputs
fig5, (ax51, ax52) = plt.subplots(2,1, sharex=True) # figure for dnn outputs

ax41.plot(exp_dnn_inputs[:,0])
ax42.plot(exp_dnn_inputs[:,1])
ax43.plot(exp_dnn_inputs[:,2])
ax51.plot(exp_dnn_outputs[:,0])
ax52.plot(exp_dnn_outputs[:,1])

fig4.suptitle('DNN RAW INPUTS')
fig5.suptitle('DNN RAW OUTPUTS')

inputs_min = np.amin(exp_dnn_inputs,axis=0)
outputs_min = np.amin(exp_dnn_outputs,axis=0)
inputs_max = np.amax(exp_dnn_inputs,axis=0)
outputs_max = np.amax(exp_dnn_outputs,axis=0)
in_range = inputs_max - inputs_min
out_range = outputs_max - outputs_min

sc_inputs = 2*(exp_dnn_inputs - inputs_min)/(in_range) - 1
sc_outputs = 2*(exp_dnn_outputs - outputs_min)/(out_range) - 1

fig4, (ax41, ax42, ax43) = plt.subplots(3,1, sharex=True) # figure for dnn inputs
fig5, (ax51, ax52) = plt.subplots(2,1, sharex=True) # figure for dnn outputs

ax41.plot(sc_inputs[:,0])
ax42.plot(sc_inputs[:,1])
ax43.plot(sc_inputs[:,2])
ax51.plot(sc_outputs[:,0])
ax52.plot(sc_outputs[:,1])

fig4.suptitle('DNN MIN-MAX SCALED INPUTS')
fig5.suptitle('DNN MIN-MAX SCALED OUTPUTS')

save_dict = {}
save_dict["inputs"] = sc_inputs.T
save_dict["outputs"] = sc_outputs.T
save_dict["input_min"] = inputs_min.reshape(-1,1)
save_dict["output_min"] = outputs_min.reshape(-1,1)
save_dict["input_max"] = inputs_max.reshape(-1,1)
save_dict["output_max"] = outputs_max.reshape(-1,1)

savemat(dnn_data_save_file, save_dict)

plt.show()
