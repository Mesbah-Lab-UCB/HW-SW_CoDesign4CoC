%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                          %
%          Generated by MATLAB 9.10 and Fixed-Point Designer 7.2           %
%                                                                          %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%#codegen
function [y1_1,y1_2] = plasma_nn_wrapper_fixpt(x1_1, x1_2, x1_3)
fm = get_fimath();

x1 = fi([fi(x1_1, 1, 20, 18, fm); x1_2; x1_3], 1, 20, 18, fm);
y1 = fi(plasma_nn(x1), 1, 20, 18, fm);
y1_1 = fi(y1(1), 1, 20, 18, fm);
y1_2 = fi(y1(2), 1, 20, 18, fm);
end

function [y1] = plasma_nn(x1)
%PLASMA_NN neural network simulation function.
%
% Auto-generated by MATLAB, 04-Oct-2023 00:25:18.
% 
% [y1] = plasma_nn(x1) takes these arguments:
%   x = 3xQ matrix, input #1
% and returns:
%   y = 2xQ matrix, output #1
% where Q is the number of samples.

%#ok<*RPMT0>

% ===== NEURAL NETWORK CONSTANTS =====

% Input 1
fm = get_fimath();

x1_step1.xoffset = fi([-1;-1;-1], 1, 2, 0, fm);
x1_step1.gain = fi([1;1;1], 0, 1, 0, fm);
x1_step1.ymin = fi(-1, 1, 2, 0, fm);

% Layer 1
b1 = fi([0.35766133846005082608;-0.02886609770463617608;0.39769767342968287416;-0.75776653586736664181;-0.65972238252427484184;-0.98417019952912121461;0.35319826010591803822;1.6287170902828418395], 1, 20, 18, fm);
IW1_1 = fi([-1.2953206751411974196 -0.43710659006262553294 1.0404543579229308392;0.78765401467446083394 -0.018677080508606825476 -0.87635154516600222152;-0.067273659813552266762 0.44252620614874316196 0.0017261982896522309883;0.30115938911612705198 -0.045411962423838270198 -0.39833864148111031156;-0.29067810633773483175 -0.098086838455262670422 0.080366705669851157268;-0.065951561213302367648 0.004788850529114041521 -0.50238942428638688753;-1.4145230258663836764 -0.012540811091352840889 -0.84627633004883029422;-0.77630445689281857291 -0.13277235799491654555 -1.1481192135528952569], 1, 20, 18, fm);

% Layer 2
b2 = fi([-0.24599750787502569493;-0.3762216765590243317;0.33884298190556066954;0.54146907589686110729;0.29096823474555133515;-0.76634894979485512767;-0.010580302266084924689;0.64858328881529170307], 1, 20, 19, fm);
LW2_1 = fi([0.23614907356495387636 0.6953132059533854159 0.17334273331987976041 -0.2534214836253880776 -0.72855287846404226393 -0.30531425058832262209 1.2724599865502306262 0.29954392408944263693;-0.072828213447345024889 0.17043962566133596948 0.001962036588433766892 0.63495338171662196736 -0.85031613126562555216 -0.082267649529636166505 -0.95861960233132348375 0.013633419387287713104;1.0143752913716392872 0.083281897537446497592 -0.54759890312566283921 0.10063435644826479454 0.50446017600018766558 0.80905437346584796465 0.20225534534715111645 -0.74421045881555702994;0.15192070609548774529 1.6761166091958299429 -0.075807769489523724182 0.2621312041375243318 -0.38148655769943839999 0.057119309236383752904 -0.37256662026542636257 -1.2907568811830474331;0.29440457828138211216 -0.20859409905618142567 -0.82720197809690032553 -0.63592674215461264531 0.5096422311369286362 0.010826665479243269274 -0.40767896686792437499 -1.2243083235360898708;1.1005712581072961687 -0.13363813779343733379 0.20611505320778522599 0.28965983832636976736 -0.10298881973217310914 -0.61673741942521198567 -0.19872835259838350641 0.31272259792075318696;0.7901585754848283738 -0.17108253760511366037 0.32683669889233696315 -0.51369360264290997442 0.57970180685219951933 -0.29066906503682243823 0.41824790683228096899 0.15026658201045017815;-0.15019443678706734246 -0.41320264933185774092 -0.28726859176480873392 -0.8746023367368387369 -0.77642388267295570081 0.9767060434122398771 -0.95131763099450339372 0.85925561113437698424], 1, 20, 18, fm);

% Layer 3
b3 = fi([0.67867038128313694756;-0.4811483987213140967;-0.075494046470833228724;0.84863237827258020118;-1.2423186229476010922;-0.97237040559888998636;-0.39588991748924579062;-0.15973229244985742703], 1, 20, 18, fm);
LW3_2 = fi([0.15932931553783513667 0.33717245600484363477 0.98130891754400617621 0.99824297856277710572 0.32662681857331254953 0.51272175817692089428 -0.53427519449444715871 -0.45390025522579430239;-0.88401098634455199665 0.005811343179935590797 -0.39770616717925544314 0.35758840876439346168 0.41029101083324936994 0.50746321534797522723 -0.29798852688273025358 -0.62118332286253008512;0.33857678239484345628 -0.19164516862124769681 1.2383696784157181003 -0.60284415461334484032 1.1040674305139457356 -0.58443828448346457627 -0.3802380460555522812 -1.1630935168978040473;-0.59532014951160094895 0.12047203761493840979 0.63777480069212044711 -1.1436364616313521303 -1.0945421489207853849 -1.2079796592093545726 -0.07678534179276820526 -0.08916153716640212723;0.61358946388869262112 -0.44318282245812573583 -0.50727644886507117228 1.5181320338753709898 0.57074634651990918677 0.060750737780924504716 0.13618550718804567357 0.2944491614594675899;-0.32813902947441730973 0.14156032616982217043 -0.74429420533502987922 -0.38793630708140325325 -0.90052530625531312936 0.65304982994685789599 -0.98207635264504355987 0.77051930538764001888;-0.7118461615899766004 0.67510563102731302454 -0.24035520223292988762 -0.34758787713558814136 -0.062610901156769704912 -0.29077492143875338648 0.39201371077447638713 0.91470842007144681496;0.65921167584025153197 0.95267755777134399686 0.35920926016323795338 -0.67640813543966593624 -0.10384557309284747628 -0.3360349345224369344 0.9095203691771496235 0.66519955454417711849], 1, 20, 18, fm);

% Layer 4
b4 = fi([0.0035098334355473078186;-0.25043910620856335569], 1, 20, 20, fm);
LW4_3 = fi([-0.86336303643061163005 -0.75925015608209367457 -0.14182131904848424564 1.089594010458218909 -0.90520731906775053766 -0.27021925381947564659 0.87107250451553297488 0.55188820854003239891;0.78545308724092366415 -0.90428608644865038357 1.1627779266792914736 -1.0072576096817402735 0.81632580250139041844 0.027816701797936937979 1.0465720041367398974 -0.46316008968564420512], 1, 20, 18, fm);

% Output 1
y1_step1.ymin = fi(-1, 1, 2, 0, fm);
y1_step1.gain = fi([1;1], 0, 1, 0, fm);
y1_step1.xoffset = fi([-1;-1], 1, 2, 0, fm);

% ===== SIMULATION ========

% Dimensions
Q = fi(size(x1,fi(2, 0, 2, 0, fm)), 0, 1, 0, fm); % samples

% Input 1
xp1 = fi(mapminmax_apply(x1,x1_step1), 1, 20, 18, fm);

% Layer 1
a1 = fi(poslin_apply(repmat(b1,1,fi_toint(Q)) + IW1_1*xp1), 0, 20, 18, fm);

% Layer 2
a2 = fi(poslin_apply(repmat(b2,1,fi_toint(Q)) + LW2_1*a1), 0, 20, 18, fm);

% Layer 3
a3 = fi(poslin_apply(repmat(b3,1,fi_toint(Q)) + LW3_2*a2), 0, 20, 17, fm);

% Layer 4
a4 = fi(repmat(b4,1,fi_toint(Q)) + LW4_3*a3, 1, 20, 18, fm);

% Output 1
y1 = fi(mapminmax_reverse(a4,y1_step1), 1, 20, 18, fm);
end

% ===== MODULE FUNCTIONS ========
% Map Minimum and Maximum Input Processing Function
function y = mapminmax_apply(x,settings)
  fm = get_fimath();

  y = fi(bsxfun(@minus,x,settings.xoffset), 1, 20, 17, fm);
  y(:) = bsxfun(@times,y,settings.gain);
  y(:) = bsxfun(@plus,y,settings.ymin);
end

% Linear Positive Transfer Function
function a = poslin_apply(n,~)
  fm = get_fimath();

  a = fi(max(fi(0, 0, 1, 0, fm),n), 0, 20, 17, fm);
  a(isnan(n)) = nan;
end

% Map Minimum and Maximum Output Reverse-Processing Function
function x = mapminmax_reverse(y,settings)
  fm = get_fimath();

  x = fi(bsxfun(@minus,y,settings.ymin), 1, 20, 17, fm);
  x(:) = bsxfun(@rdivide,x,settings.gain);
  x(:) = bsxfun(@plus,x,settings.xoffset);
end



function y = fi_toint(u)
    coder.inline( 'always' );
    if isfi( u )
        nt = numerictype( u );
        s = nt.SignednessBool;
        wl = nt.WordLength;
        y = int32( fi( u, s, wl, 0, hdlfimath ) );
    else
        y = int32( u );
    end
end

function fm = get_fimath()
	fm = fimath('RoundingMethod', 'Floor',...
	     'OverflowAction', 'Wrap',...
	     'ProductMode','FullPrecision',...
	     'MaxProductWordLength', 128,...
	     'SumMode','FullPrecision',...
	     'MaxSumWordLength', 128);
end