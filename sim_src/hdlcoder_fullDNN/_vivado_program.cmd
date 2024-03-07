set chain_position 1
open_hw
connect_hw_server -url localhost:3121
open_hw_target
current_hw_device [lindex [get_hw_devices] $chain_position]
refresh_hw_device -update_hw_probes false [lindex [get_hw_devices] $chain_position]
set_property PROGRAM.FILE {/home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil/plasma_nn_wrapper_fixpt_fil.bit} [lindex [get_hw_devices] $chain_position]
program_hw_devices [lindex [get_hw_devices] $chain_position]
disconnect_hw_server