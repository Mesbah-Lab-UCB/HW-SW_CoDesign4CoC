function [y1_1,y1_2] = plasma_nn_wrapper(x1_1, x1_2, x1_3)
x1 = [x1_1; x1_2; x1_3];
y1 = plasma_nn(x1);
y1_1 = y1(1);
y1_2 = y1(2);
end