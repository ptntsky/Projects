import math
a=1
b=12.21

t1=0.81*math.cbrt(a)
t2=(1/2.125)*math.cbrt(b)
y=(t1-t2)*math.exp(a)

print(f"y={y:.6f}")
