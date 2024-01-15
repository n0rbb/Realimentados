clear all
close all
%creamos unas variables simbolicas 
syms x1 x2 a b real 
syms s

%definimos las ecuaciones del sistema
f(1,1) = x2 + 2*x1^2+x1*x2
f(2,1) = -x1 - x2 + x1*x2 + 3*x2^2

%Calculamos el Jacobiano
J = jacobian(f,[x1 x2])
%obtenemos los puntos en que se anulan las ecuaciones de estado, ya que
%dichos puntos son precisamente los puntos deequilibrio
[x10,x20] = solve(f,[x1 x2])
X0 = [x10,x20]
%calculamos ahora resultados para todos los puntos de equilibrio
%encontrados

for i =1:size(X0,1)
    %sustituimos la solucion en la expresion del Jacobiano
    Je = subs(J,{x1,x2},X0(i,:))
    E = double(eig(Je))
    %calculamos el p carcateristico
    
    D = det(s*eye(length(X0(i,:))) - Je) %ver que forma tiene mas que nada 
end

%solo (0,0) es estable, asi que solo tiene sentido buscar estabilidad en
%torno a este punto...
Je = double(subs(J,{x1,x2},X0(1,:)))
Q = [1 0;0 1]
P = lyap(Je',Q)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%La funcion de lyapunov es entonces
V = [x1 x2] * P * [x1;x2]
%para aplicarla al sistema no lineal
grV = gradient(V)
dotV = simplify(grV'*f)

