dt = [data, data2, data3, data4, data5, data6, data7, data8, data9, data10, data11, data12];
p = [];
ke = [];
for i = 1:12
    m = get(dt(i), "Motor:1").Values.Data;
    t = get(dt(i), "Motor:1").Values.Time;
    a = find(m); %Encontrar los valores no cero de la posición.
    pol = polyfit(t(a + 100:end), m(a + 100:end), 1);
    p(i) = -pol(1)/pol(2);
    ke(i) = pol(1)*p(i) / i;
    %figure(i)
    %plot(t, m)
end

p
ke

