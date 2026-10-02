A = [1 2 -1; 
     3 4 1; 
     5 1 -3];

B = [-3; 1; -2];

Delta = det(A);

Ax = A; Ax(:, 1) = B;
Ay = A; Ay(:, 2) = B;
Az = A; Az(:, 3) = B;

Delta_x = det(Ax);
Delta_y = det(Ay);
Delta_z = det(Az);

x = Delta_x / Delta;
y = Delta_y / Delta;
z = Delta_z / Delta;

fprintf('x = %.2f\ny = %.2f\nz = %.2f\n', x, y, z);
