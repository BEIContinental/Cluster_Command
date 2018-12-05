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

figure
plot(t,DRI_GBX,t,Boite_ref)
legend('driver','ref')
title('boite')

figure
plot(t,V_ref,t,PLA_SPEED) % Vitesse du véhicule
legend('ref','voiture')
title('vitesse')

figure
plot(t,DRI_TQ,t,TQ_ICE,t,TQ_elec) % Couples 
title ('couples')
legend('driver','ice','elec')

% figure
% plot(t,DRI_Brake,t,FA_Brake,t,RA_Brake)
% title ('frein demande')
% legend('ref','avant','arriere')

figure
plot(t,FA_ICE) % qu'est ce que ça represente

figure 
plot(t,FA_N_ICE); % vitesse moteur thermique
xlabel('temps(s)')
ylabel('vitesse(tr/min)')
title ('[FA_N_ICE] vitesse moteur therm en sortie de l embrayage n°0')

figure
plot(t,FA_N_SH); % SH? qu'est ce que c'est?
xlabel('temps(s)')
ylabel('vitesse(tr/min)')
title ('[FA_N_SH]')

figure 
plot(t,FA_TQ_CLU0_OUT); % couple sortie moteur thermique
xlabel('temps(s)')
ylabel('Couple(N/m)')
title ('[FA_TQ_CLU0_OUT] couple moteur thermique sortie embrayage n°0')

figure
plot(t,FA_TQ_GBX); % couple sortie GearBox
xlabel('temps(s)')
ylabel('Couple(N/m)')
title ('[FA_TQ_GBX] couple GBX sortie embrayage n°1')

figure
plot(t,FA_CLU0_STUCK); % qu'est ce donc?
xlabel('temps(s)')
ylabel('Unknown')
title ('[FA_CLU0_STUCK]')

figure
plot(t,FA_CLU1_STUCK); % qu'est ce donc?
xlabel('temps(s)')
ylabel('Unknown')
title ('[FA_CLU1_STUCK]')



