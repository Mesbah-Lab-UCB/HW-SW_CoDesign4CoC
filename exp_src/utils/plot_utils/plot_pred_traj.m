function plot_pred_traj(var)
% function to plot predicted trajectories; assumes variable values are
% given in a cell of dimensions Np-by-Nscenarios, where Np is the
% prediction horizon, Nscenarios is the number of scenarios. Each cell
% should contain column vectors that have the same dimensions (e.g.,
% nv-by-1, where nv is the number of variables)

nv = length(var{1,1});

figure()
hold on
[~, c] = size(var);
for i = 1:c
    y_traj = [var{:,i}];
    
    for j = 1:nv
    subplot(nv,1,j)
        hold on
        plot(y_traj(j,:), ':')
        ylabel(['y' num2str(j)])
    end
end
xlabel('Time Iteration')
end
