# script to run MOBO using Ax
#
# Requirements:
# * Python 3.8.10
# * Ax 0.2.3
#
# Copyright (c) 2024 Mesbah Lab. All Rights Reserved.
# Contributor(s): Kimberly J. Chan
# Affiliation: University of California, Berkeley
#
# This file is under the MIT License. A copy of this license is included in the
# download of the entire code package (within the root folder of the package).

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

tkwargs = {
    "dtype": torch.double,
    "device": torch.device("cuda" if torch.cuda.is_available() else "cpu"),
}
SMOKE_TEST = os.environ.get("SMOKE_TEST")

####################################################################
# helper function to convert MATLAB data to torch Tensors
####################################################################
def convert_data(data):
    obj = torch.tensor(data[0], **tkwargs)
    obj_true = torch.tensor(data[1], **tkwargs)
    return obj, obj_true

####################################################################
# main script to run MOBO
####################################################################
if __name__ == '__main__':
    from ax.storage.json_store.save import save_experiment

    # generate training data if not exists
    n_trn = int(2e3)
    n_exps = 4
    n_BO = 50
    dnn_trn_save_file = './saved/dnn_trn_data_2000samp.mat' # file where training data for a DNN is saved
    hw_classifier_filename = './saved/workspace_HW_classifier_2023_09_14_noBO.mat' # file where the hardware classifier object is saved
    random_sampling = False # switch to perform random sampling or MOBO
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
            print(dnn_trn_save_file) # dnn_obj is not used
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
        _, objs, objs_true = eng.approx_msMPC_HIL(parameters,
                dnn_trn_save_file,
                'skip_mpc_test', False,
                'skip_dnn_test', False,
                'hw_obj', False,
                'use_perf_obj', True,
                'train_dnn', True,
                'rand_seed2', rand_seed2,
                'save_prefix', save_prefix,
                'plot_intermediate', True,
                nargout=3)
        objs, objs_true = convert_data([objs, objs_true])
        obj1 = objs[0]
        obj2 = objs[1]

        # set standard error to be estimated
        return {"obj1": (obj1.item(), None), "obj2": (obj2.item(), None)}

    ####################################################################
    # evaluation function to compute constraint
    ####################################################################
    def evaluate_constraint(parameters):
        feas = eng.hw_constraint4python(parameters, 
                                        hw_classifier_filename,
                                        nargout=1)
        return bool(feas)
    ####################################################################
    # run multiple trials of BO to account for stochasticity
    ####################################################################
    for n in range(n_exps):
        # setup experiments for MOBO
        # set random seed for repeatable experiments
        rs = int(42*(n+1236))
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
                    num_trials = 1, # how many trials should be produced from this generation step
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
        # create an AxClient object that manages the iterative optimization based on the generation strategy specfied above
        ax_client = AxClient(random_seed=rs, generation_strategy=gs)
        # create the experiment within the AxClient that specifies the parameters (and their bounds to define the search space) and objectives
        ax_client.create_experiment(
            name = "dnn_fpga_exp"+str(n),
            parameters = [
                {
                    "name": "w1bound",
                    "type": "range",
                    "bounds": [0.0, 10.0],
                    "value_type": "float",
                },
                {
                    "name": "H",
                    "type": "range",
                    "bounds": [3, 8],
                    "value_type": "int",
                },
                {
                    "name": "fxp_word_length",
                    "type": "range",
                    "bounds": [10, 20],
                    "value_type": "int",
                },
            ],
            objectives = {
                "obj1": ObjectiveProperties(minimize=True, threshold=100.0),
                "obj2": ObjectiveProperties(minimize=True, threshold=80.0)
            }, # objectives can have thresholds, which are like soft constraints to guide the search to a desired region
            overwrite_existing_experiment=True,
            is_test=False,
        )

        # initialize MOBO with parameter guess
        initial_parameters = {
            "w1bound": 0.5,
            "H": 5,
            "fxp_word_length": 18,
        }
        ax_client.attach_trial(parameters=initial_parameters)
        eng.remove_codegen_project(nargout=0) # remove any existing codegen so as to not interfere with new codegen
        raw_data = evaluate(initial_parameters, save_prefix=f'experiments/{date}/trial{n}_exp0')
        ax_client.complete_trial(trial_index=0, raw_data=raw_data)
        ax_client.save_to_json_file(f"experiments/{date}/ax_client_snapshot{n}.json")

        # save data
        mobo_save_filepath = f"experiments/{date}/experiment{str(n)}.json"
        for i in range(n_BO):
            save_experiment(ax_client.experiment, mobo_save_filepath)
            parameters, trial_index = ax_client.get_next_trial()

            feas = evaluate_constraint(parameters)
            if feas:
                eng.remove_codegen_project(nargout=0)
                raw_data = evaluate(parameters, rand_seed2=i, save_prefix=f'experiments/{date}/trial{n}_exp{i+1}')
                if abs(raw_data["obj1"][0] - 1000.0) <= 1e-6:
                    ax_client.abandon_trial(trial_index=trial_index)
                    # trial is abandoned and parameters from that trial are not used again if the first objective is too high
                else:
                    ax_client.complete_trial(trial_index=trial_index, raw_data=raw_data)
            else:
                ax_client.abandon_trial(trial_index=trial_index)
                # trial is abandoned and parameters from that trial are not used again if it is infeasible to implement on hardware
            ax_client.save_to_json_file(f"experiments/{date}/ax_client_snapshot{n}.json")

        # restart matlab engine
        eng.quit()
        eng = matlab.start_matlab()
        out = ax_client.get_pareto_optimal_parameters()
        if out is not None:
            print(out)
