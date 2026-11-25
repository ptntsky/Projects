#include <iostream>
using namespace std;

class Seans {
private:
    int num;
    int start;
    int end;

public:
    Seans();
    Seans(int n, int s, int e);
    ~Seans();

    void input();
    friend ostream& operator<<(ostream& out, const Seans& x);

    bool operator<(const Seans& x) const;
    friend bool operator%(const Seans& x, int k);

    void setNum(int n);
    friend double pct(const Seans& x);
};

Seans::Seans() {
    num = 0;
    start = 0;
    end = 0;
}

Seans::Seans(int n, int s, int e) {
    num = n;
    start = s;
    end = e;
}

Seans::~Seans() {}

void Seans::input() {
    cin >> num >> start >> end;
}

ostream& operator<<(ostream& out, const Seans& x) {
    out << x.num << " " << x.start << " " << x.end;
    return out;
}

bool Seans::operator<(const Seans& x) const {
    return (start - end) < (x.start - x.end);
}

bool operator%(const Seans& x, int k) {
    if (k == 0) return false;
    return x.num % k == 0;
}

void Seans::setNum(int n) {
    num = n;
}

double pct(const Seans& x) {
    if (x.start <= 0) return 0.0;
    return (double)(x.start - x.end) / x.start * 100.0;
}

int main() {
    Seans a;
    Seans b(50, 100, 80);

    a.input();
    a.setNum(12);

    cout << a << endl;
    cout << b << endl;

    if (a < b) {
        cout << "a < b" << endl;
    } else {
        cout << "a >= b" << endl;
    }

    if (b % 50) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    cout << pct(b) << endl;

    return 0;
}
