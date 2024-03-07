% hdlcoder script

% specify a required time (ns) and slack (ns) for timing report
required_time = 40;
slack = 0;
% slack is difference between required_time and arrival_time; by adding
% slack to required_time, you can resolve
new_req_time = required_time + slack;
target_freq = 1 / new_req_time;
% convert to MHz
target_freq_mhz = target_freq * 10^3;

%% fixed point converter config
fxpCfg = coder.config('fixpt');
fxpCfg.TestBenchName = 'test_fullDNN';
fxpCfg.TestNumerics = true;

fxpCfg.addDesignRangeSpecification('plasma_nn_wrapper', 'x1_1', -1.0, 1.0)
fxpCfg.addDesignRangeSpecification('plasma_nn_wrapper', 'x1_2', -1.0, 1.0)
fxpCfg.addDesignRangeSpecification('plasma_nn_wrapper', 'x1_3', -1.0, 1.0)
% fxpCfg.ComputeDerivedRanges = true;

fxpCfg.DefaultWordLength = 18;
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
hdlcfg.DistributedPipelining = true;
hdlcfg.DistributedPipeliningPriority = 'NumericalIntegrity'; % options include {'NumericalIntegrity', 'Performance'}
% hdlcfg.PipelineVariables = 'x1_1, x1_2, x1_3, y1_1, y1_2';
hdlcfg.InputPipeline = 3;
hdlcfg.OutputPipeline = 2;
hdlcfg.RegisterInputs = true;
hdlcfg.RegisterOutputs = true;
hdlcfg.PreserveDesignDelays = true;
hdlcfg.ShareAdders = true;
hdlcfg.ShareMultipliers = true;

hdlcfg.LoopOptimization = 'UnrollLoops'; % options include {'LoopNone', 'StreamLoops', 'UnrollLoops'}

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
hdlcfg.SynthesisTool = 'Xilinx Vivado';
hdlcfg.SynthesisToolChipFamily = 'Zynq';
hdlcfg.SynthesisToolDeviceName = 'xc7z020';
hdlcfg.SynthesisToolPackageName = 'clg400';
hdlcfg.SynthesisToolSpeedValue = '-1';

% codegen('-config',hdlcfg)

codegen('-float2fixed', fxpCfg, '-config', hdlcfg, 'plasma_nn_wrapper')



