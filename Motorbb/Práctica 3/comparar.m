motor2 = importdata("datos/motor02V.mat")
mreal2 = importdata("datos/mreal_2V.mat")
motor5 = importdata("datos/motor05V.mat")
mreal5 = importdata("datos/mreal_5V.mat")
motor10 = importdata("datos/motor10V.mat")
mreal10 = importdata("datos/mreal_10V.mat")

t = get(motor2, "Motor:1").Values.Time; 
figure(1)
title("5V")
motor = get(motor2, "Motor:2").Values.Data;

