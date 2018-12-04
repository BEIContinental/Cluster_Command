close all
clear all
clc

%% Constants loading

load('AxelSplitHEVv4_NEDC_18_06_15.mat')
load('fa_differential_ratio.mat')
load('fa_gearbox_ratio.mat')
load('ra_differential_ratio.mat')
load('SP_elec.mat')
load('SP_therm.mat')
load('Tab_poly_elec.mat')
load('Tab_poly_therm.mat')

%sim('AxleSplitHEVv6', 200)
sim('AxleSplitHEVv7', 200)

figure
plot(t,DRI_GBX,t,Boite_ref)
legend('driver','ref')
title('boite')

figure
plot(t,V_ref,t,PLA_SPEED)
legend('ref','voiture')
title('vitesse')

figure
plot(t,DRI_TQ,t,TQ_ICE,t,TQ_elec)
title ('couples')
legend('driver','ice','elec')

figure
plot(t,DRI_Brake,t,FA_Brake,t,RA_Brake)
title ('frein demande')
legend('ref','avant','arriere')

figure
plot(t,FA_ICE)
title('FA_ICE');

figure; 
plot(t,Command_RA,t,Command_FA);
legend('RA','FA')
title ('Couple repartition')
