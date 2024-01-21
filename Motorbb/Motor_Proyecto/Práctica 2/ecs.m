syms ke s p V w(t) theta(t) E(s) thetalap(t)

%Defino las ecuaciones diferenciales para resolver w (velocidad), theta
%(posición) y las resuelvo 
%Primero la velocidad
eqvel = diff(w, t) ==  -p*w + ke * V
wsol = dsolve(eqvel, w(0) == 0)

%Y luego la posición
eqpos = diff(theta, t) == wsol 
thetasol = dsolve(eqpos, theta(0) == 0) 

%Calculo la transformada de laplace de e(t) = V
E(s) = laplace(V, t, s) 
%Calculo la transformada inversa de la función de transferencia Th(s)
Th = ke /(s * (s + p)) * E(s) 
thetalap(t) = ilaplace(Th)

wlap = diff(thetalap(t), t)