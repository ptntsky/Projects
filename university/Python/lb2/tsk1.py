import math

def calculate_sum(x: float, a: float, eps: float, max_iter: int = 1000):
    total_sum = 0.0
    k = 0
    count = 0

    while k < max_iter:
        numerator = math.cos(a**k + x**k)
        denominator = math.factorial(k**2)
        
        term = numerator / denominator
        
        # Добавляем слагаемое к общей сумме
        total_sum += term
        count += 1
        
        # Если модуль слагаемого меньше заданной точности, останавливаем вычисление
        if abs(term) < eps:
            break
            
        k += 1

    return total_sum, count

def main():
    print("Обчислення суми ряду (Варіант 8)")
    try:
        x = float(input("Введіть x (x ≠ 0): "))
        a = float(input("Введіть a (a ≠ 0): "))
        eps = float(input("Введіть точність eps (eps > 0): "))
        
        if x == 0 or a == 0 or eps <= 0:
            print("Помилка: перевірте обмеження (x ≠ 0, a ≠ 0, eps > 0).")
            return
            
        result, n_terms = calculate_sum(x, a, eps)
        
        print(f"\nСума ряду: {result:.10f}")
        print(f"Кількість врахованих доданків: {n_terms}")
        
    except ValueError:
        print("Помилка: введено некоректні числові дані.")

if __name__ == "__main__":
    main()
