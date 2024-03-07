// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2020.1 (lin64) Build 2902540 Wed May 27 19:54:35 MDT 2020
// Date        : Sat Aug 27 06:52:58 2022
// Host        : kimberlychan-hpomen running 64-bit Ubuntu 20.04.4 LTS
// Command     : write_verilog -force -mode synth_stub
//               /home/kimberlychan/Desktop/DNN_Generality/matlab/hdlcoder_fullDNN/codegen/plasma_nn_wrapper/fil/plasma_nn_wrapper_fixpt_fil/fpgaproj/plasma_nn_wrapper_fixpt_fil.srcs/sources_1/ip/jtag_mac_fifo/jtag_mac_fifo_stub.v
// Design      : jtag_mac_fifo
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg400-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* x_core_info = "fifo_generator_v13_2_5,Vivado 2020.1" *)
module jtag_mac_fifo(rst, wr_clk, rd_clk, din, wr_en, rd_en, dout, full, 
  almost_full, empty, rd_data_count, wr_rst_busy, rd_rst_busy)
/* synthesis syn_black_box black_box_pad_pin="rst,wr_clk,rd_clk,din[7:0],wr_en,rd_en,dout[7:0],full,almost_full,empty,rd_data_count[11:0],wr_rst_busy,rd_rst_busy" */;
  input rst;
  input wr_clk;
  input rd_clk;
  input [7:0]din;
  input wr_en;
  input rd_en;
  output [7:0]dout;
  output full;
  output almost_full;
  output empty;
  output [11:0]rd_data_count;
  output wr_rst_busy;
  output rd_rst_busy;
endmodule
