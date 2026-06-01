syms x
f = (sqrt(x) - 1)^3 / x;
res = int(f, x);
pretty(res)
