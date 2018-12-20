function [I] = plus_proche(tab,val)
%%% Calcul l'indice le plus proche qui donne la valeur "val" dans "tab"  

tab=tab-val;
[valeur,indice]=min(abs(tab));
I = indice;

end
