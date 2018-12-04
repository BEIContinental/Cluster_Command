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
