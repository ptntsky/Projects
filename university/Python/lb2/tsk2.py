import math

def task_2_variant_24():
    x = float(input("Введіть дійсне x: "))
    eps = float(input("Введіть точність eps (>0): "))
    
    max_n = 100
    a_prev = 1.0  # a_0 = 1 для формування добутку
    found = False
    
    for n in range(1, max_n + 1):
        # Наступний співмножник: 1 - ((-1)^n * x) / (n + 1)!
        multiplier = 1.0 - (((-1) ** n) * x) / math.factorial(n + 1)
        a_curr = a_prev * multiplier
        
        # Перевірка умови збіжності
        if abs(a_curr - a_prev) < eps:
            print(f"Знайдено член послідовності:")
            print(f"Номер n: {n}")
            print(f"Значення a_n: {a_curr}")
            print(f"Різниця |a_n - a_{{n-1}}|: {abs(a_curr - a_prev)}")
            found = True
            break
            
        a_prev = a_curr
        
    if not found:
        print(f"Серед перших {max_n} членів послідовності умову |a_n - a_(n-1)| < eps не досягнуто.")

if __name__ == "__main__":
    task_2_variant_24()
