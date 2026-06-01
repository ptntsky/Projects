mat = {{1,2,3},{4,5,6},{7,8,9}};
k = 5;
pos = Position[mat,k]
If[pos != {},
  r = pos[[1,1]];
  c = pos[[1,2]];
  result = Drop[Map[Drop[#, {c}]&, mat], {r}],
  "Елемент не знайдено"]
    MatrixForm[result]


(* Функція для підсумовування підматриці *)
SumMatrixRange[matrix_, n1_, n2_, k1_, k2_] := Module[{subMatrix},
  (* Виділяємо потрібну частину матриці (підматрицю) *)
  subMatrix = matrix[[n1 ;; n2, k1 ;; k2]];
  
  (* Повертаємо суму всіх елементів цієї підматриці *)
  Total[subMatrix, 2]
]

(* Приклад використання *)
(* Створимо матрицю 5x5 для тесту *)
testMatrix = Table[i*10 + j, {i, 1, 5}, {j, 1, 5}];

(* Визначимо межі (наприклад, рядки 2-4, стовпчики 3-5) *)
{n1, n2} = {2, 4};
{k1, k2} = {3, 5};

(* Виклик функції *)
result = SumMatrixRange[testMatrix, n1, n2, k1, k2];

(* Вивід результатів *)
Print["Початкова матриця:"];
Print[MatrixForm[testMatrix]];
Print["Сума елементів у діапазоні рядків ", n1, "-", n2, 
      " та стовпчиків ", k1, "-", k2, " дорівнює: ", result];
