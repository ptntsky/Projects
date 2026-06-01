% Приклад введення функції: @(x) (x.^2 + 1) ./ (x.^4 + 1)
func_str = input('Введіть функцію: ', 's');
f = str2func(func_str);

a = input('Введіть нижню межу (a): ');
b = input('Введіть верхню межу (b): ');

% 2. для n = 20
n1 = 20;
x1 = linspace(a, b, n1);
y1 = f(x1);
res20 = trapz(x1, y1);

% 3. для n = 50
n2 = 50;
x2 = linspace(a, b, n2);
y2 = f(x2);
res50 = trapz(x2, y2);

exact = integral(f, a, b);

fprintf('Точне значення (integral): %.6f\n', exact);
fprintf('Метод трапецій (n = 20):   %.6f\n', res20);
fprintf('Метод трапецій (n = 50):   %.6f\n', res50);
fprintf('Різниця (похибка для n=50): %.6e\n', abs(exact - res50));
