%% gestion de l'embrayage
%%% la linearisation de la sensibilite de clutch
% Afin de commander l'embrayage avec rho (tauw de couple transmis), nous
% allons linéariser la sensibilite de clutch


epsilon = 0.001;
fa_clu_pv_lin = [0 0.100000000000000 0.300000000000000 0.500000000000000 0.700000000000000 0.900000000000000 1];
fa_clu_pos_lin = [1 1-epsilon 0.700000000000000 0.500000000000000 0.300000000000000 epsilon 0];
% figure;
% plot(fa_clu_pv_lin,fa_clu_pos_lin)

fa_clu_pv_lin_inv = [0 epsilon 0.3 0.5 0.7 1-epsilon 1];
fa_clu_pos_lin_inv = [1 0.9 0.7 0.5 0.3 0.1 0];
% figure;
% plot(fa_clu_pv_lin_inv,fa_clu_pos_lin_inv)

