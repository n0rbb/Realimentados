clear all; close all;
syms x1 x2 real
f(1, 1) = x2 + 2*x1^2 + x1*x2;
f(2, 1) = -x1 - x2 + x1*x2 + 3*x2^2;
f

V = 3*x1^2/2 + x1*x2 + 3*x2^2

[peq.x1, peq.x2] = solve(f)
peq = [peq.x1'; peq.x2'] %puntos de equilibrio

%Linealizar en torno a puntos de equilibrio
J = jacobian(f)
E = eig(J)


for i = 1:2
    je = subs(J, {x1, x2}, {peq(1,i), peq(2,i)})
end


dlie = simplify(gradient(V)'*f)
[x, y] = meshgrid(-2:0.1:2);
mesh(x, y, subs(dlie, {x1, x2}, {x, y})); hold on;
contour3(x, y, subs(dlie, {x1, x2}, {x, y}), '-k', 'LineWidth', 1.5)
%mesh(x, y, zeros(size(x)), "FaceColor","flat")