close all
clear all
clc

%% Constante laoding

load('AxelSplitHEVv4_NEDC_18_06_15.mat')
load('fa_differential_ratio.mat')
load('fa_gearbox_ratio.mat')
load('ra_differential_ratio.mat')
load('SP_elec.mat')
load('SP_therm.mat')
load('Tab_poly_elec.mat')
load('Tab_poly_therm.mat')
lin_clutch;
Linearisation_vitesse_au_carre;
verif_embrayage_modele;

%% Partie modele hybride avec les deux moteurs sur l'axe avant
reducteur = 2; % reducteur reliant EM a l'axe de transmission
%%% il manque la valeur de l'inertie de la machine elec dans le bloc clutch
%%% nous avons pris une valeur de Inertie_ICE/10
%%
sim('AxleSplitHEVv6_modif2019', 200)

figure(2);
plot(t,DRI_GBX,t,Boite_ref)
legend('driver','ref')
title('boite')

figure(3);
plot(t,V_ref,t,PLA_SPEED) % Vitesse du véhicule
legend('ref','voiture')
title('vitesse')

% figure(4);
% plot(t,DRI_TQ,t,TQ_ICE,t,TQ_EM,t,TQ_global) % Couples 
% title ('Couples')
% legend('driver','ice','elec','global')

figure(5);
plot(t,FA_Brake,t,RA_Brake)
title ('frein demande')
legend('avant','arriere')

figure(6);
plot(t,FA_ICE) % qu'est ce que ça represente
title('FA ICE');

figure(7); 
plot(t,FA_N_ICE); % vitesse moteur thermique
xlabel('temps(s)')
ylabel('vitesse(tr/min)')
title ('[FA N ICE] vitesse moteur therm en sortie de l embrayage n°0')

figure(8);
plot(t,FA_N_SH); % SH? qu'est ce que c'est?
xlabel('temps(s)')
ylabel('vitesse(tr/min)')
title ('[FA N SH]')

figure(9);
plot(t,FA_TQ_CLU0_OUT); % couple sortie moteur thermique
xlabel('temps(s)')
ylabel('Couple(N/m)')
title ('[FA TQ CLU0 OUT] couple moteur thermique sortie embrayage n°0')

figure(10)
plot(t,FA_TQ_GBX); % couple sortie GearBox
xlabel('temps(s)')
ylabel('Couple(N/m)')
title ('[FA TQ GBX] couple GBX sortie embrayage n°1')

figure(11);
plot(t,FA_CLU0_STUCK); % qu'est ce donc?
xlabel('temps(s)')
ylabel('1 = contact, 0 = decouple')
title ('[FA CLU0 STUCK]')

figure(12);
plot(t,FA_CLU1_STUCK); % qu'est ce donc?
xlabel('temps(s)')
ylabel('1 = contact, 0 = decouple')
title ('[FA CLU1 STUCK]')



