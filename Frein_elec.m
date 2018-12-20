function T_opt = Frein_elec(T,V) 

%%% This function takes the actual torque and speed on the EMA, and 
%%% calculates the optimal Electrical braking torque (if requested)
%%% It is not implemented , because its results showd only that the optimal
%%% point is always the maximum torque ...


load('AxleSplitHEVv2.mat')

SP_elec = ra_electrical_machine_speed(11:21) ; 
Tab_eff = ra_electrical_machine_efficiency(19:37,11:21); 
TOR_elec = ra_electrical_machine_torque(19:37) ; 



% En entrée on a le couple max admissible par la machine élec , et la
% vitesse de rotation en tr/min de la machine élec . 

ind =  plus_proche(SP_elec,V) ; 

eff = Tab_eff(:,ind) ;

P = eff.*TOR_elec' ;

[~,a] = max(P) ; 

T_opt = min(TOR_elec(a),T) ;

end