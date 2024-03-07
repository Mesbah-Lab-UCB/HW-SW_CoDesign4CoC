classdef (StrictDefaults)class_plasma_nn_wrapper_fixpt_sysobj <  hdlverifier.FILSimulation
%class_plasma_nn_wrapper_fixpt_sysobj is a filWizard generated class used for FPGA-In-the-Loop
%   simulation with the 'plasma_nn_wrapper_fixpt' DUT.
%   class_plasma_nn_wrapper_fixpt_sysobj connects MATLAB with a FPGA and cosimulate with it by 
%   writing inputs in the FPGA and reading outputs from the FPGA.
%
%   MYFIL = class_plasma_nn_wrapper_fixpt_sysobj
%
%   Step method syntax:
%
%   [out1, out2, ...] = step(MYFIL, in1, in2, ...) connect to the FPGA,
%   write in1, in2, ... to the FPGA and read out1, out2, ... from 
%   the FPGA
%
%   class_plasma_nn_wrapper_fixpt_sysobj methods:
%
%   step        - See above description for use of this method
%   release     - Allow property value and input characteristics changes, and
%                 release connection to FPGA board
%   clone       - Create class_plasma_nn_wrapper_fixpt_sysobj object with same property values
%   isLocked    - Locked status (logical)
%   programFPGA - Load the programming file in the FPGA
%
%   class_plasma_nn_wrapper_fixpt_sysobj properties:
%
%   DUTName                  - DUT top level name
%   InputSignals             - Input paths in the HDL code
%   InputBitWidths           - Width in bit of the inputs
%   OutputSignals            - Output paths in the HDL code
%   OutputBitWidths          - Width in bit of the outputs
%   OutputDataTypes          - Data type of the outputs
%   OutputSigned             - Sign of the outputs
%   OutputFractionLengths    - Fraction lengths of the outputs
%   OutputDownsampling       - Downsampling factor and phase of the outputs
%   OverclockingFactor       - Overclocking factor of the hardware
%   Connection               - Parameters for the connection with the board
%   FPGAVendor               - Name of the FPGA chip vendor
%   FPGABoard                - Name of the FPGA board
%   FPGAProgrammingFile      - Path of the Programming file for the FPGA
%   ScanChainPosition        - Position of the FPGA in the JTAG scan chain
%
%   File Name: class_plasma_nn_wrapper_fixpt_sysobj.m
%   Created: 22-Jul-2022 12:40:39
% 
%   Generated by FIL Wizard

%#codegen

    properties (Nontunable)
        DUTName = 'plasma_nn_wrapper_fixpt';
    end
    
    methods
        function obj = class_plasma_nn_wrapper_fixpt_sysobj
            
            %THE FOLLOWING PROTECTED PROPERTIES ARE SPECIFIC TO THE HW DUT
            %AND MUST NOT BE EDITED (RERUN THE FIL WIZARD TO CHANGE THEM)
            obj.InputSignals = char('x1_1','x1_2','x1_3');
            obj.InputBitWidths = [13,13,3];
            obj.OutputSignals = char('y1_1','y1_2');
            obj.OutputBitWidths = [13,13];
            obj.Connection = char('JTAG','libmwrtiostream_xjtag','FPGAInstr=000010;FPGAInstr2=000011;FPGAInstr3=100010;FPGAInstr4=100011;InstrLenBefore=4;InstrLenAfter=0;TckFrequency=66.000000',''); 
            obj.FPGAVendor = 'Xilinx';
            obj.FPGATool   = 'Xilinx Vivado';
            obj.FPGABoard = 'Zybo Zynq-7000 - Copy';
            obj.ScanChainPosition = 2 ;
            
            %THE FOLLOWING PUBLIC PROPERTIES ARE RELATED TO THE SIMULATION
            %AND CAN BE EDITED WITHOUT RERUNING THE FIL WIZARD
            obj.OutputSigned = [true,true];
            obj.OutputDataTypes = char('fixedpoint','fixedpoint');
            obj.OutputFractionLengths = [11,11];
            obj.OutputDownsampling = [1,0];
            obj.OverclockingFactor = 1;
            obj.FPGAProgrammingFile = '/home/kimberlychan/Desktop/DNN_Generality/matlab/codegen0_H5_L2_wL13_UnrollLoops/codegen/plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil/plasma_nn_wrapper_fixpt_fil.bit';                       
        end
    end
end




