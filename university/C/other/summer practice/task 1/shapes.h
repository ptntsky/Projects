#include <math.h>

#define PI 3.14159265

// Об'єм куба або призми
double box(double a, double b, double c) {
    return a * b * c;
}

// Об'єм циліндра
double cylinder(double r, double h) {
    return PI * r * r * h;
}

// Об'єм кулі
double sphere(double r) {
    return (4.0 / 3.0) * PI * r * r * r;
}

// Об'єм конуса
double cone(double r, double h) {
    return (1.0 / 3.0) * PI * r * r * h;
}

// Об'єм піраміди з прямокутною основою
double pyramid(double a, double b, double h) {
    return (1.0 / 3.0) * a * b * h;
}
