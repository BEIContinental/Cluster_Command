%%% Linéarisation des forces aerodynamique (la vitesse au carré)
%%% Faero = - Kaero V²
%%% on linearise cette force par plusieurs morceaux de 10 km/h
%%% on a :  V² = a*V+b


V=[0:1:140];
V2=V.^2;
b=[];
a=[];
table_a = [];
table_b = [];
table_V = [];
%% calcule des coeff a et b
for i=1:10:140
   ai= V(i) + V(i+10);
   a=[a ai];
   bi = V2(i) - ai*V(i);
   b=[b bi];
   table_a = [table_a ai ai];
   table_b = [table_b bi bi];
   table_V = [table_V V(i)+0.1 V(i+10)];
end
table_V(1) = 0;
%% trace la courbe
V2_lin=[];
V_lin=[];

for i=0:1:13
    V2_lin = [V2_lin a(i+1)*V(10*i+1)+b(i+1)];
    V_lin = [V_lin i*10];
end


figure
plot(V,V2)
hold on
plot(V_lin,V2_lin)
legend('Vree','V decoupe')

