
import random

t1 = tuple(int(random.random() * 6) for _ in range(10))
t2 = tuple(int(random.random() * 6) - 5 for _ in range(10))
t3 = t1 + t2
zeros = t3.count(0)

print(t3)
print(zeros)
