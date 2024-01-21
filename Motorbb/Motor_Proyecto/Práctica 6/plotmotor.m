close all;
clear all;
%Importo los datos medidos del motor
%Consigna de 180º
%Consigna de -240º

dtpos = importdata("datos/motor_real_control.mat");
dtneg = importdata("datos/motor_real_control_neg.mat");


p = get(dtpos, "Motor:1").Values.Data;
tp = get(dtpos, "Motor:1").Values.Time; 

pest = get(dtpos, "Sum:1(1)").Values.Data;
tpest = get(dtpos, "Sum:1(1)").Values.Time;

v = get(dtpos, "Motor:2").Values.Data;
tv = get(dtpos, "Motor:2").Values.Time; 

vest = get(dtpos, "Sum:1(2)").Values.Data;
tvest = get(dtpos, "Sum:1(2)").Values.Time;

u = get(dtpos, "Zero-Order Hold1:1").Values.Data;
tu = get(dtpos, "Zero-Order Hold1:1").Values.Time;

subplot(3, 1, 1)
plot(tp, p); hold on; grid on;
plot(tpest, pest); hold off;
ylabel("p (º)")
xlabel("t (s)")
xlim([0 1])
legend("Posición del modelo", "Posición estimada")

subplot(3, 1, 2)
plot(tv, v); hold on; grid on;
plot(tvest, vest); hold off;
ylabel("v (º/s)")
xlabel("t (s)")
xlim([0 1])
legend("Velocidad del modelo", "Velocidad estimada")

subplot(3, 1, 3)
plot(tu, u); grid on;
ylabel("u (V)")
xlabel("t (s)")
legend("Entrada")
xlim([0 1])


