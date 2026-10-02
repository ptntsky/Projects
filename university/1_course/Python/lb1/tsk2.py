x = float(input("x: "))
y = float(input("y: "))
z = float(input("z: "))

#Спосіб 1
if x > y:
    m = x
else:
    m = y
s = x + y
if z <= m and z <= s:
    f1 = z
elif m <= z and m <= s:
    f1 = m
else:
    f1 = s

#Спосіб 2
f2=min(z,max(x,y),x+y)

print("if/else:",f1)
print("min/max:",f2)
