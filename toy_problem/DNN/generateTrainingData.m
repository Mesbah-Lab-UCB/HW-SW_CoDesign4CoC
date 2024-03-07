function [data] = generateTrainingData(c, Nsim, prob_info, Nsamp)

nx = prob_info.nx;
nu = prob_info.nu;
f = prob_info.fp;

Ntraj = ceil(Nsamp/Nsim);
inputs = zeros(nx,Nsamp);
outputs = zeros(nu,Nsamp);

for n = 1:Ntraj
    Xsim = zeros(nx,Nsim+1);
    Usim = zeros(nu,Nsim);

    w = 2*rand(nx,Nsim)-1; 
    w(1:nx/2,:) = 0; 
    w = 0.5*w;

    Xsim(:,1) = prob_info.x0;
    for k = 1:Nsim

        Uopt = full(c(Xsim(:,k)));
        Usim(:,k) = Uopt;

        Xsim(:,k+1) = full(f(Xsim(:,k),Usim(:,k),w(:,k)));
    end
    start_idx = (n-1)*Nsim + 1;
    end_idx = n*Nsim;
    if end_idx > Nsamp
        ndiff = end_idx - Nsamp;
        end_idx = Nsamp;
        inputs(:,start_idx:end_idx) = Xsim(:,1:end-(ndiff+1));
        outputs(:,start_idx:end_idx) = Usim(:,1:end-ndiff);
    else
        inputs(:,start_idx:end_idx) = Xsim(:,1:end-1);
        outputs(:,start_idx:end_idx) = Usim;
    end
   
data.inputs = inputs;
data.outputs = outputs;
% % scale to [-1,1]
data.input_min = min(inputs,[],2);
data.input_max = max(inputs,[],2);
data.output_min = min(outputs,[],2);
data.output_max = max(outputs,[],2);
% in_range = data.input_max - data.input_min;
% out_range = data.output_max - data.output_min;
% data.inputs = 2*(inputs - data.input_min)./(in_range) - 1;
% data.outputs = 2*(outputs - data.output_min)./(out_range) - 1;
end

