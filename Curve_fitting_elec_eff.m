
function [Tab_poly_elec,SP_elec] = Curve_fitting_ele_eff(ra_electrical_machine_speed,ra_electrical_machine_torque,ra_electrical_machine_efficiency)


%%% This function interpolates polynomials to represent the EMA efficiency
%%% cartography . It is important to notice that we eliminate points that
%%% contain NaNs. The cartography symetric, so we only interpolate the
%%% positive/positive part of the map . We obtain then two square zones not
%%% containing NaNs 




PCI = 42.5e3 ; % [J/g]
PCI = 1/(1.27e-4);
ra_electrical_machine_efficiency_norm = ra_electrical_machine_efficiency/100 ; 





SP1 = ra_electrical_machine_speed(11:17) ; 
SP2 = ra_electrical_machine_speed(18:21) ;

SP_elec = [SP1 SP2];

TOR1 =  ra_electrical_machine_torque(19:37) ; 
TOR2 =  ra_electrical_machine_torque(19:30) ; 

TOR_elec = [TOR1 TOR2] ; 

M1 = ra_electrical_machine_efficiency_norm(19:37,11:17) ; 
M2 = ra_electrical_machine_efficiency_norm(19:30,18:21) ; 



for ind = 1:7
a1_elec(ind,:) = polyfit(TOR1',M1(:,ind),6) ;
x = TOR1 ; 
Pol1_elec(ind,:) =  a1_elec(ind,7)  + a1_elec(ind,6).*x + a1_elec(ind,5).*x.^2 + a1_elec(ind,4).*x.^3 + a1_elec(ind,3).*x.^4+ a1_elec(ind,2).*x.^5 + a1_elec(ind,1).*x.^6 ;

end


for ind = 1:4
a2_elec(ind,:) = polyfit(TOR2',M2(:,ind),6) ;
x = TOR2 ; 
Pol2_elec(ind,:) =  a2_elec(ind,7)  + a2_elec(ind,6).*x + a2_elec(ind,5).*x.^2 + a2_elec(ind,4).*x.^3 + a2_elec(ind,3).*x.^4+ a2_elec(ind,2).*x.^5 + a2_elec(ind,1).*x.^6 ;
end


% 
figure
mesh(ra_electrical_machine_speed,ra_electrical_machine_torque,ra_electrical_machine_efficiency_norm)
hold on
subplot(1,2,1)
mesh(SP2,TOR2,Pol2_elec')
hold on
mesh(SP1,TOR1,Pol1_elec')

subplot(1,2,2)
mesh(SP2,TOR2,M2)
hold on
mesh(SP1,TOR1,M1)

figure
mesh(SP2,TOR2,(M2-Pol2_elec')./M2)
hold on
mesh(SP1,TOR1,(M1-Pol1_elec')./M1)


Tab_poly_elec  = [a1_elec;a2_elec];%/PCI ; % On divise par le PCI pour obtenir la consommation de carburant équivalente à la puissance trouvée . 

end