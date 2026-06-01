Clear[f, x, a]
f = x*Exp[-a*x]
NIntegrate[f /. a -> 13, {x, -3, -1}]
