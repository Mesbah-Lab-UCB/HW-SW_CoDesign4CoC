# script to generate codegen projects for experiments
import os
from datetime import datetime
import torch
import matlab.engine as matlab # matlab engine import

# start/connect to matlab engine
eng = matlab.start_matlab() # start new matlab engine

tkwargs = {
    "dtype": torch.double,
    "device": torch.device("cuda" if torch.cuda.is_available() else "cpu"),
}

dnn_trn_save_file = './saved/dnn_trn_data_exp_data.mat'
Nreps = 1
# parameters = {"H": 5,
#               "L": 3,
#               "fxp_word_length": 20,
#               "loopOpt": "LoopNone",
#               } # utopia parameters
# parameters = {"H": 5,
#               "L": 2,
#               "fxp_word_length": 13,
#               "loopOpt": "UnrollLoops",
#               } # control performance preferred
# parameters = {"H": 8,
#               "L": 2,
#               "fxp_word_length": 18,
#               "loopOpt": "LoopNone",
#               } # constraint satisfaction preferred
parameters = {"H": 6,
              "L": 2,
              "fxp_word_length": 18,
              "loopOpt": "LoopNone",
              } # test

####################################################################
# helper function to convert MATLAB data to torch Tensors
####################################################################
def convert_data(data):
    # x = torch.tensor(data[0], **tkwargs)
    obj = torch.tensor(data[0], **tkwargs)
    obj_true = torch.tensor(data[1], **tkwargs)
    return obj, obj_true

####################################################################
# evaluation function to compute objective values
####################################################################
def evaluate(parameters, rand_seed2=0, save_prefix='', codegen_dir='./hdlcoder_fullDNN'):
    # run closed-loop simulation to get objective
    # print(parameters)
    x, objs, objs_true = eng.approx_msMPC_HIL(parameters,
            dnn_trn_save_file,
            'skip_mpc_test', True,
            'skip_dnn_test', True,
            'hw_obj', False,
            'use_perf_obj', True,
            'rand_seed2', rand_seed2,
            'save_prefix', save_prefix,
            'codegen_dir', codegen_dir,
            'exp_runs', True,
            nargout=3)
    objs, objs_true = convert_data([objs, objs_true])
    obj1 = objs[0]
    obj2 = objs[1]

    # set standard error to 0
    return {"obj1": (obj1.item(), None), "obj2": (obj2.item(), None)}

date = datetime.now().strftime('%Y_%m_%d_%H'+'h%M'+'m%S'+'s')
os.makedirs(f"experiments/{date}", exist_ok=True)

for n in range(Nreps):
# n=1
    dir = f'./codegen{n}_H{parameters["H"]}_L{parameters["L"]}_wL{parameters["fxp_word_length"]}_{parameters["loopOpt"]}'
    os.makedirs(dir, exist_ok=True)
    save_prefix = f'experiments/{date}/rep{n}_exp0'

    # evaluate objectives to generate the programming files for hardware
    objectives = evaluate(parameters, save_prefix=save_prefix, codegen_dir=dir)
    print(objectives)
