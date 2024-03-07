set SRCDIR /home/kimberlychan/Desktop/DNN_Generality/matlab/codegen0_H5_L3_wL20_LoopNone/codegen/plasma_nn_wrapper/fil/home/kimberlychan/Desktop/DNN_Generality/matlab/codegen0_H5_L3_wL20_LoopNone/codegen/plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil/filsrc
set SIMDIR /home/kimberlychan/Desktop/DNN_Generality/matlab/codegen0_H5_L3_wL20_LoopNone/codegen/plasma_nn_wrapper/fil/home/kimberlychan/Desktop/DNN_Generality/matlab/codegen0_H5_L3_wL20_LoopNone/codegen/plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil/filsrc/sim
set COMPILE vcom

set SIM vsim

vlib $SIMDIR/work
vmap work $SIMDIR/work

$COMPILE $SRCDIR/jtag_mac.v
$COMPILE $SRCDIR/jtag_mac_fifo_wrapper.vhd
$COMPILE $SRCDIR/simcycle_fifo_wrapper.vhd
$COMPILE $SRCDIR/mwfil_dpscram.vhd
$COMPILE $SRCDIR/mwfil_udfifo.vhd
$COMPILE $SRCDIR/mwfil_bus2dut.vhd
$COMPILE $SRCDIR/mwfil_chifcore.vhd
$COMPILE $SRCDIR/mwfil_controller.vhd
$COMPILE $SRCDIR/mwfil_dut2bus.vhd
$COMPILE $SRCDIR/plasma_nn_wrapper_fixpt_wrapper.v
$COMPILE $SRCDIR/mwfil_chiftop.vhd
$COMPILE $SRCDIR/plasma_nn_wrapper_fixpt_fil.vhd
