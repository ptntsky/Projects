import math

def find_sequence_element(x, eps, max_n=100):
    a_prev = 1
    
    for n in range(1, max_n + 1):
        multiplier = 1 - (((-1) ** n) * x) / math.factorial(n + 1)
        a_curr = a_prev * multiplier
        
        if abs(a_curr - a_prev) < eps:
            return n, a_curr
            
        a_prev = a_curr
        
    return None, None

x = float(input("Введіть x: "))
eps = float(input("Введіть точність eps: "))

n, a_n = find_sequence_element(x, eps)

if n is not None:
    print(f"n: {n}")
    print(f"a_n: {a_n}")
else:
    print("Умову не досягнуто за перші 100 членів")
