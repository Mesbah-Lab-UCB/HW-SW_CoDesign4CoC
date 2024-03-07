function plot_sim_data(sim_data, sim_params, Nsim, varargin)

    new_figure = true;
    plot_params = struct;
    plot_params.line_width = 2;
    plot_params.font_size = 15;
    label = 'msMPC';
    line_color_style = 'b-';
    
    if nargin > 3
        for i = 1:2:length(varargin)
            name = varargin{i};
            value = varargin{i+1};
            switch name
                case 'new_figure'
                    new_figure = value;
                case 'plot_params'
                    plot_params = value;
                case 'label'
                    label = value;
                case 'line_color_style'
                    line_color_style = value;
                otherwise
                    warning(['Name "', name, '" not recognized. Value not assigned'])
            end
        end
    end
    ts = sim_params.ts;
    t = 0:ts:Nsim;
    
    st = sim_data.CEM_stop_time;
    CEMplot = sim_data.CEMsim(1:st);
    ref_plot = sim_data.Yrefsim(1:st);
    Tplot = sim_data.Ysim(1,:) + sim_params.yss(1);
    Tplot = Tplot(1:st);
    
    if new_figure
        figure()
        
        subplot(221)
        hold on
        yl = yline(ref_plot(1), 'k--'); % reference line
        yl.LineWidth = plot_params.line_width; yl.Label='Reference';
        xlabel('Time (s)')
        ylabel('CEM (min)')
        ylim([0,1.7])
        
        subplot(222)
        hold on
        Tmax = sim_params.Tmax;
        yl = yline(Tmax, 'r--'); % constraint line
        yl.LineWidth = plot_params.line_width; yl.Label='Constraint';
        xlabel('Time (s)')
        ylabel('Surface Temperature ($^\circ$C)', 'Interpreter', 'latex')
        
        subplot(223)
        hold on
        Pmax = sim_params.ctrl_params.u_max(1)+sim_params.ctrl_params.uss(1);
        Pmin = sim_params.ctrl_params.u_min(1)+sim_params.ctrl_params.uss(1);
        yl = yline(Pmin, 'r-'); % minimum line
        yl.LineWidth = plot_params.line_width; yl.Label='Minimum';
        yl = yline(Pmax, 'r-'); % maximum line
        yl.LineWidth = plot_params.line_width; yl.Label='Maximum';
        ylim([Pmin-0.2*(Pmax-Pmin), Pmax+0.2*(Pmax-Pmin)])
        xlabel('Time (s)')
        ylabel('Power (W)')

        subplot(224)
        hold on
        qmin = sim_params.ctrl_params.u_min(2)+sim_params.ctrl_params.uss(2);
        qmax = sim_params.ctrl_params.u_max(2)+sim_params.ctrl_params.uss(2);
        yl = yline(qmin, 'r-'); % minimum line
        yl.LineWidth = plot_params.line_width; yl.Label='Minimum';
        yl = yline(qmax, 'r-'); % maximum line
        yl.LineWidth = plot_params.line_width; yl.Label='Maximum';
        ylim([qmin-0.2*(qmax-qmin), qmax+0.2*(qmax-qmin)])
        xlabel('Time (s)')
        ylabel('Flow Rate (SLM)')
    end
    
    subplot(221)
    hold on
    a = plot(t(1:st), CEMplot, line_color_style, 'DisplayName', label);

    subplot(222)
    hold on
    a = plot(t(1:st), Tplot, line_color_style, 'DisplayName', label);

    subplot(223)
    hold on
    u_plot = sim_data.Usim(1,:)+sim_params.ctrl_params.uss(1);
    [x,y] = stairs(t(1:st-1), u_plot(1:st-1));
    plot(x, y, line_color_style, 'DisplayName', label)

    subplot(224)
    hold on
    u_plot = sim_data.Usim(2,:)+sim_params.ctrl_params.uss(2);
    [x,y] = stairs(t(1:st-1), u_plot(1:st-1));
    plot(x, y, line_color_style, 'DisplayName', label)

end