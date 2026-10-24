#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cstdio>

struct TAngle {
    int degrees;
    double minutes;
};

void init(TAngle& a, int deg, double min) { a.degrees = deg; a.minutes = min; }
void input(TAngle& a) { std::cin >> a.degrees >> a.minutes; }
void output(TAngle a) { std::cout << a.degrees << "° " << a.minutes << "'\n"; }

char* toPChar(TAngle a) {
    char* buf = new char[64];
    std::sprintf(buf, "%d град %.2f хв", a.degrees, a.minutes);
    return buf;
}

double toTotalDegrees(TAngle a) { return a.degrees + (a.minutes / 60.0); }

void normalizeAngle(TAngle& a) {
    double total = std::fmod(toTotalDegrees(a), 360.0);
    if (total < 0) total += 360.0;
    int deg = static_cast<int>(total);
    a.degrees = deg;
    a.minutes = (total - deg) * 60.0;
}

double toRadians(TAngle a) { return toTotalDegrees(a) * (M_PI / 180.0); }

void addAngle(TAngle& a, int deg, double min) {
    a.degrees += deg;
    a.minutes += min;
    normalizeAngle(a);
}

void subtractAngle(TAngle& a, int deg, double min) { addAngle(a, -deg, -min); }
double getSin(TAngle a) { return std::sin(toRadians(a)); }

int compareAngles(TAngle a, TAngle b) {
    normalizeAngle(a);
    normalizeAngle(b);
    double diff = toTotalDegrees(a) - toTotalDegrees(b);
    if (std::fabs(diff) < 1e-7) return 0;
    return (diff > 0) ? 1 : -1;
}

int main() {
    TAngle a1, a2;

    init(a1, 370, 90.0);
    normalizeAngle(a1);

    char* s = toPChar(a1);
    std::cout << "Рядок (PChar): " << s << "\n";
    delete[] s;

    std::cout << "Радіани: " << toRadians(a1) << "\n";
    std::cout << "Синус: " << getSin(a1) << "\n";

    addAngle(a1, 15, 30.0);
    subtractAngle(a1, 10, 0.0);

    init(a2, 376, 0.0);
    normalizeAngle(a2);

    std::cout << "Порівняння: " << compareAngles(a1, a2) << "\n";

    std::cout << "Введіть кут (градуси хвилини): ";
    TAngle aUser;
    input(aUser);
    normalizeAngle(aUser);

    std::cout << "Кут на виході: ";
    output(aUser);
    std::cout << "Радіани: " << toRadians(aUser) << "\n";

    return 0;
}
