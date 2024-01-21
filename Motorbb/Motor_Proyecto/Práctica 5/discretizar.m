%Es necesario haber ejecutado antes realimentador.m (Práctica 4)
close all;
warning("off")
p0 = 75.6862;
ke0 = 7.3343e+03;
%Crear modelo del sistema del motor
sys = ss(A, B, C, 0)
%Discretizar el modelo: c2d(modelo, T) (T = 10^-h s)
T = 1e-4
sysd = c2d(sys, T)

%Crear el control discreto
Kd = acker(sysd.A, sysd.B, [exp(-0.3 .* p0 * T), exp(-0.3 * p0 * T)])
Ld = acker(sysd.A', sysd.C', [exp(-1.2 *p0 * T), exp(-1.2 * p0 * T)] )'
%Discretizar acción integral
DAamp = [sysd.A zeros(2, 1); T * C, 1] 
DBamp = [sysd.B; 0]

Kid = acker(DAamp, DBamp, [exp(-5 * p0* T), exp(-5 * p0 * T), exp(-7*p0*T)])

warning("on")

AccionDirecta = 1; %Valor arbitrario
%Acciondirectafija = -(C*( (eye(2)-(sysd.A-sysd.B*Kid(1:2)))^-1 * sysd.B ) )^-1 
%AccionDirecta = Acciondirectafija; %Valor ajustado - Forzar Kid(3) = 0. 
consigna = 100;
InicioEstimador = 10;

%%Gráficas

s = sim('discreto.slx');


tp = s.yout{1}.Values.Time;
tv = s.yout{2}.Values.Time;

p = s.yout{1}.Values.Data;
v = s.yout{2}.Values.Data;

tpest = s.yout{4}.Values.Time;
tvest = s.yout{5}.Values.Time;

pest = s.yout{4}.Values.Data;
vest = s.yout{5}.Values.Data;

tu = s.yout{3}.Values.Time;
u = s.yout{3}.Values.Data;

subplot(3, 1, 1)
plot(tp, p); hold on; grid on;
plot(tpest, pest); hold off;
ylabel("p (º)")
xlabel("t (s)")
xlim([0 2])
legend("Posición del modelo", "Posición estimada")

subplot(3, 1, 2)
plot(tv, v); hold on; grid on;
plot(tvest, vest); hold off;
ylabel("v (º/s)")
xlabel("t (s)")
xlim([0 2])
legend("Velocidad del modelo", "Velocidad estimada")

subplot(3, 1, 3)
plot(tu, u); grid on;
ylabel("u (V)")
xlabel("t (s)")
legend("Entrada")
xlim([0 2])