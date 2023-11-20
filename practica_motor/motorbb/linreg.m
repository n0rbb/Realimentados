%Joder macho que hay que importar los datos manualmente 

close all;
A = zeros(3, 6);
v = [v1, v3, v5, v7, v9, v11];

for i = 1:6
    data = v(i);
    p = get(data, "Motor:1");
    %v = get(data, "Motor:2"); Solo vamos a necesitar la posición

    t = p.Values.Time(p.Values.Time(:, 1) > 1,  :);
    pos = p.Values.Data(length(p.Values.Data) - length(t) + 1:length(p.Values.Data));
    figure();
    plot(t - 1, pos); hold on;
    
    FP = polyfit(t, pos, 1);
    A(1, i) = -FP(1)/(FP(2));
    A(2, i) = FP(1) * A(1, i) / (2*i - 1);
    A(3, i) = -FP(2) * A(1, i)^2 / (2*i - 1); %Sale bastante igual

    plot(0.01:0.01:4, (A(1, i) + A(2, i)) * (2*i - 1) .* [0.01:0.01:4], "r:"); hold off;
end

A

