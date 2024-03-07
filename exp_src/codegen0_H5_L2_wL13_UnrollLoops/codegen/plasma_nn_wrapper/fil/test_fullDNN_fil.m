% test script for the implementation of a full DNN FPGA implementation
clear plasma_nn_wrapper ;
filename = './saved/test_dnn.mat';
loaded_dnn = load( filename );
rmpath( loaded_dnn.casadipath )
disp( 'Number of test points:' )
N = 1;
disp( N )
% test_in = [43; 50; 0.8];
% test_in_s = scale_inputs(filename, test_in);
test_in_s = loaded_dnn.inputs( :, 1:N );
test_out_s = loaded_dnn.net( test_in_s );
test_out = unscale_outputs( filename, test_out_s );
test_out3 = zeros( size( test_out ) );
[r,c] = size( test_out );
for i = 1:c
    [test_out31,test_out32] = plasma_nn_wrapper_wrapper_fixpt_fil( test_in_s( 1, i ), test_in_s( 2, i ), test_in_s( 3, i ) );
    test_out3( :, i ) = unscale_outputs( filename, [ test_out31; test_out32 ] );
end
disp( 'Number of computations within tolerance:' )
disp( sum( all( abs( test_out - test_out3 )<=1e-2 ) ) )
disp( 'Max Error:' )
disp( max( max( abs( test_out - test_out3 ) ) ) )
addpath( loaded_dnn.casadipath )
