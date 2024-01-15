close all; clear all;

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

%Defino una lista con todos los datasets sobre la que voy a iterar para
%sacar los datos
dt = [dt1, dt2, dt3, dt4, dt5, dt6, dt7, dt8, dt9, dt10, dt11, dt12];
p = [];
ke = [];


for i = 1:12
    m = get(dt(i), "Motor:1").Values.Data;
    t = get(dt(i), "Motor:1").Values.Time; 
    %Para hacer la estimación, voy a empezar a contar justo antes de que los datos de posición
    %cambien de 0. Como los datos a 6 y 10 V marcan 1 desde el principio,
    %resto 1 a la posición para que la búsqueda luego funcione bien. 
    if i == 6 || i == 10
        m(2:end) = m(2:end) - 1;
    end
    
    %Encontrar los valores no cero de la posición y empezar a contar justo
    %antes (la menor desviación se obtiene al contar 6 posiciones antes)
    a = find(m); 
    %st = [a(1) + 10, a(1) - 8, a(1) - 6, a(1) - 6, a(1) - 6, a(1) - 6,  a(1) - 6, a(1) - 6, a(1) - 6, a(1) - 6 a(1) - 3, a(1) - 3]
    st = a(1) - 5
    mprima = m(st:end);

    %Hago el fit con los datos recortados y traslado los tiempos para que
    %vayan de 0 a X
    pol = polyfit(t(1:length(mprima)), mprima,  1);

    %Estimo los parámetros para este voltaje y los guardo en una lista
    ke(i) = -pol(1)^2 / (pol(2) * i);
    p(i) = (ke(i) * i)/pol(1);
    
    
    %figure(i)
    %plot(t, m); hold on;
    %plot(t, polyval(pol, t))
end

%Imprimo las listas de valores y las medias
p
ke
p0 = mean(p)
ke0 = mean(ke)





