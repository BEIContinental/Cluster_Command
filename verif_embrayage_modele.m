%%% 
%%%
%%%%
Ie = fa_ice_inertia;
%%%%
Rdiff = fa_differential_ratio;
Rgbx = fa_gearbox_ratio;
Rroue = pla_wheel_radius;
eta1 = fa_gearbox_efficiency;
eta2 = 2 - fa_gearbox_efficiency;
M = pla_equivalent_weight;
Rdiff2 = ra_differential_ratio;
eta_em1 = ra_transmission_efficiency;
eta_em2 = 2 - ra_transmission_efficiency;
%%%

c1 = pla_k*9.80665*pla_equivalent_weight;
c2 = (9.80665*pla_equivalent_weight*pla_f);
Kaero = pla_kaero;

%%%
femax = fa_max_tq_clu;
%%
A = [0 0;0 -c1/M ];
B1 = [1/Ie 0 -femax/Ie; 0 Rdiff*Rgbx(2)*Rdiff2*eta_em1/(M*Rroue^2) ((Rdiff*Rgbx(2)/Rroue)^2)*femax*eta1/M];
B2 = [1/Ie 0 -femax/Ie; 0 Rdiff*Rgbx(2)*Rdiff2*eta_em1/(M*Rroue^2) ((Rdiff*Rgbx(2)/Rroue)^2)*femax*eta2/M];
%%%
Bferme1 = [((Rdiff*Rgbx(2)/Rroue)^2)*eta1/M    Rdiff*Rgbx(2)*Rdiff2*eta_em1/(M*Rroue^2)];
Bferme2 = [((Rdiff*Rgbx(2)/Rroue)^2)*eta2/M    Rdiff*Rgbx(2)*Rdiff2*eta_em1/(M*Rroue^2)];
Aferme = A(2,2);


% sys = ss(A,B2,eye(2),0);
% damp(sys);

