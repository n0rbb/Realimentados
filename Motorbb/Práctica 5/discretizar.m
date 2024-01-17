warning("off")

%Crear modelo del sistema del motor
sys = ss(A, B, C, 0)
%Discretizar el modelo: c2d(modelo, T) (T = 10^-h s)
T = 1e-4
sysd = c2d(sys, T)

%Crear el control discreto
Kd = acker(sysd.A, sysd.B, [exp(-0.3 * p * T), exp(-0.3 * p * T)])
Ld = acker(sysd.A', C', [exp(-1.2*p * T), exp(-1.2 * p * T)] )'

DAamp = [sysd.A zeros(2, 1); T * C, 1] 
DBamp = [sysd.B; 0]

Kid = acker(DAamp, DBamp, [exp(- p * T), exp(-0.5 * p * T), exp(-0.7*p*T)])

warning("on")
