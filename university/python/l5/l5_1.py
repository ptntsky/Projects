nums = list(map(int, input('Числа через пробіл: ').split()))
prime = lambda n: n > 1 and all(n % i for i in range(2, int(n ** .5) + 1))
print({n % 2 for n in nums if not prime(n)} <= {0})

