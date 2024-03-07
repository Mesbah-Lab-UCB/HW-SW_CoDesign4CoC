# This file plots data obtained from experimental runs on the APPJ

import sys
sys.dont_write_bytecode = True
import numpy as np
import matplotlib.pyplot as plt
import os

plot_stats = False
plot_all_in_one = True
Fontsize = 15 # default font size for plots
Lwidth = 2 # default line width for plots

lines = {'linewidth' : Lwidth}
plt.rc('lines', **lines)
font = {'family' : 'serif',
        'serif'  : 'Times',
        'size'   : Fontsize}
plt.rc('font', **font)  # pass in the font dict as kwargs

# root directory for all experimental data in this project
root = './ExperimentalData/'
folder = '2022_07_18_16h10m22s'
exp_num = 0
filename = root+folder+f'/Backup/Experiment_{exp_num}.npy'

exp_data = np.load(filename, allow_pickle=True)
exp_data = exp_data.item()

print('Experimental Data Keys: ', [*exp_data])

print(exp_data['ArdSave'][0,:])
# Arduino data:
# 1. time (ms), 2. _, 3. Vp2p (V), 4. f (kHz), 5. q (slm),
# 6. x (mm), 7. y (mm), 8. z/dsep (mm), 9. Temb, 10. Pemb (W),
# 11. Pset (W), 12. duty (%) 13/14 Vemb and Iemb

data_dirs = sorted(os.listdir(root))
print(data_dirs)
best_cg = [data_dirs[-7]]
best_perf_cg = [data_dirs[-5]]
best_cons_cg = [data_dirs[-3]]
# msmpc = [data_dirs[-10]]
# msmpc = data_dirs[-7:-1]
msmpc = [data_dirs[-12]]
Nreps = 5
ts = 0.5

excluded_runs = [] # exclude certain runs from all trials

data_dirs_part = [best_cg, best_perf_cg, best_cons_cg, msmpc]
# data_dirs_part = [msmpc]
print(data_dirs_part)
types = ['BALANCED', 'PERFORMANCE', 'CONSTRAINT SATISFACTION', 'SMPC']
colors = ['C0', 'C1', 'C2', 'C4']

if plot_stats or plot_all_in_one:
    fig1, (ax11, ax12, ax13) = plt.subplots(3,1, sharex=True) # figure for states
    ax11.axhline(1.5, color='k', label='Setpoint', linestyle='--')
    ax12.axhline(47, color='r', label='Constraint', linestyle='--')
    fig2, (ax21, ax22) = plt.subplots(2,1, sharex=True) # figure for inputs
    ax21.axhline(1.5, color='r', linestyle='--')
    ax21.axhline(5.5, color='r', linestyle='--')
    ax22.axhline(1.5, color='r', linestyle='--')
    ax22.axhline(5.5, color='r', linestyle='--')

for dirs,exp_type,plot_color in zip(data_dirs_part, types, colors):
    print(exp_type)
    if not (plot_stats or plot_all_in_one):
        fig1, (ax11, ax12, ax13) = plt.subplots(3,1, sharex=True) # figure for states
        ax11.axhline(1.5, color='k')
        ax12.axhline(47, color='r')
        fig2, (ax21, ax22) = plt.subplots(2,1, sharex=True) # figure for inputs
        ax21.axhline(1.5, color='r', linestyle='--')
        ax21.axhline(5.5, color='r', linestyle='--')
        ax22.axhline(1.5, color='r', linestyle='--')
        ax22.axhline(5.5, color='r', linestyle='--')
        fig3, (ax31, ax32) = plt.subplots(2,1, sharex=True) # figure for Arduino inputs

    count = 1
    for data_dir in dirs:

        if exp_type == 'SMPC':
            Nreps = 10
            excluded_runs = [0]

        CEMs = np.empty((Nreps-len(excluded_runs),240))
        CEMs[:] = np.nan
        Tss = np.empty((Nreps-len(excluded_runs),240))
        Tss[:] = np.nan
        Iss = np.empty((Nreps-len(excluded_runs),240))
        Iss[:] = np.nan
        Ps = np.empty((Nreps-len(excluded_runs),240))
        Ps[:] = np.nan
        qs = np.empty((Nreps-len(excluded_runs),240))
        qs[:] = np.nan

        end_xs = []
        count2 = 0
        obj1 = np.zeros((Nreps,))
        obj2 = np.zeros((Nreps,))

        for i in range(Nreps):
            print(f'--------------REPETITION: {i}-----------------\n')
            common_kwargs = {}

            if i in excluded_runs:
                pass
            else:
                filename = root+data_dir+f'/Backup/Experiment_{i}.npy'

                exp_data = np.load(filename, allow_pickle=True)
                exp_data = exp_data.item()

                bt = exp_data['badTimes']
                if bool(bt):
                    print(f'Data Directory: {data_dir}, Experiment Number: {i}, BadTimes: {bt}')

                # extract data
                CEM = exp_data['CEMsim'][:,:-1]
                data_mask = np.ravel(CEM>0)
                # print(np.sum(data_mask))
                data_mask[0] = True
                CEM = np.ravel(CEM[:,data_mask])
                # print(np.sum(data_mask))
                Ts = exp_data['Tsave'][data_mask]
                Is = exp_data['Isave'][data_mask]
                P = exp_data['Psave'][data_mask]
                q = exp_data['qSave'][data_mask]
                CEMref = exp_data['Yrefsim'][:,data_mask]
                Pset = exp_data['ArdSave'][data_mask,10]
                Pemb = exp_data['ArdSave'][data_mask,9]
                qemb = exp_data['ArdSave'][data_mask,4]

                o1 = np.sum((1.5-CEM[:-3])**2)
                o2 = np.sum(np.where(Ts[:-3]>47, Ts[:-3]-47,0)**2)
                print(f'PERFORMANCE OBJECTIVE: {o1}\n')
                print(f'SAFETY OBJECTIVE: {o2}\n')
                obj1[i] = o1
                obj2[i] = o2

                t = np.arange(len(Ts[:-3]))*ts
                tu = t[:-1]

                if CEM[-4]>1.5:
                    CEM[-4] = 1.5

                if plot_stats or plot_all_in_one:

                    end_x = np.sum(data_mask)-3
                    end_u = end_x-1
                    CEMs[count2,:end_x] = CEM[:-3]
                    Tss[count2,:end_x] = Ts[:-3]
                    Iss[count2,:end_x] = Is[:-3]
                    Ps[count2,:end_u] = P[:-4]
                    qs[count2,:end_u] = q[:-4]

                    end_xs.append(end_x)

                # elif plot_all_in_one:
                #
                #     common_kwargs['color'] = plot_color
                #     if exp_type == 'SMPC':
                #         common_kwargs['alpha'] = 0.2
                #     else:
                #         common_kwargs['alpha'] = 0.4
                #     ax11.plot(t, CEM[:-3], **common_kwargs)
                #     ax12.plot(t, Ts[:-3], **common_kwargs)
                #     if i == 1:
                #         ax13.plot(t, Is[:-3], label=exp_type, **common_kwargs)
                #     else:
                #         ax13.plot(t, Is[:-3], **common_kwargs)
                #
                #     ax21.step(tu, P[:-4], **common_kwargs)
                #     if i == 1:
                #         ax22.step(tu, q[:-4], label=exp_type, **common_kwargs)
                #     else:
                #         ax22.step(tu, q[:-4], **common_kwargs)

                else:
                    common_kwargs['label'] = f'exp{count}'
                    if count == 4:
                        common_kwargs['color'] = 'C9'
                    ax11.plot(t, CEM[:-3], **common_kwargs)
                    ax12.plot(t, Ts[:-3], **common_kwargs)
                    ax13.plot(t, Is[:-3], **common_kwargs)

                    ax21.step(tu, P[:-4], **common_kwargs)
                    ax22.step(tu, q[:-4], **common_kwargs)

                    ax31.step(tu, Pset[:-4], '--', **common_kwargs)
                    ax31.step(tu, Pemb[:-4], **common_kwargs)
                    ax32.step(tu, qemb[:-4], **common_kwargs)

                count2+=1

            count+=1

        print(f'MEAN OBJ1: {np.mean(obj1)}\n')
        print(f'STD OBJ1: {np.std(obj1)}\n')
        print(f'STE OBJ1: {np.std(obj1)/np.sqrt(Nreps)}\n')
        print(f'MEAN OBJ2: {np.mean(obj2)}\n')
        print(f'STD OBJ2: {np.std(obj2)}\n')
        print(f'STE OBJ2: {np.std(obj2)/np.sqrt(Nreps)}\n')

        if plot_stats or plot_all_in_one:
            max_x_idx = np.argmax(end_xs)
            min_x_idx = np.argmin(end_xs)
            max_end_x = end_xs[max_x_idx]
            min_end_x = end_xs[min_x_idx]
            max_end_u = max_end_x-1
            t = np.arange(max_end_x)*ts
            tu = t[:-1]

        if plot_stats:

            CEM_mean = (np.nanmean(CEMs, axis=0))[:max_end_x]
            CEM_std = (np.nanstd(CEMs, axis=0))[:max_end_x]
            Ts_mean = (np.nanmean(Tss, axis=0))[:max_end_x]
            Ts_std = (np.nanstd(Tss, axis=0))[:max_end_x]
            Is_mean = (np.nanmean(Iss, axis=0))[:max_end_x]
            Is_std = (np.nanstd(Iss, axis=0))[:max_end_x]
            P_mean = (np.nanmean(Ps, axis=0))[:max_end_u]
            P_std = (np.nanstd(Ps, axis=0))[:max_end_u]
            q_mean = (np.nanmean(qs, axis=0))[:max_end_u]
            q_std = (np.nanstd(qs, axis=0))[:max_end_u]
            print(CEM_mean.shape)

            ax11.plot(t, CEM_mean, label=exp_type, **common_kwargs)
            ax12.plot(t, Ts_mean, **common_kwargs)
            ax13.plot(t, Is_mean, **common_kwargs)

            ax11.fill_between(t, np.ravel(CEM_mean-CEM_std), np.ravel(CEM_mean+CEM_std), alpha=0.2)
            ax12.fill_between(t, np.ravel(Ts_mean-Ts_std), np.ravel(Ts_mean+Ts_std), alpha=0.2)
            ax13.fill_between(t, np.ravel(Is_mean-Is_std), np.ravel(Is_mean+Is_std), alpha=0.2)

            ax21.step(tu, P_mean, **common_kwargs)
            ax22.step(tu, q_mean, **common_kwargs)

            ax21.fill_between(tu, np.ravel(P_mean-P_std), np.ravel(P_mean+P_std), alpha=0.2)
            ax22.fill_between(tu, np.ravel(q_mean-q_std), np.ravel(q_mean+q_std), alpha=0.2)

        elif plot_all_in_one:
            common_kwargs['color'] = plot_color

            CEM_max = CEMs[max_x_idx,:max_end_x]
            CEM_min = 1.5*np.ones_like(CEM_max)
            CEM_min[:min_end_x] = CEMs[min_x_idx,:min_end_x]
            Ts_max = (np.nanmax(Tss, axis=0))[:max_end_x]
            Ts_min = (np.nanmin(Tss, axis=0))[:max_end_x]
            Is_max = (np.nanmax(Iss, axis=0))[:max_end_x]
            Is_min = (np.nanmin(Iss, axis=0))[:max_end_x]
            P_max = (np.nanmax(Ps, axis=0))[:max_end_u]
            P_min = (np.nanmin(Ps, axis=0))[:max_end_u]
            q_max = (np.nanmax(qs, axis=0))[:max_end_u]
            q_min = (np.nanmin(qs, axis=0))[:max_end_u]

            Ts_med = (np.nanmedian(Tss, axis=0))[:max_end_x]
            Is_med = (np.nanmedian(Iss, axis=0))[:max_end_x]
            P_med = (np.nanmedian(Ps, axis=0))[:max_end_u]
            q_med = (np.nanmedian(qs, axis=0))[:max_end_u]

            ax12.plot(t, Ts_med, label=exp_type, **common_kwargs)
            ax13.plot(t, Is_med, label=exp_type, **common_kwargs)

            ax21.step(tu, P_med, label=exp_type, **common_kwargs)
            ax22.step(tu, q_med, label=exp_type, **common_kwargs)

            ax11.fill_between(t, np.ravel(CEM_min), np.ravel(CEM_max), alpha=0.2, **common_kwargs)
            ax12.fill_between(t, np.ravel(Ts_min), np.ravel(Ts_max), alpha=0.2, **common_kwargs)
            ax13.fill_between(t, np.ravel(Is_min), np.ravel(Is_max), alpha=0.2, **common_kwargs)

            ax21.fill_between(tu, np.ravel(P_min), np.ravel(P_max), alpha=0.2, **common_kwargs)
            ax22.fill_between(tu, np.ravel(q_min), np.ravel(q_max), alpha=0.2, **common_kwargs)


    if not (plot_stats or plot_all_in_one):
        ax13.set_xlabel('Time (s)')
        ax22.set_xlabel('Time (s)')
        ax32.set_xlabel('Time (s)')

        lkwargs = {}
        if exp_type == 'SMPC':
            lkwargs['ncol'] = 3
        else:
            lkwargs['ncol'] = 2

        ax13.legend(fontsize='small', loc='lower right', bbox_to_anchor=(1.0,0.0), **lkwargs)
        ax22.legend(fontsize='small', loc='lower center', bbox_to_anchor=(0.5,0.0), **lkwargs)
        ax32.legend(fontsize='small', loc='upper right', bbox_to_anchor=(1.0,1.0), **lkwargs)

        fig1.suptitle(exp_type)
        fig2.suptitle(exp_type)
        fig3.suptitle(exp_type)

        ax11.set_ylabel('CEM (min)'); ax11.set_ylim([-0.1,1.6])
        ax12.set_ylabel('Surface\nTemperature ($^\circ$C)'); ax12.set_ylim([33,50])
        ax13.set_ylabel('Total Optical\nIntensity (arb. units)'); ax13.set_ylim([20,35])

        ax21.set_ylabel('Power (W)'); ax21.set_ylim([1,6])
        ax22.set_ylabel('Flow Rate (SLM)'); ax22.set_ylim([1,6])

        ax31.set_ylabel('Power (W)'); ax31.set_ylim([1,6])
        ax32.set_ylabel('Flow Rate (SLM)'); ax32.set_ylim([1,6])

if plot_stats:
    fig1.legend(fontsize='small', loc='lower right')
    fig2.legend(fontsize='small', loc='lower right')

    ax11.set_ylabel('CEM (min)'); ax11.set_ylim([-0.1,1.6])
    ax12.set_ylabel('Surface Temperature\n($^\circ$C)'); ax12.set_ylim([30,50])
    ax13.set_ylabel('Total Optical\nIntensity (arb. units)'); ax13.set_ylim([20,35])

    ax21.set_ylabel('Power (W)'); ax21.set_ylim([1,6])
    ax22.set_ylabel('Flow Rate (SLM)'); ax22.set_ylim([1,6])

if plot_all_in_one:

    ax13.set_xlabel('Time (s)')
    ax22.set_xlabel('Time (s)')

    ax13.legend(fontsize='small', loc='lower right', bbox_to_anchor=(1.0,0.0))
    # ax22.legend(fontsize='small', loc='upper center', bbox_to_anchor=(0.5,-0.1))

    ax11.set_ylabel('CEM (min)'); ax11.set_ylim([-0.1,1.6])
    ax12.set_ylabel('Surface Temperature\n($^\circ$C)'); ax12.set_ylim([30,50])
    ax13.set_ylabel('Total Optical\nIntensity (arb. units)'); ax13.set_ylim([20,35])

    ax21.set_ylabel('Power (W)'); ax21.set_ylim([1,6])
    ax22.set_ylabel('Flow Rate (SLM)'); ax22.set_ylim([1,6])

plt.show()
