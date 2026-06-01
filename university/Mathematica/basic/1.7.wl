a = 0.25;
b = 2.25;
h = 0.2;
f[x_]:= Exp[-2x] + x^2 -1;
Module[{t}, 
  t = Table[{x, f[x]}, {x, a, b, h}];
  ListLinePlot[t, PlotMarkers -> Automatic]
]
