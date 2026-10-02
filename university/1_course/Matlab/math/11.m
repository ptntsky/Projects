a_vec = linspace(-pi, pi, 50);      % альфа від -pi до pi
b_vec = linspace(-pi/2, pi/2, 50);  % бета від -pi/2 до pi/2

[alpha, beta] = meshgrid(a_vec, b_vec);

X = cos(alpha) .* cos(beta);
Y = sin(alpha) .* cos(beta);
Z = sin(beta);

% Будуємо поверхню
figure;
mesh(X, Y, Z); % Малює "сітчасту" поверхню

title('Параметрична поверхня: Сфера');
xlabel('Вісь X');
ylabel('Вісь Y');
zlabel('Вісь Z');
axis equal; % Щоб сфера не була сплюснутою, а виглядала як куля
grid on;
