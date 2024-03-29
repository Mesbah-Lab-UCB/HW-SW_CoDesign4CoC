#!/bin/sh

# 
# Vivado(TM)
# runme.sh: a Vivado-generated Runs Script for UNIX
# Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
# 

if [ -z "$PATH" ]; then
  PATH=/home/Xilinx/Vivado/2020.1/ids_lite/ISE/bin/lin64:/home/Xilinx/Vivado/2020.1/bin
else
  PATH=/home/Xilinx/Vivado/2020.1/ids_lite/ISE/bin/lin64:/home/Xilinx/Vivado/2020.1/bin:$PATH
fi
export PATH

if [ -z "$LD_LIBRARY_PATH" ]; then
  LD_LIBRARY_PATH=
else
  LD_LIBRARY_PATH=:$LD_LIBRARY_PATH
fi
export LD_LIBRARY_PATH

HD_PWD='/home/kimberlychan/Desktop/DNN_Generality/matlab_v3/hdlcoder_fullDNN/codegen/plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil/fpgaproj/plasma_nn_wrapper_fixpt_fil.runs/jtag_mac_fifo_synth_1'
cd "$HD_PWD"

HD_LOG=runme.log
/bin/touch $HD_LOG

ISEStep="./ISEWrap.sh"
EAStep()
{
     $ISEStep $HD_LOG "$@" >> $HD_LOG 2>&1
     if [ $? -ne 0 ]
     then
         exit
     fi
}

EAStep vivado -log jtag_mac_fifo.vds -m64 -product Vivado -mode batch -messageDb vivado.pb -notrace -source jtag_mac_fifo.tcl
