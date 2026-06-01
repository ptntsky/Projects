 syms x y

eq1 = sin(x + 0.5) - y == 1;
eq2 = cos(y - 2) + x == 0;

sol = solve([eq1, eq2], [x, y]);

x_val = double(sol.x);
y_val = double(sol.y);

fprintf('Розв''язок:\nx = %.4f\ny = %.4f\n', x_val, y_val);
