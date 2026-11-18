#include "Line.h"
#include <cmath>

int Line::count = 0;

// ---------- Конструктори ----------
Line::Line() : A(1), B(0), C(0) {
    ++count;
    cout << "[конструктор за замовчуванням] x = 0" << endl;
}

Line::Line(double a, double b, double c) : A(a), B(b), C(c) {
    if (A == 0 && B == 0) {
        cout << "[УВАГА] A=B=0 — некоректна пряма, коригуємо на x=0" << endl;
        A = 1;
    }
    ++count;
    cout << "[конструктор з параметрами]" << endl;
}

Line::Line(const Line& other) : A(other.A), B(other.B), C(other.C) {
    ++count;
    cout << "[конструктор копіювання]" << endl;
}

Line::Line(Line&& other) noexcept : A(other.A), B(other.B), C(other.C) {
    other.A = 1; other.B = 0; other.C = 0;
    ++count;
    cout << "[конструктор переміщення]" << endl;
}

// Делегуючий: y = kx + b  ->  kx - y + b = 0
Line::Line(double k, double b) : Line(k, -1.0, b) {
    cout << "[делегуючий конструктор y = kx + b]" << endl;
}

Line::~Line() {
    --count;
    cout << "[деструктор]" << endl;
}

// ---------- Присвоєння ----------
Line& Line::operator=(const Line& other) {
    cout << "[оператор присвоєння копіюванням]" << endl;
    if (this != &other) {
        A = other.A; B = other.B; C = other.C;
    }
    return *this;
}

Line& Line::operator=(Line&& other) noexcept {
    cout << "[оператор присвоєння переміщенням]" << endl;
    if (this != &other) {
        A = other.A; B = other.B; C = other.C;
        other.A = 1; other.B = 0; other.C = 0;
    }
    return *this;
}

// ---------- Введення / виведення ----------
ostream& operator<<(ostream& os, const Line& l) {
    os << l.A << "x ";
    os << (l.B >= 0 ? "+ " : "- ") << fabs(l.B) << "y ";
    os << (l.C >= 0 ? "+ " : "- ") << fabs(l.C) << " = 0";
    return os;
}

istream& operator>>(istream& is, Line& l) {
    cout << "Введіть A, B, C: ";
    is >> l.A >> l.B >> l.C;
    if (l.A == 0 && l.B == 0) { l.A = 1; }
    return is;
}

// ---------- Оператори ----------
double Line::operator^(const Line& other) const {
    double num = fabs(A * other.A + B * other.B);
    double den = sqrt(A*A + B*B) * sqrt(other.A*other.A + other.B*other.B);
    if (den == 0) return 0;
    double c = num / den;
    if (c > 1.0) c = 1.0;
    return acos(c);            // радіани
}

double Line::operator||(const Line& other) const {
    // відстань між паралельними прямими: |C1/k1 - C2/k2| або через нормаль
    if (!isParallelTo(other)) {
        cout << "[увага] прямі не паралельні — відстань не визначена, повертаємо -1" << endl;
        return -1;
    }
    // нормалізуємо коефіцієнти так, щоб A,B співпадали
    double k = 1.0;
    if (fabs(A) > 1e-12) k = other.A / A;
    else if (fabs(B) > 1e-12) k = other.B / B;
    double c1 = C * k;
    double c2 = other.C;
    double den = sqrt(other.A*other.A + other.B*other.B);
    if (den == 0) return -1;
    return fabs(c2 - c1) / den;
}

bool Line::operator==(const Line& other) const {
    // A1/A2 == B1/B2 == C1/C2 (пропорційні)
    return fabs(A*other.B - B*other.A) < 1e-9 &&
           fabs(A*other.C - C*other.A) < 1e-9 &&
           fabs(B*other.C - C*other.B) < 1e-9;
}

bool Line::operator!=(const Line& other) const {
    return !(*this == other);
}

// ---------- Функції-члени ----------
void Line::print() const {
    cout << "Пряма: " << *this << endl;
}

bool Line::containsPoint(double x, double y) const {
    return fabs(A*x + B*y + C) < 1e-9;
}

bool Line::getNormalForm(double& cosAlpha, double& sinAlpha, double& p) const {
    double d = sqrt(A*A + B*B);
    if (d == 0) return false;
    double sign = (C > 0) ? -1.0 : 1.0;   // обираємо так, щоб p >= 0
    cosAlpha = sign * A / d;
    sinAlpha = sign * B / d;
    p = -sign * C / d;
    if (p < 0) p = -p;
    return true;
}

bool Line::isParallelToOx() const { return fabs(B) < 1e-9; }
bool Line::isParallelToOy() const { return fabs(A) < 1e-9; }

bool Line::isParallelTo(const Line& other) const {
    return fabs(A*other.B - B*other.A) < 1e-9;
}

bool Line::isPerpendicularTo(const Line& other) const {
    return fabs(A*other.A + B*other.B) < 1e-9;
}

// ---------- Дружні функції ----------
bool intersection(const Line& l1, const Line& l2, double& x, double& y) {
    double det = l1.A * l2.B - l2.A * l1.B;
    if (fabs(det) < 1e-9) return false;     // паралельні / співпадають
    x = (l1.B * l2.C - l2.B * l1.C) / det;
    y = (l1.C * l2.A - l2.C * l1.A) / det;
    return true;
}

double distancePointToLine(const Line& l, double x0, double y0) {
    double den = sqrt(l.A*l.A + l.B*l.B);
    if (den == 0) return -1;
    return fabs(l.A*x0 + l.B*y0 + l.C) / den;
}
