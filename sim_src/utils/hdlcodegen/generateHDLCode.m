function [fxpCfg, hdlcfg] = generateHDLCode(params, codegen_dir)
% function to generate HDL code for the DNN

warning('off')
if isempty(params)
    target_freq_mhz = 25;
    fxp_word_length = 18;
    loopOpt = 'LoopNone';
else
    target_freq_mhz = 25;
    fxp_word_length = params.fxp_word_length;
    loopOpt = char(params.loopOpt);
end

%% configuration settings for fixed point code conversion
fxpCfg = coder.config('fixpt');
fxpCfg.TestBenchName = 'test_fullDNN';
fxpCfg.TestNumerics = true;

% assume scaled inputs
fxpCfg.addDesignRangeSpecification('plasma_nn_wrapper', 'x1_1', -1.0, 1.0)
fxpCfg.addDesignRangeSpecification('plasma_nn_wrapper', 'x1_2', -1.0, 1.0)
fxpCfg.addDesignRangeSpecification('plasma_nn_wrapper', 'x1_3', -1.0, 1.0)
fxpCfg.addDesignRangeSpecification('plasma_nn_wrapper', 'y1_1', -1.0, 1.0)
fxpCfg.addDesignRangeSpecification('plasma_nn_wrapper', 'y1_2', -1.0, 1.0)
% fxpCfg.ComputeDerivedRanges = true;

fxpCfg.DefaultWordLength = fxp_word_length;
fxpCfg.ProposeFractionLengthsForDefaultWordLength = true;
% % or
% fxpCfg.DefaultFractionLength = 10;
% fxpCfg.ProposeWordLengthsForDefaultFractionLength = true;

fxpCfg.SafetyMargin = 10; % default is 0

%% HDL config object
hdlcfg = coder.config('hdl');

hdlcfg.TargetLanguage = 'Verilog';
hdlcfg.TargetFrequency = target_freq_mhz;

hdlcfg.DesignFunctionName = 'plasma_nn_wrapper';
hdlcfg.TestBenchName = 'test_fullDNN';
% hdlcfg.GenerateHDLTestBench = true;
% hdlcfg.SimulateGeneratedCode = true;

% optimizations
hdlcfg.UseMatrixTypesInHDL = true;
hdlcfg.ConstantMultiplierOptimization = 'auto';
hdlcfg.DistributedPipelining = false;
hdlcfg.DistributedPipeliningPriority = 'NumericalIntegrity'; % options include {'NumericalIntegrity', 'Performance'}
% hdlcfg.PipelineVariables = 'x1_1, x1_2, x1_3, y1_1, y1_2';
% hdlcfg.InputPipeline = 2;
% hdlcfg.OutputPipeline = 2;
hdlcfg.RegisterInputs = false;
hdlcfg.RegisterOutputs = false;
hdlcfg.PreserveDesignDelays = true;
hdlcfg.ShareAdders = true;
hdlcfg.ShareMultipliers = true;

hdlcfg.LoopOptimization = loopOpt; % options include {'LoopNone', 'StreamLoops', 'UnrollLoops'}

% FGPA-in-the-loop verification
hdlcfg.GenerateFILTestBench = true;
if hdlcfg.GenerateFILTestBench
    hdlcfg.SimulateFILTestBench = true;
    hdlcfg.FILBoardName = 'Zybo Zynq-7000 - Copy';
    hdlcfg.FILBoardIPAddress = '192.168.1.101';
    hdlcfg.FILBoardMACAddress = '00-18-3e-03-3a-2f';
end

% synthesize code to program board
hdlcfg.SynthesizeGeneratedCode = false;
if hdlcfg.SynthesizeGeneratedCode
    hdlcfg.SynthesisTool = 'Xilinx Vivado';
    hdlcfg.SynthesisToolChipFamily = 'Zynq';
    hdlcfg.SynthesisToolDeviceName = 'xc7z020';
    hdlcfg.SynthesisToolPackageName = 'clg400';
    hdlcfg.SynthesisToolSpeedValue = '-1';
end

codegen('-float2fixed', fxpCfg, '-config', hdlcfg, 'plasma_nn_wrapper', '-d', codegen_dir)
warning('on')

end
