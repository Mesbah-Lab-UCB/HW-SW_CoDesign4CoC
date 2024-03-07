
-- ----------------------------------------------
-- File Name: mwfil_chiftop.vhd
-- Created:   22-Jul-2022 12:36:43
-- Copyright  2022 MathWorks, Inc.
-- ----------------------------------------------

LIBRARY IEEE;
USE IEEE.std_logic_1164.all;
USE IEEE.numeric_std.ALL;


ENTITY mwfil_chiftop IS 
PORT (
      clk                             : IN  std_logic;
      reset                           : IN  std_logic;
      din                             : IN  std_logic_vector(7 DOWNTO 0);
      din_valid                       : IN  std_logic;
      dout_ready                      : IN  std_logic;
      simcycle                        : IN  std_logic_vector(15 DOWNTO 0);
      din_ready                       : OUT std_logic;
      dout                            : OUT std_logic_vector(7 DOWNTO 0);
      dout_valid                      : OUT std_logic
);
END mwfil_chiftop;

ARCHITECTURE rtl of mwfil_chiftop IS

COMPONENT mwfil_chifcore IS 
GENERIC (INWORD: integer := 1;
OUTWORD: integer := 1;
WORDSIZE: integer := 64;
HASENABLE: integer := 1
);
PORT (
      clk                             : IN  std_logic;
      reset                           : IN  std_logic;
      din                             : IN  std_logic_vector(7 DOWNTO 0);
      din_valid                       : IN  std_logic;
      dout_ready                      : IN  std_logic;
      simcycle                        : IN  std_logic_vector(15 DOWNTO 0);
      dut_dout                        : IN  std_logic_vector(31 DOWNTO 0);
      din_ready                       : OUT std_logic;
      dout                            : OUT std_logic_vector(7 DOWNTO 0);
      dout_valid                      : OUT std_logic;
      dut_din                         : OUT std_logic_vector(39 DOWNTO 0);
      dut_enable                      : OUT std_logic
);
END COMPONENT;

COMPONENT plasma_nn_wrapper_fixpt_wrapper IS 
PORT (
      clk                             : IN  std_logic;
      enb                             : IN  std_logic;
      reset                           : IN  std_logic;
      din                             : IN  std_logic_vector(39 DOWNTO 0);
      dout                            : OUT std_logic_vector(31 DOWNTO 0)
);
END COMPONENT;

  SIGNAL dut_din                          : std_logic_vector(39 DOWNTO 0); -- std40
  SIGNAL dut_dout                         : std_logic_vector(31 DOWNTO 0); -- std32
  SIGNAL dut_clkenb                       : std_logic; -- boolean
  SIGNAL x1_1                             : std_logic_vector(12 DOWNTO 0); -- std13
  SIGNAL x1_1_tmp                         : std_logic_vector(12 DOWNTO 0); -- std13
  SIGNAL x1_2                             : std_logic_vector(12 DOWNTO 0); -- std13
  SIGNAL x1_2_tmp                         : std_logic_vector(12 DOWNTO 0); -- std13
  SIGNAL x1_3                             : std_logic_vector(2 DOWNTO 0); -- std3
  SIGNAL x1_3_tmp                         : std_logic_vector(2 DOWNTO 0); -- std3
  SIGNAL y1_1                             : std_logic_vector(12 DOWNTO 0); -- std13
  SIGNAL y1_1_tmp                         : std_logic_vector(12 DOWNTO 0); -- std13
  SIGNAL zero0                            : std_logic_vector(2 DOWNTO 0); -- std3
  SIGNAL y1_2                             : std_logic_vector(12 DOWNTO 0); -- std13
  SIGNAL y1_2_tmp                         : std_logic_vector(12 DOWNTO 0); -- std13
  SIGNAL zero1                            : std_logic_vector(2 DOWNTO 0); -- std3
  SIGNAL tmpconcat                        : std_logic_vector(31 DOWNTO 0); -- std32

BEGIN

u_mwfil_chifcore: mwfil_chifcore 
GENERIC MAP (INWORD => 5,
OUTWORD => 4,
WORDSIZE => 8,
HASENABLE => 0
)
PORT MAP(
        clk                  => clk,
        reset                => reset,
        din                  => din,
        din_valid            => din_valid,
        din_ready            => din_ready,
        dout                 => dout,
        dout_valid           => dout_valid,
        dout_ready           => dout_ready,
        simcycle             => simcycle,
        dut_din              => dut_din,
        dut_dout             => dut_dout,
        dut_enable           => dut_clkenb
);

u_dut: plasma_nn_wrapper_fixpt_wrapper 
PORT MAP(
        clk                  => clk,
        enb                  => dut_clkenb,
        reset                => reset,
        din                  => dut_din,
        dout                 => dut_dout
);


END;
