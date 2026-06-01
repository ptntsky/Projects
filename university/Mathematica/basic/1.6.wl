x1 = 0.4;
x2 = 4;
m = 50;
r = 4;
h = Abs[x1-x2]/(m-1);
fexact[x_] := Log[1 + x]
fapprox[x_] := Sum[(-1)^(k-1) * x^k / k, {k, 1,r}]; 
t = Table[{x, Abs[fexact[x] - fapprox[x]]}, {x, x1, x2, h}];
ListLinePlot[t,PlotStyle->Thick,PlotMarkers->Automatic]
TableForm[t, TableHeadings->{None,{"x", "Похибка"}}]
