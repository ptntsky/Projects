syms x

f = (x^2 + 1) / (x^4 + 1);
result = int(f, x, 0, inf);

disp('Результат інтеграла:');
disp(result);

disp('Чисельне значення:');
disp(double(result));
disp('Значення pi/sqrt(2):');
disp(double(pi/sqrt(2)));
