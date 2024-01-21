close all;
p = 75.6862;
ke = 7.3343e+03;
A = [0 1; 0 -p]
B = [0; ke] %Solo controlo la velocidad
K = place(A, B, [-0.3*p, -0.4*p])

%u = 1 Vref
%Diseño del estimador
C = [1, 0];
L = place(A', C', [-1.2*p, -1.3*p])'

Aamp = [A zeros(2, 1); C 0]
Bamp = [B; 0]

Ki = acker(Aamp, Bamp, [-0.5*p, -0.5*p, -0.7*p])

InicioEstimador = -100;
AccionDirecta = 0;
consigna = 90;
s = sim('realimentado.slx');


ts = s.tout;

p = s.yout{1}.Values.Data;
v = s.yout{2}.Values.Data;

pest = s.yout{4}.Values.Data;
vest = s.yout{5}.Values.Data;

u = s.yout{3}.Values.Data;

subplot(3, 1, 1)
plot(ts, p); hold on; grid on;
plot(ts, pest); hold off;
ylabel("p (º)")
xlabel("t (s)")
xlim([0 0.5])
legend("Posición del modelo", "Posición estimada")

subplot(3, 1, 2)
plot(ts, v); hold on; grid on;
plot(ts, vest); hold off;
ylabel("v (º/s)")
xlabel("t (s)")
xlim([0 0.5])
legend("Velocidad del modelo", "Velocidad estimada")

subplot(3, 1, 3)
plot(ts, u); grid on;
ylabel("u (V)")
xlabel("t (s)")
legend("Entrada")
xlim([0 0.5])


