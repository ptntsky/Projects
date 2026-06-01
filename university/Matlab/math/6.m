syms x

y = 3*x^7 - 6*x^5 - 4*x^2 + 17;

dy = diff(y, x);

disp('похідна y'':');
pretty(dy)
