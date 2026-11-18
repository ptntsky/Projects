#ifndef LINE_H
#define LINE_H

#include <iostream>
using namespace std;

class Line {
private:
    double A, B, C;               // загальне рівняння Ax + By + C = 0
    static int count;             // статичний лічильник об'єктів

public:
    // ---------- Конструктори / деструктор / присвоєння ----------
    Line();                                   // за замовчуванням
    Line(double a, double b, double c);       // з параметрами
    Line(const Line& other);                  // копіювання
    Line(Line&& other) noexcept;              // переміщення
    Line(double k, double b);                 // делегуючий: y = kx + b -> kx - y + b = 0
    ~Line();                                  // деструктор

    Line& operator=(const Line& other);       // присвоєння копіюванням
    Line& operator=(Line&& other) noexcept;   // присвоєння переміщенням

    // ---------- Гетери ----------
    double getA() const { return A; }
    double getB() const { return B; }
    double getC() const { return C; }
    static int getCount() { return count; }

    // ---------- Введення / виведення ----------
    friend ostream& operator<<(ostream& os, const Line& l);
    friend istream& operator>>(istream& is, Line& l);

    // ---------- Перевантажені оператори ----------
    double operator^(const Line& other) const;      // кут між прямими (радіани)
    double operator||(const Line& other) const;     // відстань між паралельними прямими
    bool   operator==(const Line& other) const;     // рівність прямих
    bool   operator!=(const Line& other) const;     // нерівність

    // ---------- Функції-члени ----------
    void print() const;                                  // друк інформації
    bool containsPoint(double x, double y) const;        // чи належить точка прямій
    bool getNormalForm(double& cosAlpha, double& sinAlpha, double& p) const; // нормальне рівняння
    bool isParallelToOx() const;                         // паралельна осі Ox
    bool isParallelToOy() const;                         // паралельна осі Oy
    bool isParallelTo(const Line& other) const;          // паралельність двох прямих
    bool isPerpendicularTo(const Line& other) const;     // перпендикулярність двох прямих

    // ---------- Дружні функції ----------
    friend bool intersection(const Line& l1, const Line& l2,
                             double& x, double& y);      // точка перетину
    friend double distancePointToLine(const Line& l, double x0, double y0); // відстань від точки до прямої
};

#endif
