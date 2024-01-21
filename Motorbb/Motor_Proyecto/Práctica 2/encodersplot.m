close all; clf;
ecn = importdata("datos/encoders.mat");
ec1 = get(ecn, "Encoder A:1").Values.Data;
ec2 = get(ecn, "Encoder B:1").Values.Data;
tec1 = get(ecn, "Encoder A:1").Values.Time;
tec2 = get(ecn, "Encoder B:1").Values.Time;


plot(tec1, ec1(:)); hold on; grid on;
plot(tec2, ec2(:));
xlim([1.05 1.15])
ylim([-0.1 1.1])
legend("Encoder A", "Encoder B")
