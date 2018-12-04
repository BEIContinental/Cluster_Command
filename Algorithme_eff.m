function [alpha_opt,S,alpha_min,alpha_max] = Algorithme_eff(T,V,Tmax_elec,Tmin_elec,Tmax_therm,Tmin_therm,GBX)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%% Optimization of torque repartition algorithm (in acceleration phase)%%%%%%%%%%%%%%%%%%% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%          This algorithm minimizes the sum of instantanious consumptions during
%%%%%%%%%%          a prediction horizon . We assume that the torque requested by the
%%%%%%%%%%          driver will always be constant during a prediction horizon that we
%%%%%%%%%%          estimate of 4 seconds (Corresponding N = 400 number of sampling
%%%%%%%%%%          times). The speed is then a slope . Knowing the values of torque and
%%%%%%%%%%          speed , we can express the consumption using the polynoms
%%%%%%%%%%          interpolated from the engines look up tables.
%%%%%%%%%%          Tq_requested = alpha*T_ICE + (1-alpha)*T_elec . 
%%%%%%%%%%          alpha = 0 ===> Pure Electric Mode .  
%%%%%%%%%%          alpha = 1 ===> Pure ICE Mode .
%%%%%%%%%%          The minimization process is a computation of the final criteria with
%%%%%%%%%%          all the possible values of alpha, and then select the minimum . 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

SPE=load ('SP_elec.mat','SP_elec');
TPE=load ('Tab_poly_elec.mat','Tab_poly_elec');
RDR=load ('ra_differential_ratio.mat','ra_differential_ratio');
SPT=load ('SP_therm.mat','SP_therm');
TPT=load ('Tab_poly_therm.mat','Tab_poly_therm');
FGR=load ('fa_gearbox_ratio.mat','fa_gearbox_ratio');
FDR=load ('fa_differential_ratio.mat','fa_differential_ratio');

SP_elec=SPE.SP_elec ; 
Tab_poly_elec=TPE.Tab_poly_elec; 
ra_differential_ratio=RDR.ra_differential_ratio ; 
SP_therm=SPT.SP_therm; 
Tab_poly_therm=TPT.Tab_poly_therm; 
fa_gearbox_ratio=FGR.fa_gearbox_ratio; 
fa_differential_ratio=FDR.fa_differential_ratio ; 


N = 100 ; 
Sp_elec = [] ; 
Sp_therm = [] ;
te = 0.01; 
I_elec = [] ; 
I_therm = [] ;
poly_therm = []; 
poly_elec = [];
f = [] ; 
g = [] ; 
F = [] ; 
G = [] ;
m = [] ; 
alpha_opt = [] ;

Sp(1) = V*(60/(2*(pi))) ;



%% Calcul des bornes de alpha 

alpha_min = max(0 ,  max( 1 - (Tmax_elec/T) , Tmin_therm/T ) ); 
alpha_max = min( 1 ,min( 1 - (Tmin_elec/T) , Tmax_therm/T ) ); 



%% Calcul des vitesse 

for k = 1 : N 
    
    Sp(k+1) = T*te + Sp(k) ;
%     Sp_elec(k+1) = T*te + Sp_elec(k) ; 
%     Sp_therm(k+1) = T*te + Sp_therm(k) ; 
end

Sp_elec=Sp*ra_differential_ratio;
Sp_therm= Sp*fa_differential_ratio*fa_gearbox_ratio(GBX+1) ;


%% Calcul des fonction de consomation 

for k = 1 : N 
   
I_therm(k) = plus_proche(SP_therm,Sp_therm(k)/(60/(2*(pi)))) ;
I_elec(k) = plus_proche(SP_elec,Sp_elec(k)/(60/(2*(pi)))) ;

poly_therm = Tab_poly_therm(I_therm(k),:);
poly_elec = Tab_poly_elec(I_elec(k),:);
 p_el=poly_elec;
 
    for p = 1 : 7 
        poly_therm(p) = poly_therm(p)*T^(7-p);
        poly_elec(p) = poly_elec(p)*T^(7-p);
    end
f(k,:) = poly_therm ; 
g(k,:) = -poly_elec ; 

end

save f 


F = sum(f,1); %/length(f(:,1)) ; 
G = sum(g,1); %/length(g(:,1)) ; 

%% Recherche du alpha optimal  

alpha = alpha_min: 0.01 : alpha_max ; 
% 
% for x = 1 : length(f(:,1)) 
% for k = 1 : length(alpha)    
% K(x,k) = f(x,7)  + f(x,6).*(1-alpha(k)) + f(x,5).*(1-alpha(k)).^2 + f(x,4).*(1-alpha(k)).^3 + f(x,3).*(1-alpha(k)).^4 + f(x,2).*(1-alpha(k)).^5 + f(x,1).*(1-alpha(k)).^6 ; 
% end 
% % figure
% % plot(alpha,K(x,:))
% end

S = zeros(1,length(alpha)) ;
 
for k = 1 : length(alpha)

for p = 1 : 7
%     S_f(k,p)=F(p)*alpha(k)^(7-p);
%     S_g(k,p)=G(p)*(1 - alpha(k))^(7-p) ; 
    S(k) = S(k)   + F(p)*alpha(k)^(7-p) +  G(p)*(1 - alpha(k))^(7-p) ; 
    
    
end
S_2(k)=(F(7)  + F(6).*alpha(k) + F(5).*alpha(k)^2 + F(4).*alpha(k)^3 + F(3).*alpha(k)^4 + F(2).*alpha(k)^5 + F(1).*alpha(k)^6 );
S_3(k)=(G(7)  + G(6).*(1-alpha(k)) + G(5).*(1-alpha(k)).^2 + G(4).*(1-alpha(k)).^3 + G(3).*(1-alpha(k)).^4 + G(2).*(1-alpha(k)).^5 + G(1).*(1-alpha(k)).^6 );
S_t(k)=S_3(k)+S_2(k);

end
    
[m,alpha_opt] = min(S) ; 
alpha_opt = alpha(alpha_opt) ;

%%trace

figure
subplot(3,1,1)
hold on
plot(alpha,S_2)
plot(alpha,alpha*T,'r')
title(['alphaopt=',num2str(alpha_opt),'T=',int2str(T)])
ylabel('thermique')
hold off
subplot(3,1,2)
hold on
plot(alpha,S_3)
plot(alpha,(1-alpha)*T,'r')
ylabel('electrique')
hold off
subplot(3,1,3)
plot(alpha,S)
ylabel('critere total')
end