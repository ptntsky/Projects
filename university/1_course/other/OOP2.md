#include <iostream>

using namespace std;

struct Interval {
    int first;
    int second;


    bool check();
    void input();
    void output();
    bool rangeCheck(int number);
};


bool Interval::check() {
    return first < second;
}

void Interval::input() {
    while (true) {
        cout << "Введіть ліву та праву межі інтервалу: ";
      double d1, d2;
        if (!(cin >> d1 >> d2) || d1 != (int)d1 || d2 != (int)d2) {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Помилка, введіть коректні цілі числа\n";
            continue;
        }
        first = (int)d1;
        second = (int)d2;
        if (check()) {
            break;
        }
        cout << "Помилка, ліва межа має бути меншою за праву\n";
    }
}

void Interval::output() {
    cout << "[" << first << ", " << second << ")" << endl;
}

bool Interval::rangeCheck(int number) {
    return (number >= first && number < second);
}

void rangePrintUnion(Interval ob1, Interval ob2) {
    int min_val = (ob1.first < ob2.first) ? ob1.first : ob2.first;
    int max_val = (ob1.second > ob2.second) ? ob1.second : ob2.second;

    cout << "Цілі числа об'єднання діапазонів: ";
    for (int i = min_val; i < max_val; i++) {
        if (ob1.rangeCheck(i) || ob2.rangeCheck(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    Interval ob1, ob2;

    cout << "ob1:" << endl;
    ob1.input();
    cout << "Інтервал 1: ";
    ob1.output();

    cout << "\nob2:" << endl;
    ob2.input();
    cout << "Інтервал 2: ";
    ob2.output();

    int test_num;
    cout << "\nВведіть число для перевірки належності до ob1: ";
    cin >> test_num;
    if (ob1.rangeCheck(test_num)) {
        cout << "Число " << test_num << " належить інтервалу ob1" << endl;
    } else {
        cout << "Число " << test_num << " НЕ належить інтервалу ob1" << endl;
    }

    cout << endl;
    rangePrintUnion(ob1, ob2);

    return 0;
}
