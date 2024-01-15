sys = ss(A, B, C, 0)
T = 1e-4
sysd = c2d(sys, T)
%Crear un modelo del motor motormods = ss(A, B, C, D)
%Discretizar el modelo: motorz = c2d(motors, T) (T = 10^-h s)
%motorz.A = G
%motorz.B = H
%motorz.C = C

Kd = acker(sysd.A, sysd.B, [exp(-0.3 * p * T), exp(-0.3 * p * T)])
Ld = acker(sysd.A', C', [exp(-1.2*p * T), exp(-1.2 * p * T)] )'

DAamp = [sysd.A zeros(2, 1); T * C, 1] 
DBamp = [sysd.B; 0]

Kid = acker(DAamp, DBamp, [exp(- p * T), exp(-0.5 * p * T), exp(-0.7*p*T)])


