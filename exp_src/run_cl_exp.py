# this file runs the experiments for the APPJ testbed in the following paper:
#
#
# Requirements:
# * Python 3
# * several 3rd party packages including CasADi, NumPy, Scikit-Optimize for
# the implemented algorithms and Seabreeze, os, serial, etc. for connection to
# the experimental setup.
#
# Copyright (c) 2021 Mesbah Lab. All Rights Reserved.
# Contributor(s): Kimberly Chan
# Affiliation: University of California, Berkeley
#
# This file is under the MIT License. A copy of this license is included in the
# download of the entire code package (within the root folder of the package).

## import 3rd party packages
import sys
sys.dont_write_bytecode = True
import numpy as np
from seabreeze.spectrometers import Spectrometer, list_devices
import time
import os
import serial
import cv2
from datetime import datetime
import asyncio
# pickle import to save class data
try:
    import cPickle as pickle
except ModuleNotFoundError:
    import pickle
from scipy.io import loadmat

## import user functions
import utils.APPJPythonFunctions as appj
import matlab.engine
from utils.experiments import Experiment

eng = matlab.engine.start_matlab() # start matlab engine

model_path = '../Model_ID/APPJmodel_2022_07_22_11h40m51s.mat'
model = loadmat(model_path)
use_gp = False
dataInfo = model['dataInfo'].item()
I_NORMALIZATION = 1/float(dataInfo[4])
print(I_NORMALIZATION)
collect_open_loop_data = False
use_hw = False
use_dnn = False
casadi_matlab_path = '~/casadi-linux-matlab-v3.5.5'
dnn_trn_save_file = './saved/dnn_trn_data_exp_data.mat'
Nrep = 5 # number of repetition of closed-loop runs

################################################################################
## Startup/prepare APPJ
################################################################################
if use_hw:
    ## designate parameters used in the experiment

    # control performance preferred
    codegen_dir = "/home/kimberlychan/Desktop/DNN_Generality/matlab/codegen0_H5_L2_wL13_UnrollLoops"
    params = {}
    params["loopOpt"] = "UnrollLoops"
    params["fxp_word_length"] = 13

    # constraint satisfaction preferred
    # codegen_dir = "/home/kimberlychan/Desktop/DNN_Generality/matlab/codegen0_H8_L2_wL18_LoopNone"
    # params = {}
    # params["loopOpt"] = "LoopNone"
    # params["fxp_word_length"] = 18

    # utopia
    # codegen_dir = "/home/kimberlychan/Desktop/DNN_Generality/matlab/codegen0_H5_L3_wL20_LoopNone"
    # params = {}
    # params["loopOpt"] = "LoopNone"
    # params["fxp_word_length"] = 20

    c = eng.initialize_fpga_ctrl(dnn_trn_save_file,params,codegen_dir,nargout=1)
elif use_dnn:
    params = {}
    params["H"] = 6
    params["L"] = 4
    c = eng.initialize_dnn(casadi_matlab_path, dnn_trn_save_file, params)
else:
    c = eng.initialize_msmpc(casadi_matlab_path, use_gp, model_path)

## collect time stamp
timeStamp = datetime.now().strftime('%Y_%m_%d_%H'+'h%M''m%S'+'s')
print('Timestamp for save files: ', timeStamp)

# configure run options
runOpts = appj.RunOpts()
runOpts.collectData = True
runOpts.collectEntireSpectra = False
runOpts.collectOscMeas = False
runOpts.collectSpatialTemp = False
runOpts.saveSpectra = False
runOpts.saveOscMeas = False
runOpts.saveSpatialTemp = False
runOpts.tSampling = 0.5

Nsim = int(2*60/runOpts.tSampling)
ts = runOpts.tSampling

## Set startup values
dutyCycleIn = 100
powerIn = 2.0
flowIn = 3.0

Ts0_des = 37.0 # desired initial surface temperature
coolDownDiff = 1 # degrees to substract from desired surface temperature for cooldown
warmUpDiff = 1 # degrees to subtract from desired surface temperature for initialization of experiment

# set save location
directory = os.getcwd()
# os.makedirs(directory+"/ExperimentalData/"+timeStamp, exist_ok=True)
saveDir = directory+"/ExperimentalData/"+timeStamp+"/"
print('\nData will be saved in the following directory:')
print(saveDir)

## connect to/open connection to devices in setup
# Arduino
arduinoAddress = appj.getArduinoAddress(os="ubuntu")
print("Arduino Address: ", arduinoAddress)
arduinoPI = serial.Serial(arduinoAddress, baudrate=38400, timeout=1)
s = time.time()
# Oscilloscope
oscilloscope = appj.Oscilloscope()       # Instantiate object from class
instr = oscilloscope.initialize()	# Initialize oscilloscope
# Spectrometer
devices = list_devices()
print(devices)
spec = Spectrometer(devices[0])
spec.integration_time_micros(12000*6)
# Thermal Camera
dev, ctx = appj.openThermalCamera()
print("Devices opened/connected to sucessfully!")

devices = {}
devices['arduinoPI'] = arduinoPI
devices['arduinoAddress'] = arduinoAddress
devices['instr'] = instr
devices['spec'] = spec

# send startup inputs
time.sleep(2)
appj.sendInputsArduino(arduinoPI, powerIn, flowIn, dutyCycleIn, arduinoAddress)
input("Ensure plasma has ignited and press Return to begin.\n")

## Startup asynchronous measurement
if os.name == 'nt':
    ioloop = asyncio.ProactorEventLoop() # for subprocess' pipes on Windows
    asyncio.set_event_loop(ioloop)
else:
    ioloop = asyncio.get_event_loop()
# run once to initialize measurements
prevTime = (time.time()-s)*1e3
tasks, runTime = ioloop.run_until_complete(appj.async_measure(arduinoPI, prevTime, instr, spec, runOpts))
print('measurement devices ready!')
s = time.time()

# let APPJ run for a bit
powerIn = 1.5
flowIn = 1.5
appj.sendInputsArduino(arduinoPI, powerIn, flowIn, dutyCycleIn, arduinoAddress)
time.sleep(0.5)

w8 = input("Wait 5 min? [y,n]\n")
if w8 == 'y':
    print("Waiting 5 minutes to ensure roughly steady plasma startup...\n")
    time.sleep(60)
    print("4 minutes left...")
    time.sleep(60)
    print("3 minutes left...")
    time.sleep(60)
    print("2 minutes left...")
    time.sleep(60)
    print("1 minute left...")
    time.sleep(60)
else:
    time.sleep(5)

# wait for cooldown
appj.sendInputsArduino(arduinoPI, 0.0, 0.0, dutyCycleIn, arduinoAddress)
arduinoPI.close()
while appj.getSurfaceTemperature() > Ts0_des-coolDownDiff:
    time.sleep(runOpts.tSampling)
    print('cooling down ...')
arduinoPI = serial.Serial(arduinoAddress, baudrate=38400, timeout=1)
time.sleep(2)
appj.sendInputsArduino(arduinoPI, powerIn, flowIn, dutyCycleIn, arduinoAddress)
# wait for surface to reach desired starting temp
while appj.getSurfaceTemperature() < Ts0_des-warmUpDiff:
    time.sleep(runOpts.tSampling)
    print('warming up ...')

prevTime = (time.time()-s)*1e3
# get initial measurements
tasks, runTime = ioloop.run_until_complete(appj.async_measure(arduinoPI, prevTime, instr, spec, runOpts))
if runOpts.collectData:
    thermalCamOut = tasks[0].result()
    Ts0 = thermalCamOut[0]
    specOut = tasks[1].result()
    I0 = specOut[0]*I_NORMALIZATION
    oscOut = tasks[2].result()
    arduinoOut = tasks[3].result()
    outString = "Measured Outputs: Temperature: %.2f, Intensity: %.2f" % (Ts0, I0)
    print(outString)
else:
    Ts0 = 37
    I0 = 100

s = time.time()

arduinoPI.close()

################################################################################
## Begin Experiment: Experiment with generated hardware code
################################################################################
exp = Experiment(Nsim, saveDir)

if Nrep>1 and not use_hw:
    rng = np.random.default_rng(0)
    Ts0_vec = rng.uniform(36.0,40.0,size=(Nrep,))
for i in range(Nrep):
    # connect to Arduino
    arduinoPI = serial.Serial(arduinoAddress, baudrate=38400, timeout=1)
    s = time.time()
    print('Pausing for cooldown...')
    time.sleep(2)
    if Nrep>1 and not use_hw:
        Ts0_des = Ts0_vec[i]
        print(f'Desired Starting Temperature: {Ts0_des}\n')
    while appj.getSurfaceTemperature() > Ts0_des-coolDownDiff:
        time.sleep(runOpts.tSampling)
    appj.sendInputsArduino(arduinoPI, powerIn, flowIn, dutyCycleIn, arduinoAddress)
    devices['arduinoPI'] = arduinoPI

    if collect_open_loop_data:
        # create input sequences
        uvec = np.linspace(1.5,5.5,5)
        uu1,uu2 = np.meshgrid(uvec,uvec)
        uvec = uu1.reshape(-1,)
        rng = np.random.default_rng(0)
        rng.shuffle(uvec)
        pseq = np.copy(uvec)
        pseq = np.insert(pseq,0,[0.0,3.5,3.5,3.5])
        rng.shuffle(uvec)
        qseq = np.copy(uvec)
        qseq = np.insert(qseq,0,[0.0,3.5,3.5,3.5])
        print(pseq)
        print(qseq)

        pseq = np.repeat(pseq, 30/runOpts.tSampling).reshape(-1,)
        qseq = np.repeat(qseq, 30/runOpts.tSampling).reshape(-1,)
        print(pseq.shape[0])

        exp_data = exp.run_open_loop(ioloop,
                                     power_seq=pseq,
                                     flow_seq=qseq,
                                     runOpts=runOpts,
                                     devices=devices,
                                     prevTime=prevTime)
    else:
        # create prob_info (make sure these are the same as in the appropriate load_prob_info function)
        prob_info = {}
        prob_info['nu'] = 2
        prob_info['nx'] = 2
        prob_info['ny'] = 2
        prob_info['nyc'] = 1
        prob_info['xss'] = model['yss']
        prob_info['uss'] = model['uss']
        prob_info['u_max'] = [5.5, 5.5]
        prob_info['u_min'] = [1.5, 1.5]

        prob_info['x0'] = np.array([Ts0,I0])-model['yss']# initial state/point
        prob_info['y0'] = prob_info['x0'] # initial outputs/measurements
        prob_info['u0'] = np.array([powerIn,flowIn])-model['uss'] # startup inputs
        prob_info['myref'] = lambda t: 1.5 # reference function for the controlled output
        prob_info['ts'] = runOpts.tSampling # experiment sampling time
        exp.load_prob_info(prob_info)

        prevTime = (time.time()-s)*1e3

        exp_data = exp.run_closed_loop_mpc(c, ioloop,
                                           runOpts=runOpts,
                                           devices=devices,
                                           prevTime=prevTime,
                                           matlab_eng=eng,
                                           CEM=True,
                                           hw_flag=use_hw,
                                           dnn_flag=use_dnn,
                                           I_NORM=I_NORMALIZATION)


    arduinoPI.close()

# reconnect Arduino
arduinoPI = serial.Serial(arduinoAddress, baudrate=38400, timeout=1)
devices['arduinoPI'] = arduinoPI

# turn off plasma jet (programmatically)
appj.sendInputsArduino(arduinoPI, 0.0, 0.0, dutyCycleIn, arduinoAddress)
arduinoPI.close()
print("Experiments complete!\n"+
    "################################################################################################################\n"+
    "IF FINISHED WITH EXPERIMENTS, PLEASE FOLLOW THE SHUT-OFF PROCEDURE FOR THE APPJ\n"+
    "################################################################################################################\n")
