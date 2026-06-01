syms x y z
eqn1 = x + y + 2*z + 1 == 0;
eqn2 = 2*x - y + 2*z + 4 == 0;
eqn3 = 4*x + y + 4*z + 2 == 0;
sol = solve([eqn1, eqn2, eqn3], [x, y, z]);
disp(sol);
