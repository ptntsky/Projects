/*1.    Дано стек, заповнений n випадковими цілими числами.
 Помістити парні елементи в один додатковий стек, непарні - в другий.

2.    Черга складається з n цілих чисел.
 Помістити в початок черги елементи з парними значеннями,
  а в кінець – з непарними, зберігши їх первинний порядок у 
  заданій черзі та використавши додаткові черги.*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_SIZE = 100;

bool isEmpty(int top) {
return top == -1;
}

void push(int stack[], int &top, int value) {
if (top < MAX_SIZE - 1) {
top++;
stack[top]=value;
}
}

int pop(int stack[],int &top) {
if (!isEmpty(top)) {
int val =stack[top];
top--;
return val;
}
return 0;
}

void printStack(int stack[], int top, const char* name) {
    cout << name << " (вершина -> дно): ";
    if (isEmpty(top)) {
        cout << "порожній\n";
        return;
    }
    for (int i=top;i>=0;i--) {
        cout << stack[i] << " ";
    }
    cout << "\n";
}

int main() {
    srand(time(0));

    int n;
    cout << "N: ";
    cin >> n;

    int a[MAX_SIZE], top_a = -1;
    int even_arr[MAX_SIZE], top_even = -1;
    int odd_arr[MAX_SIZE], top_odd = -1;


    for (int i = 0; i < n; i++) {
        push(a, top_a, rand() % 100 - 50);
    }

    printStack(a, top_a, "Початковий стек");


    while (!isEmpty(top_a)) {
        int val = pop(a, top_a);
        if (val % 2 == 0) {
            push(even_arr, top_even, val);
        } else {
            push(odd_arr, top_odd, val);
        }
    }

    printStack(even_arr, top_even, "Стек парних");
    printStack(odd_arr, top_odd, "Стек непарних");

    return 0;
}
