function [Tab_poly_therm,SP_therm] = Curve_fitting_conso(fa_conso_speed,fa_conso_torque,fa_fuel_consumption)

%%%%% The goal of this function is interpolating polynomials to approach
%%%%% the fuel consumption cartography . It is necessary to note that we
%%%%% eliminate the points that are NaN from the cartography before the interpolation.
%%%%% We get the three separated square zones not containing any NaN.    


fa_fuel_consumption = fa_fuel_consumption/max(max(fa_fuel_consumption)) ; 

M1 = fa_fuel_consumption(1:35,3:18);
M2 = fa_fuel_consumption(1:42,19:42);
M3 = fa_fuel_consumption(1:33,43:55);

SP1 = fa_conso_speed(3:18);
SP2 = fa_conso_speed(19:42);
SP3 = fa_conso_speed(43:55);
SP = [SP1 SP2 SP3];

TOR1 =  fa_conso_torque(1:35);
TOR2 =  fa_conso_torque(1:42);
TOR3 =  fa_conso_torque(1:33);

for ind = 1:16
a1(ind,:) = polyfit(TOR1,M1(:,ind)',6) ;
x = TOR1 ; 
Pol1(ind,:) =  a1(ind,7)  + a1(ind,6).*x + a1(ind,5).*x.^2 + a1(ind,4).*x.^3 + a1(ind,3).*x.^4+ a1(ind,2).*x.^5 + a1(ind,1).*x.^6 ;

end


for ind = 1:24
a2(ind,:) = polyfit(TOR2,M2(:,ind)',6) ;
x = TOR2 ; 
Pol2(ind,:) =  a2(ind,7)  + a2(ind,6).*x + a2(ind,5).*x.^2 + a2(ind,4).*x.^3 + a2(ind,3).*x.^4 + a2(ind,2).*x.^5 + a2(ind,1).*x.^6 ;

end

for ind = 1:13
a3(ind,:) = polyfit(TOR3,M3(:,ind)',6) ;
x = TOR3 ; 
Pol3(ind,:) =  a3(ind,7)  + a3(ind,6).*x + a3(ind,5).*x.^2 + a3(ind,4).*x.^3 + a3(ind,3).*x.^4 + a3(ind,2).*x.^5 + a3(ind,1).*x.^6 ;

end

figure
subplot(1,2,1)
mesh(SP1,TOR1,Pol1')
hold on 
mesh(SP1,TOR1,M1)
mesh(SP2,TOR2,Pol2')
hold on 
mesh(SP3,TOR3,Pol3')
hold on 
subplot(1,2,2)
mesh(fa_conso_speed,fa_conso_torque,fa_fuel_consumption)

figure
mesh(SP1,TOR1,Pol1')
hold on 
mesh(SP1,TOR1,M1)
mesh(SP2,TOR2,Pol2')
hold on 
mesh(SP3,TOR3,Pol3')
hold on 
mesh(fa_conso_speed,fa_conso_torque,fa_fuel_consumption)
title('superposés')


figure
mesh(SP2,TOR2,(M2-Pol2')./M2)
hold on 
mesh(SP1,TOR1,(M1-Pol1')./M1)
hold on
mesh(SP3,TOR3,(M3-Pol3')./M3)
title('erreur')


%% Sauvegarde du tableau des fonctions polynomiales 

Tab_poly = [a1;a2;a3];


% Pour une vitesse donnée  wk, on a un polynôme liant la conso au couple .
% % et donc à alpha . 
% 
%  ind = plus_proche(SP,w)
%  Tab_poly(ind,:)

 SP_therm = SP(5:end-1); % Les vitesses supprimés avaient donné des coefficients NaN 
 Tab_poly_therm = Tab_poly(5:end-1,:); % On les supprime alors de notre répértoire de vitesse pour lequels on arrive à interpoller 
                                % On a donc un répértoire de fonction
                                % polynomiales pour une plage de vitesse
                                % entre 800tr/min et 5500 tr/min (C'est des rpm non ?)
                                
              % On a donc un répértoire de polynomes de fonction polynomiales de alpha qui donnent la consommation thermique . 
              % Cela veut dire qu'à partir d'une vitesse entre 800 et 5500
              % on peut écrire la consommation en fontion de alp^ha 
              
end
              