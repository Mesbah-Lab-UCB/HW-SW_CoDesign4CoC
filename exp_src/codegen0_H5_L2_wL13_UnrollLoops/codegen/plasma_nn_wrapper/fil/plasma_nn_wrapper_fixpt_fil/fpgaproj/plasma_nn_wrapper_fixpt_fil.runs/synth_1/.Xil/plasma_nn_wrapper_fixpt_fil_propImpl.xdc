set_property SRC_FILE_INFO {cfile:/home/kimberlychan/Desktop/DNN_Generality/matlab/codegen0_H5_L2_wL13_UnrollLoops/codegen/plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil/fpgaproj/plasma_nn_wrapper_fixpt_fil.srcs/sources_1/ip/clk_wiz_0/clk_wiz_0/clk_wiz_0_in_context.xdc rfile:../../../plasma_nn_wrapper_fixpt_fil.srcs/sources_1/ip/clk_wiz_0/clk_wiz_0/clk_wiz_0_in_context.xdc id:1 order:EARLY scoped_inst:u_clk_wiz_0} [current_design]
set_property SRC_FILE_INFO {cfile:/home/kimberlychan/Desktop/DNN_Generality/matlab/codegen0_H5_L2_wL13_UnrollLoops/codegen/plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil/filsrc/plasma_nn_wrapper_fixpt_fil.xdc rfile:../../../../filsrc/plasma_nn_wrapper_fixpt_fil.xdc id:2} [current_design]
current_instance u_clk_wiz_0
set_property src_info {type:SCOPED_XDC file:1 line:1 export:INPUT save:INPUT read:READ} [current_design]
create_clock -period 8.000 [get_ports -no_traverse {}]
set_property src_info {type:SCOPED_XDC file:1 line:4 export:INPUT save:INPUT read:READ} [current_design]
create_generated_clock -source [get_ports clk_in1] -edges {1 2 3} -edge_shift {0.000 16.000 32.000} [get_ports {}]
current_instance
set_property src_info {type:XDC file:2 line:2 export:INPUT save:INPUT read:READ} [current_design]
set_property PACKAGE_PIN K17 [get_ports sysclk]
set_property src_info {type:XDC file:2 line:5 export:INPUT save:INPUT read:READ} [current_design]
set_false_path -from [get_clocks clk_out1_clk_wiz_0] -to [get_clocks TCK]
set_property src_info {type:XDC file:2 line:6 export:INPUT save:INPUT read:READ} [current_design]
set_false_path -from [get_clocks TCK] -to [get_clocks clk_out1_clk_wiz_0]
