
/*-- ----------------------------------------------
-- File Name: plasma_nn_wrapper_fixpt_wrapper.v
-- Created:   22-Jul-2022 12:44:47
-- Copyright  2022 MathWorks, Inc.
-- ----------------------------------------------*/

module plasma_nn_wrapper_fixpt_wrapper (
      clk,
      enb,
      reset,
      din,
      dout
);


      input     clk;
      input     enb;
      input     reset;
      input    [55 : 0] din;
      output   [47 : 0] dout;

  wire[17 : 0] x1_1; // std18
  wire[17 : 0] x1_1_tmp; // std18
  wire[17 : 0] x1_2; // std18
  wire[17 : 0] x1_2_tmp; // std18
  wire[2 : 0] x1_3; // std3
  wire[2 : 0] x1_3_tmp; // std3
  wire[17 : 0] y1_1; // std18
  wire[17 : 0] y1_1_tmp; // std18
  wire[5 : 0] zero0; // std6
  wire[17 : 0] y1_2; // std18
  wire[17 : 0] y1_2_tmp; // std18
  wire[5 : 0] zero1; // std6
  wire[47 : 0] tmpconcat; // std48
plasma_nn_wrapper_fixpt u_plasma_nn_wrapper_fixpt (
        .y1_1                 (y1_1),
        .y1_2                 (y1_2),
        .x1_1                 (x1_1),
        .x1_2                 (x1_2),
        .x1_3                 (x1_3)
);

assign x1_1 = x1_1_tmp;
assign x1_1_tmp = din[17 : 0];
assign x1_2 = x1_2_tmp;
assign x1_2_tmp = din[41 : 24];
assign x1_3 = x1_3_tmp;
assign x1_3_tmp = din[50 : 48];
assign y1_1_tmp = y1_1;
assign y1_1_tmp = y1_1;
assign zero0 = 6'b000000;
assign y1_2_tmp = y1_2;
assign y1_2_tmp = y1_2;
assign zero1 = 6'b000000;
assign dout = {zero1,y1_2_tmp,zero0,y1_1_tmp};

endmodule
