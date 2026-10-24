#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cstdio>

struct TAngle {
    int degrees;
    double minutes;
};

class AngleClass {
private:
    TAngle data;
public:
    void init(int deg, double min);
    void input();
    void output();
    char* toPChar();

    TAngle getStruct() { return data; }
    void setStruct(TAngle s) { data = s; }
    int getDegrees() { return data.degrees; }
    void setDegrees(int deg) { data.degrees = deg; }
    double getMinutes() { return data.minutes; }
    void setMinutes(double min) { data.minutes = min; }
};

void AngleClass::init(int deg, double min) { data.degrees = deg; data.minutes = min; }
void AngleClass::input() { std::cin >> data.degrees >> data.minutes; }
void AngleClass::output() { std::cout << data.degrees << "° " << data.minutes << "'"; }

char* AngleClass::toPChar() {
    char* buf = new char[64];
    std::sprintf(buf, "%d deg %.2f min", data.degrees, data.minutes);
    return buf;
}

double toTotalDegrees(AngleClass a) {
    return a.getDegrees() + (a.getMinutes() / 60.0);
}

void normalizeAngle(AngleClass& a) {
    double total = std::fmod(toTotalDegrees(a), 360.0);
    if (total < 0) total += 360.0;
    int deg = static_cast<int>(total);
    a.setDegrees(deg);
    a.setMinutes((total - deg) * 60.0);
}

double toRadians(AngleClass a) {
    return toTotalDegrees(a) * (M_PI / 180.0);
}

void addAngle(AngleClass& a, int deg, double min) {
    a.setDegrees(a.getDegrees() + deg);
    a.setMinutes(a.getMinutes() + min);
    normalizeAngle(a);
}

void subtractAngle(AngleClass& a, int deg, double min) {
    addAngle(a, -deg, -min);
}

double getSin(AngleClass a) {
    return std::sin(toRadians(a));
}

int compareAngles(AngleClass a, AngleClass b) {
    normalizeAngle(a);
    normalizeAngle(b);
    double diff = toTotalDegrees(a) - toTotalDegrees(b);
    if (std::fabs(diff) < 1e-7) return 0;
    return (diff > 0) ? 1 : -1;
}

int main() {
    std::setlocale(LC_ALL, "");

    AngleClass a1, a2;

    a1.init(370, 90.0);
    normalizeAngle(a1);

    char* s = a1.toPChar();
    std::cout << s << " | rad: " << toRadians(a1) << " | sin: " << getSin(a1) << std::endl;
    delete[] s;

    addAngle(a1, 15, 30.0);
    subtractAngle(a1, 10, 0.0);

    a2.init(376, 0.0);
    normalizeAngle(a2);

    std::cout << "CMP: " << compareAngles(a1, a2) << std::endl;

    
    AngleClass aUser;
    std::cout << "Введіть градуси і мінути : ";
    aUser.input();       
    normalizeAngle(aUser);  
    
    std::cout << "Введений кут: ";
    aUser.output();        
    std::cout << "\nРадіани вашого кута: " << toRadians(aUser) << std::endl;

    return 0;
}

