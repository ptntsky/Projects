#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_SIZE = 100;

bool isQueueEmpty(int head, int tail) { return head == tail; }

void enqueue(int queue[], int &tail, int value) {
if (tail < MAX_SIZE) {
queue[tail] = value;
tail++;
}
}


int dequeue(int queue[], int &head) {
int val = queue[head];
head++;
return val;
}

void printQueue(int queue[], int head, int tail, const char* name) {
cout << name << " (початок -> кінець): ";
if (isQueueEmpty(head, tail)) {
cout << "порожня\n";
return;
}
for (int i = head; i < tail; i++) {
cout << queue[i] << " ";
}
cout << "\n";
}

int main() {
    srand(time(0));

    int n;
    cout << "N: ";
    cin >> n;

    int q[MAX_SIZE], head = 0, tail = 0;

    int q_even[MAX_SIZE], head_even = 0, tail_even = 0;
    int q_odd[MAX_SIZE], head_odd = 0, tail_odd = 0;

    for (int i = 0; i < n; i++) {
    enqueue(q, tail, rand() % 100 - 50);
    }

    printQueue(q, head, tail, "Початкова черга");

    while(!isQueueEmpty(head, tail)) {
        int val = dequeue(q, head);
        if (val % 2 == 0) {
        enqueue(q_even, tail_even, val);
        } else {
        enqueue(q_odd, tail_odd, val);
        }
    }

    head = 0;
    tail = 0;

    while (!isQueueEmpty(head_even, tail_even)) { enqueue(q, tail, dequeue(q_even, head_even)); }

    while (!isQueueEmpty(head_odd, tail_odd)) { enqueue(q, tail, dequeue(q_odd, head_odd)); }

    printQueue(q, head, tail, "Оновлена черга");

    return 0;
}
