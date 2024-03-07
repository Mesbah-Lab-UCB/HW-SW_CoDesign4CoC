# script to run MOBO using Ax
import os
from scipy import io
from datetime import datetime

from ax.service.ax_client import AxClient
from ax.service.utils.instantiation import ObjectiveProperties
from ax.modelbridge.generation_strategy import GenerationStrategy, GenerationStep
from ax.modelbridge.registry import Models

import torch

import matlab.engine as matlab # matlab engine import

# start/connect to matlab engine
eng = matlab.start_matlab() # start new matlab engine
# eng = matlab.connect_matlab() # connect to existing matlab engine

tkwargs = {
    "dtype": torch.double,
    "device": torch.device("cuda" if torch.cuda.is_available() else "cpu"),
}
SMOKE_TEST = os.environ.get("SMOKE_TEST")

####################################################################
# helper function to convert MATLAB data to torch Tensors
####################################################################
def convert_data(data):
    # x = torch.tensor(data[0], **tkwargs)
    obj = torch.tensor(data[0], **tkwargs)
    obj_true = torch.tensor(data[1], **tkwargs)
    return obj, obj_true

####################################################################
# main script to run MOBO
####################################################################
if __name__ == '__main__':
    from ax.storage.json_store.save import save_experiment

    # generate training data if not exists
    n_trn = 750
    n_exps = 3
    n_BO = 60
    dnn_trn_save_file = './saved/dnn_trn_data_750samp.mat'
    random_sampling = True
    date = datetime.now().strftime('%Y_%m_%d_%H'+'h%M'+'m%S'+'s')
    os.makedirs(f"experiments/{date}", exist_ok=True)

    if dnn_trn_save_file is not None:
        dnn_trn_data = io.loadmat(dnn_trn_save_file)
        if dnn_trn_data["inputs"].shape[1] == n_trn:
            pass
        else:
            print('New training data generated. Old data file overwritten!')
            dnn_trn_save_file = eng.generate_dnn_data(n_trn,
                    'save_file',
                    dnn_trn_save_file,
                    nargout=1)
            print(dnn_trn_save_file)  # dnn_obj is not used
    else:
        dnn_trn_save_file = eng.generate_dnn_data(n_trn,
                'save_file',
                f'./saved/dnn_trn_data_{n_trn}samp.mat',
                nargout=1)

    ####################################################################
    # evaluation function to compute objective values
    ####################################################################
    def evaluate(parameters, rand_seed2=0, save_prefix=''):
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
                nargout=3)
        objs, objs_true = convert_data([objs, objs_true])
        obj1 = objs[0]
        obj2 = objs[1]

        # set standard error to 0
        return {"obj1": (obj1.item(), None), "obj2": (obj2.item(), None)}

    ####################################################################
    # run multiple trials of BO to account for stochasticity
    ####################################################################
    for n in range(n_exps):
        # setup experiments for MOBO
        # set random seed for repeatable experiments
        rs = int(42*(n+1234))
        # set generation strategy for BO implementation
        if random_sampling:
            gs = GenerationStrategy(steps=[GenerationStep(Models.SOBOL, num_trials=-1)])
        else:
            gs = GenerationStrategy(
                steps = [
                # 1. Initialization step (does not require pre-exisiting data and
                # is well-suited for initial sampling of the search space)
                GenerationStep(
                    model = Models.SOBOL,
                    num_trials = 5, # how many trials should be produced from this generation step
                    min_trials_observed = 5, # how many trials need to be completed to move to next model
                    max_parallelism = 5, # max parallelism for this step
                    model_kwargs = {"seed": rs}, # kwargs for the model
                    model_gen_kwargs = {}, # kwargs for modelbridg.gen
                ),
                # 2. Bayesian optimzation step (requires data obtained from previous
                # phase and learns from all data available at the time of each new
                # candidate generation call)
                GenerationStep(
                    model = Models.MOO,
                    num_trials = -1, # no limit on how many trials should be produced from this step
                    max_parallelism = 3, # parallelism for this step, often lower than Sobol
                ),
                ]
            )
        ax_client = AxClient(random_seed=42, generation_strategy=gs)
        ax_client.create_experiment(
            name = "dnn_fpga_exp"+str(n),
            parameters = [
                {
                    "name": "H",
                    "type": "range",
                    "bounds": [3, 8],
                    "value_type": "int",
                },
                {
                    "name": "L",
                    "type": "range",
                    "bounds": [2, 5],
                    "value_type": "int",
                },
                {
                    "name": "fxp_word_length",
                    "type": "range",
                    "bounds": [10, 20],
                    "value_type": "int",
                },
                {
                    "name": "loopOpt",
                    "type": "choice",
                    "values": ["LoopNone", "StreamLoops", "UnrollLoops"],
                    "value_type": "str",
                },
            ],
            objectives = {
                "obj1": ObjectiveProperties(minimize=True, threshold=100.0),
                "obj2": ObjectiveProperties(minimize=True, threshold=80.0)
            },
            overwrite_existing_experiment=True,
            is_test=False,
        )

        # initialize MOBO with parameter guess
        initial_parameters = {
            "H": 5,
            "L": 3,
            "fxp_word_length": 18,
            "loopOpt": "LoopNone",
        }
        ax_client.attach_trial(parameters=initial_parameters)
        eng.remove_codegen_project(nargout=0)
        raw_data = evaluate(initial_parameters, save_prefix=f'experiments/{date}/trial{n}_exp0')
        ax_client.complete_trial(trial_index=0, raw_data=raw_data)
        ax_client.save_to_json_file(f"experiments/{date}/ax_client_snapshot{n}.json")

        # save data
        mobo_save_filepath = f"experiments/{date}/experiment{str(n)}.json"
        for i in range(n_BO):
            save_experiment(ax_client.experiment, mobo_save_filepath)
            parameters, trial_index = ax_client.get_next_trial()
            eng.remove_codegen_project(nargout=0)
            raw_data = evaluate(parameters, rand_seed2=i, save_prefix=f'experiments/{date}/trial{n}_exp{i+1}')
            if abs(raw_data["obj1"][0] - 1000.0) <= 1e-6:
                ax_client.log_trial_failure(trial_index=trial_index)
            else:
                ax_client.complete_trial(trial_index=trial_index, raw_data=raw_data)
            ax_client.save_to_json_file(f"experiments/{date}/ax_client_snapshot{n}.json")

        # restart matlab engine
        eng.quit()
        eng = matlab.start_matlab()
        out = ax_client.get_pareto_optimal_parameters()
        if out is not None:
            print(out)
