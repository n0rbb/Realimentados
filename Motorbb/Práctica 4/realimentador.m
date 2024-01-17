p = 63.7990;
ke = 6.3065e+03;
A = [0 1; 0 -p]
B = [0; ke] %Solo controlo la velocidad
K = place(A, B, [-0.3 * p, -0.4 * p])

%u = 1 Vref
%Diseño del estimador
C = [1, 0];
L = acker(A', C', [-1.2*p, -1.2*p])'

Aamp = [A zeros(2, 1); C 0]
Bamp = [B; 0]

Ki = acker(Aamp, Bamp, [-0.5*p, -0.5*p, -0.7*p])

