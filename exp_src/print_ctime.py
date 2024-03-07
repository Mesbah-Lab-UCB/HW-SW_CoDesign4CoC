import numpy as np

# root directory for all experimental data in this project
root = './ExperimentalData/'
folder = '2022_07_22_13h54m22s' # fpga-based run
folder = '2022_07_22_12h16m01s' # msmpc
Nreps = 10

exp_nums = range(Nreps)
for i in exp_nums:
    filename = root+folder+f'/Backup/Experiment_{i}.npy'

    exp_data = np.load(filename, allow_pickle=True)
    exp_data = exp_data.item()

    bt = exp_data['badTimes']
    if bool(bt):
        print(f'Data Directory: {folder}, Experiment Number: {i}, BadTimes: {bt}')

    # extract data
    CEM = exp_data['CEMsim'][:,:-1]
    data_mask = np.ravel(CEM>0)
    # print(np.sum(data_mask))
    data_mask[0] = True
    CEM = np.ravel(CEM[:,data_mask])
    # print(np.sum(data_mask))

    ctime = exp_data['ctime'][data_mask]

    print(f'Experiment Number: {i}\n Max computation time: {np.max(ctime)}\n Average computation time: {np.mean(ctime)}')
