import random

n = 5
v1 = [random.uniform(-10, 10) for _ in range(n)]
v2 = [random.uniform(-10, 10) for _ in range(n)]

print(v1)
print(v2)

v1, v2 = v2, v1

print(v1)
print(v2)
