# HW-SW_CoDesign4CoC
**NOTE: This article is under review**
Contribution to IEEE Transactions on Control Systems Technology Issue xx, Volume xx:

*A Practical Multi-Objective Learning Framework for Optimal Hardware-Software Co-Design of Control-on-a-Chip Systems*

[DOI - to be added upon publication](https://www.mesbahlab.com/publications)

Authors: [Kimberly J. Chan](https://kchan45.github.io), [Joel A. Paulson](https://cbe.osu.edu/people/paulson.82), and [Ali Mesbah](https://chemistry.berkeley.edu/faculty/cbe/mesbah)

*NOTE: to be updated upon publication...*
If you use our work, please cite:
```tex
@article{chan2024practical,
  title={A Practical Multi-Objective Learning Framework for Optimal Hardware-Software Co-Design of Control-on-a-Chip Systems},
  author={Chan, Kimberly J and Paulson, Joel A and Mesbah, Ali},
}
```

## Implementation
Several components of this code was implemented using Python AND MATLAB. 

To run the Python code on your own device, it is recommended to work within a virtual environment. You may create your own virtual environment and then install the required Python packages by using the command
`pip3 install -r requirements_wo_appj_testbed.txt` (for simulations only) and `pip3 install -r requirements_w_appj_testbed.txt` (additional packages for experiments with the atmospheric pressure plasma jet (APPJ)). 

This code requires [MATLAB](https://www.mathworks.com/products/matlab.html), specifically [R2021a](https://www.mathworks.com/downloads/). Additionally, the following toolboxes were installed (not all may be necessary):
* Control System Toolbox
* Embedded Coder
* Deep Learning HDL Toolbox
* Deep Learning Toolbox
* Fixed-Point Designer
* Global Optimization Toolbox
* HDL Coder
* HDL Verifier
* MATLAB Coder
* Optimization Toolbox
* Statistics and Machine Learning Toolbox
Note, if the code implementation requires additional toolboxes, then the user should install those additional toolboxes.

For multi-objective optimization, MATLAB function(s) are called by a Python script. This can be set up using the instructions at this [link](https://www.mathworks.com/help/matlab/matlab_external/install-the-matlab-engine-for-python.html)

Finally, this code requires the installation and use of [Xilinx Vivado 2020.1](https://www.xilinx.com/products/design-tools/vivado.html) during the FPGA-in-the-loop simulations and experiments.

### Illustrative Example
The illustrative example can be implemented completely in MATLAB.

The main file to run comparisons for the illustrative example is `toy_problem/run_comparison.m`.

### Control-on-a-chip for Plasma Devices
The main file to run simulations with multi-objective Bayesian optimization for the artificial plasma control system is `sim_src/run_mobo_hw_ax.py`.

The main file to run experiments with the in-house Mesbah Lab APPJ testbed is `exp_src/run_exp.py`.

Additional details may be found within the `README`'s within the individual source code folders as well as in commentary within the files.



(c) 2024 [Mesbah Lab](https://www.mesbahlab.com)

in collaboration with Joel A. Paulson and Ali Mesbah.

Questions regarding this code may be directed to `kchan45 (at) berkeley.edu`
