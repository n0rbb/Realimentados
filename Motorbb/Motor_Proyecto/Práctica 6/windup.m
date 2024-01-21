%Es necesario haber ejecutado antes discretizar.m (práctica 5)

kamp = 1;
consigna = 100;
InicioEstimador = 10;
AccionDirecta = 0;
%%Gráficas

s = sim('antiwindup.slx');


tp = s.yout{1}.Values.Time;
tv = s.yout{2}.Values.Time;

p = s.yout{1}.Values.Data;
v = s.yout{2}.Values.Data;

tpest = s.yout{3}.Values.Time;
tvest = s.yout{4}.Values.Time;

pest = s.yout{3}.Values.Data;
vest = s.yout{4}.Values.Data;

tu = s.yout{5}.Values.Time;
u = s.yout{5}.Values.Data;

subplot(3, 1, 1)
plot(tp, p); hold on; grid on;
plot(tpest, pest); hold off;
ylabel("p (º)")
xlabel("t (s)")
xlim([0 0.5])
legend("Posición del modelo", "Posición estimada")

subplot(3, 1, 2)
plot(tv, v); hold on; grid on;
plot(tvest, vest); hold off;
ylabel("v (º/s)")
xlabel("t (s)")
xlim([0 0.5])
legend("Velocidad del modelo", "Velocidad estimada")

subplot(3, 1, 3)
plot(tu, u); grid on;
ylabel("u (V)")
xlabel("t (s)")
legend("Entrada")
xlim([0 0.5])