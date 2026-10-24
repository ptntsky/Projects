import random

n, m = 3, 4
mat = [[random.randint(1, 10) for _ in range(m)] for _ in range(n)]
trans = [[mat[j][i] for j in range(n)] for i in range(m)]

for row in mat:
  print(row)

print()

for row in trans:
  print(row)
  
