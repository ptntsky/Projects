#include "Line.h"
#include <cmath>

int main() {
    cout << "=== АНАЛІЗ ПРЯМИХ НА ПЛОЩИНІ ===" << endl;

    // Створення об'єктів (конструктори)
    Line l1;                             
    Line l2(1, -2, 3);                   
    Line l3(l2);                         
    Line l4(2.0, 5.0);                   
    Line l5(static_cast<Line&&>(Line(1, 1, 1)));  

    cout << "\n--- Поточні прямі ---" << endl;
    cout << "Пряма 1: " << l1 << endl;
    cout << "Пряма 2: " << l2 << endl;
    cout << "Пряма 3 (копія 2): " << l3 << endl;
    cout << "Пряма 4: " << l4 << endl;
    cout << "Пряма 5: " << l5 << endl;

    // Тестування присвоєння
    Line l6;
    l6 = l2;                             
    cout << "\nПряма 6 (створена з Прямої 2): " << l6 << endl;
    l6 = Line(3, 4, -7);                 
    cout << "Пряма 6 (оновлена): " << l6 << endl;

    cout << "\nВсього активних об'єктів у пам'яті: " << Line::getCount() << "\n" << endl;

    // --- Функції-члени та дружні функції ---
    cout << "--- Аналіз Прямої 2 ---" << endl;
    l2.print();
    cout << "Чи належить точка (1, 2) цій прямій? " << (l2.containsPoint(1, 2) ? "Так" : "Ні") << endl;

    double ca, sa, p;
    if (l2.getNormalForm(ca, sa, p))
        cout << "Нормальне рівняння: x*(" << ca << ") + y*(" << sa << ") = " << p << endl;

    cout << "Чи паралельна вісі Ox? " << (l2.isParallelToOx() ? "Так" : "Ні") << endl;
    cout << "Чи паралельна вісі Oy? " << (l2.isParallelToOy() ? "Так" : "Ні") << endl;

    cout << "\n--- Взаємодія кількох прямих ---" << endl;
    Line lA(2, -1, 4);
    Line lB(4, -2, -6);
    Line lC(1, 2, 0);
    
    cout << "Пряма А: " << lA << " та Пряма B: " << lB << " паралельні? " << (lA.isParallelTo(lB) ? "Так" : "Ні") << endl;
    cout << "Пряма А та Пряма C: " << lC << " перпендикулярні? " << (lA.isPerpendicularTo(lC) ? "Так" : "Ні") << endl;

    double x, y;
    if (intersection(lA, lC, x, y))
        cout << "Точка перетину Прямої А та Прямої C: (" << x << ", " << y << ")" << endl;
    else
        cout << "Пряма А та Пряма C не перетинаються" << endl;

    cout << "Відстань від точки (1,1) до Прямої А: " << distancePointToLine(lA, 1, 1) << endl;


    // --- Перевантажені оператори ---
    cout << "\n--- Операції з прямими ---" << endl;
    Line lP(1, 1, 0);                    // x + y = 0
    Line lQ(1, -1, 0);                   // x - y = 0
    Line lP2(1, 1, -5);                  // паралельна lP
    Line lPcopy(2, 2, 0);                // пропорційна lP

    cout << "Кут між Прямою P та Q: " << (lP ^ lQ) << " рад (або " << (lP ^ lQ) * 180.0 / M_PI << " градусів)" << endl;
    cout << "Відстань між Прямою P та P2: " << (lP || lP2) << endl;
    cout << "Пряма P дорівнює своїй копії? " << (lP == lPcopy ? "Так" : "Ні") << endl;
    cout << "Пряма P не дорівнює Прямій Q? " << (lP != lQ ? "Так" : "Ні") << endl;

    cout << "\n--- Введення власних даних ---" << endl;
    Line lIn;
    cin >> lIn;
    cout << "Ви створили пряму: " << lIn << endl;

    cout << "\nРоботу завершено." << endl;
    return 0;
}
