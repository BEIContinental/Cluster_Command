%% Calculus of the PI parameters of the idle controller
% INTERNSHIP 2014

% controller transfer function :
% PI=Kp(1+p/Taui);
% methos of the symetrical optimum

%% idle transmission off - phase margin of 25°
phase_margin_tr_off=25*pi/180;
test_fa_taui_idle_tr_off=((tan(phase_margin_tr_off/2 +pi/4))^2)*fa_tau_ice;
test_fa_kp_idle_tr_off=fa_ice_inertia/(30/pi)/((tan(phase_margin_tr_off/2+pi/4))*fa_tau_ice);

%% idle transmission on - phase margin of 45°
phase_margin_tr_on=45*pi/180;
test_fa_taui_idle_tr_on=((tan(phase_margin_tr_on/2 +pi/4))^2)*fa_tau_ice;
test_fa_kp_idle_tr_on=(pi*(pla_wheel_radius^2)*pla_equivalent_weight)./((fa_gearbox_ratio.*fa_gearbox_ratio.*fa_differential_ratio.*fa_differential_ratio.*fa_gearbox_efficiency.*fa_gearbox_efficiency)*30)/(tan(phase_margin_tr_on/2+pi/4)*fa_tau_ice);
test_fa_kp_idle_tr_on(1,1)=1; %remove the value for neutral position (case of inf)
clear phase_margin_tr_on phase_margin_tr_off;
Te=0.01;