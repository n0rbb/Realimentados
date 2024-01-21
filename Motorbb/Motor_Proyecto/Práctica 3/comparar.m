clear all; close all; clf;
%Fijo ya los valores del motor
p0 = 75.6862;
ke0 = 7.3343e+03;
open('completo.slx')

V = [2, 5, 6, 9, 12];

for i = 1:length(V)
    i
    Vref = V(i);
    figure(i);
    s = sim('completo.slx');
    p = s.yout{3}.Values.Data;
    v = s.yout{4}.Values.Data;

    penc = s.yout{1}.Values.Data;
    venc = s.yout{2}.Values.Data;
    
    tp = s.yout{1}.Values.Time;
    tv = s.yout{2}.Values.Time;
   
    ts = s.tout;
    tt = sprintf("Medidas para V = %d V", Vref);
    title = tt;
    subplot(2, 1, 1)
    plot(tp, penc); hold on;
    plot(ts, p);
    hold off;
    legend("p directa (º)", "p encoders (º)", "Location", "southeast");
    subplot(2, 1, 2)
    plot(ts, v); hold on;
    plot(tv, venc); 
    hold off;
    legend("v directa (º/s)", "v encoders (º/s)", "Location", "southeast");
end 



%% Comparación con los datos del motor. 
close all;
dt1 = importdata("datos/motor01V.mat");
dt2 = importdata("datos/motor02V.mat");
dt3 = importdata("datos/motor03V.mat");
dt4 = importdata("datos/motor04V.mat");
dt5 = importdata("datos/motor05V.mat");
dt6 = importdata("datos/motor06V.mat");
dt7 = importdata("datos/motor07V.mat");
dt8 = importdata("datos/motor08V.mat");
dt9 = importdata("datos/motor09V.mat");
dt10 = importdata("datos/motor10V.mat");
dt11 = importdata("datos/motor11V.mat");
dt12 = importdata("datos/motor12V.mat");

dts = [dt2, dt5, dt6, dt9, dt12];
V = [2, 5, 6, 9, 12];
for i = 1 : length(V)

    Vref = V(i);
    s = sim('completo.slx');

    pm = get(dts(i), "Motor:1").Values.Data;
    vm = get(dts(i), "Motor:2").Values.Data;

    tp = get(dts(i), "Motor:1").Values.Time; 
    tv = get(dts(i), "Motor:2").Values.Time;
    tpenc = s.yout{1}.Values.Time;
    tvenc = s.yout{2}.Values.Time;
    penc = s.yout{1}.Values.Data;
    venc = s.yout{2}.Values.Data;

    figure(i)

    plot(tp, pm); hold on;
    plot(tv, vm);
    plot(tpenc, penc);
    plot(tvenc, venc);

    legend("Posición del motor (º)", "Velocidad del motor (º/s)", "Posición del modelo (º)", "Velocidad del modelo (º/s)", "Location", "Northwest");
    xlim([0 5])
    %tit = sprintf("Medida a %d V", Vref);
    %title(tit);
end