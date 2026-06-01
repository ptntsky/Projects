Clear[f,df,x,a]
f=x*Exp[-a*x]
df=D[f,x]
df/.x->-3
df/.x->-1
