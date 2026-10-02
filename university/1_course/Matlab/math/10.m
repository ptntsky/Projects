x = linspace(-2, 2, 400); 

y1 = x.^2 + abs(x) - 2;
y2 = exp(x) ./ x;           
y3 = x.^3 + 3*x;
y4 = 1 ./ (nthroot((1 - x.^2).^2, 3));

% В чотирьох різних вікнах
figure; plot(x, y1); title('Функція 1: y = x^2 + |x| - 2'); grid on;
figure; plot(x, y2); title('Функція 2: y = e^x / x'); grid on;
figure; plot(x, y3); title('Функція 3: y = x^3 + 3x'); grid on;
figure; plot(x, y4); title('Функція 4: y = 1 / cbrt((1-x^2)^2)'); grid on;

% В одному вікні
figure;
plot(x, y1, 'r', 'LineWidth', 1.5); hold on;
plot(x, y2, 'g', 'LineWidth', 1.5);
plot(x, y3, 'b', 'LineWidth', 1.5);
plot(x, y4, 'm', 'LineWidth', 1.5);
title('Усі функції в одному вікні');
legend('y1', 'y2', 'y3', 'y4');
ylim([-10 10]);
grid on;
hold off;

% В одному вікні, розбитому на 4 підвікна
figure;
subplot(2, 2, 1); plot(x, y1); title('y1'); grid on;
subplot(2, 2, 2); plot(x, y2); title('y2'); ylim([-10 10]); grid on;
subplot(2, 2, 3); plot(x, y3); title('y3'); grid on;
subplot(2, 2, 4); plot(x, y4); title('y4'); ylim([0 10]); grid on;
