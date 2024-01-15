%el modelo de voterra lotke se puede escribir como 
%dotx1=x1-x1*x2-mux1^2
%dotx2 = x1*x2 -x2 -taux2*dotx1
%encotrar puntos de equilibrio
%linelizar en torno aquel cuyas dos varibles de estado son distintas de
%cero y mostrar como la estabilidad e inestabilidad de dicho punto depende
%de mu y tau. discutir la posibilidad de la existencia de un ciclo límite

%creamos unas variables simbolicas 
syms x1 x2 s
%y unos parametros mu y tau tambien simbolicos
syms mu tau

%definimos las ecuaciones del sistema
f(1,1) = x1-x1*x2-mu*x1^2
f(2,1) = x1*x2 -x2 -tau* x2 * (x1-x1*x2-mu*x1^2)

%Calculamos el Jacobiano
J = jacobian(f,[x1 x2])
%obtenemos los puntos en que se anulan las ecuaciones de estado, ya que
%dichos puntos son precisamente los puntos de equilibrio
[x10,x20] = solve(f,[x1 x2])
X0 = [x10,x20]
%calculamos ahora resultados para todos los puntos de equilibrio
%encontrados

for i =1:size(X0,1)
    %sustituimos la solucion en la expresion del Jacobiano
    Je = subs(J,{x1,x2},X0(i,:))
    E = eig(Je)
    %calculamos el p carcateristico
    D = det(s*eye(length(X0(i,:))) - Je)
    D = collect(D,s)
    
end
%solo me interesa en realidas el segundo que es el que corresponde a las
%dos variables de estado distintas de cero.

%D = s^2 + (mu - tau + mu*tau)*s - mu + 1
%una vez que tengo el polinomio característico, puedo utilizar el criterio
%de Routh-Hurwitz, para determinar el signo de sus raíces
%https://ocw.uc3m.es/pluginfile.php/2517/mod_page/content/16/t10_estabilidad.pdf
%necesito que todos los coeficientes de de D sean positivos
%1-mu > 0, pero el propio mu que es una tasa de crecimiento, debería ser
%positivo luego 0 < mu < 1.
%en segundo lugar 
%mu-(1-mu)tau >0 , luego, mu > (1-mu)tau -> tau < mu/(1-mu)

mu = 0.5
tau = 0.5

%estable y convergente
for i =1:5%5
    for j = 1:5 %5
        [t,x] = ode45(@(t,x)volterra(t,x,mu,tau),[0 1000],[i;j]);
        plot(i,j,'xr')
        hold on
        plot(x(:,1),x(:,2))
        
    end
end
plot(0,0,'o')
plot(1/mu,0,'x')
plot(1, 1-mu,'^')

figure
%retorno a a Volterra puro
mu = 0.0
tau = 0.0
opts = odeset('Reltol',1e-9,'MaxStep',1e-1);
for i =1:5%5
    for j = 1:5 %5
        [t,x] = ode45(@(t,x)volterra(t,x,mu,tau),[0 1000],[i;j],opts);
        plot(i,j,'xr')
        hold on
        plot(x(:,1),x(:,2))
        
    end
end
plot(0,0,'o')
plot(1/mu,0,'x')
plot(1, 1-mu,'^')
[t,x] = ode45(@(t,x)volterra(t,x,mu,tau),[0 1000],[1.1;1.1],opts);
plot(x(:,1),x(:,2),'+')


%ciclo limite pinto solo un caso de dentro y otro de fuera
figure
mu = 0.1
tau = 0.2
x0=[6;3]
[t,x] = ode45(@(t,x)volterra(t,x,mu,tau),[0 1000],x0);
plot(x0(1),x0(2),'xr')
hold on
plot(x(:,1),x(:,2),'r')

x0=[1;3]
[t,x] = ode45(@(t,x)volterra(t,x,mu,tau),[0 1000],x0);
plot(x0(1),x0(2),'xb')
plot(x(:,1),x(:,2),'b')  
plot(0,0,'o')
plot(1/mu,0,'*')
plot(1, 1-mu,'^')




