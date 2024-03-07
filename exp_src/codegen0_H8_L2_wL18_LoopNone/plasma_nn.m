function [y1] = plasma_nn(x1)
%PLASMA_NN neural network simulation function.
%
% Auto-generated by MATLAB, 22-Jul-2022 12:43:56.
% 
% [y1] = plasma_nn(x1) takes these arguments:
%   x = 3xQ matrix, input #1
% and returns:
%   y = 2xQ matrix, output #1
% where Q is the number of samples.

%#ok<*RPMT0>

% ===== NEURAL NETWORK CONSTANTS =====

% Input 1
x1_step1.xoffset = [-1;-1;-1];
x1_step1.gain = [1;1;1];
x1_step1.ymin = -1;

% Layer 1
b1 = [-0.56000428004896896095;0.20636874968419066656;-0.78026134136968094968;-0.89209976266678570056;0.055181297248563472568;0.48996236594252229324;0.90103176406086338268;-0.74018758305253973262];
IW1_1 = [0.89830776277585899781 0.59987203309012637753 -0.012683236010575804631;0.72874065562133560903 -0.39566972270100281284 0.84221489030872165316;0.084085933446197788643 0.93568706338722829052 0.26698218796248601725;-0.72275111434264172061 -0.30003246803038252644 0.099447216582279063246;-0.33639366304179996181 -0.66820236967473611855 0.84080113642900711213;-0.53872728015094573095 -0.63926273211512885108 -0.61565046834490777528;0.58682947982074251669 0.47775676436647740442 0.69329916835515481566;-0.4914356420569379047 -0.05342230219454147111 0.50745818855699065253];

% Layer 2
b2 = [0.33855775743156635293;-0.019729552050964827004;-0.51661742817233458069;-0.19217570882377055241;-0.6075850251401330171;-0.73605341478732988492;0.78050622672888214648;1.0434992225451817927];
LW2_1 = [0.27839730404115331508 -0.53335993237778289711 -0.53396340373034423266 -0.78669445963883122275 -0.42212367351770097024 0.60030974454368635218 -0.18222739860654937893 0.80543221983056212387;-0.061170334598141744287 0.20396388280327304443 0.82667472300333910695 0.92379616171010736636 0.52700359536461904852 0.40218512953195151294 -0.84806661661831617138 0.88957437944329198487;-0.97619586099751720631 -0.47405743091971142 -0.69524396206155403277 -0.99073155173186511213 -0.13717234507291076184 0.099720403672663993078 -0.52016769289268394161 -0.018271815063840124438;-0.32575471120223697952 0.30815819695356450048 0.65163395497909482046 0.54982092942300475613 0.8212951888590458438 -0.71009040355254637866 -0.753362130329668922 -0.021494723199962262328;-0.67563538361351449524 0.37842900628001552299 0.076684870520114190029 0.63460644130686594266 -0.61385633262664329735 0.93384409597671158565 -0.63013734954445721481 -0.32456118035724568216;0.58856908136781393992 0.49630318564741893184 0.99226943325377092719 0.73738941072701935653 -0.47239416695601987861 0.24411026297013194153 -0.52009494867019445685 0.80010769283532390261;-0.43432669917190652731 0.26184825591165794556 -0.87754410855053832652 -0.83112830897817935316 -0.67937484978253448453 -0.39168468896580932448 -0.10326522817528327458 -0.26150643775956994297;-0.35752431402680517891 -0.83235724400613486651 -0.11464346044910733724 -0.20043470180220701593 -0.62046712453578578561 -0.02410837953726441274 -0.96486368776185305052 -0.77759448941242514941];

% Layer 3
b3 = [-0.87371230904394681094;0.57622627019538419368];
LW3_2 = [0.37900917216201968074 -0.47161097691173431423 0.64238808039591810406 -0.91395239668438432723 -0.0092897435878128431508 0.29549192627261344768 0.42693169742905062725 0.90619776279159214294;-0.42724044970661251286 -0.3013206326516411071 -0.96919312469688989609 -0.66201994107459127825 0.59735689079267306756 -0.098152587138110147791 -0.15669297624632777532 -0.43409838619731427878];

% Output 1
y1_step1.ymin = -1;
y1_step1.gain = [1;1];
y1_step1.xoffset = [-1;-1];

% ===== SIMULATION ========

% Dimensions
Q = size(x1,2); % samples

% Input 1
xp1 = mapminmax_apply(x1,x1_step1);

% Layer 1
a1 = poslin_apply(repmat(b1,1,Q) + IW1_1*xp1);

% Layer 2
a2 = poslin_apply(repmat(b2,1,Q) + LW2_1*a1);

% Layer 3
a3 = repmat(b3,1,Q) + LW3_2*a2;

% Output 1
y1 = mapminmax_reverse(a3,y1_step1);
end

% ===== MODULE FUNCTIONS ========

% Map Minimum and Maximum Input Processing Function
function y = mapminmax_apply(x,settings)
  y = bsxfun(@minus,x,settings.xoffset);
  y = bsxfun(@times,y,settings.gain);
  y = bsxfun(@plus,y,settings.ymin);
end

% Linear Positive Transfer Function
function a = poslin_apply(n,~)
  a = max(0,n);
  a(isnan(n)) = nan;
end

% Map Minimum and Maximum Output Reverse-Processing Function
function x = mapminmax_reverse(y,settings)
  x = bsxfun(@minus,y,settings.ymin);
  x = bsxfun(@rdivide,x,settings.gain);
  x = bsxfun(@plus,x,settings.xoffset);
end