import random

lst = [random.randint(1, 20) for _ in range(10)]
res = [x**2 for x in lst if x % 2 != 0]

print(lst)
print(res)
