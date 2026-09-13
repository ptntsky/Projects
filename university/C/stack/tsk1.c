/*1.Дано стек, що містить n цілих чисел. Використовуючи додатковий стек, записати в основу заданого стека суму всіх елементів.

2.Додати у кінець черги суму модулів всіх елементів. Черга складається з n цілих додатних та від’ємних чисел.

*/

#include <stdio.h>
#include <stdlib.h>

// ===================== СТЕК =====================
typedef struct {
    int *arr;
    int top;
} Stack;

// Замість s->arr пишемо (*s).arr
void push(Stack *s, int val) { (*s).arr[++((*s).top)] = val; }
int pop(Stack *s)             { return (*s).arr[((*s).top)--]; }
int isStackEmpty(Stack *s)    { return (*s).top == -1; }

// ===================== ЧЕРГА ====================
typedef struct {
    int *arr;
    int head, tail, count, cap;
} Queue;

void enqueue(Queue *q, int val) {
    (*q).arr[(*q).tail] = val;
    (*q).tail = ((*q).tail + 1) % (*q).cap;
    (*q).count++;
}

int dequeue(Queue *q) {
    int val = (*q).arr[(*q).head];
    (*q).head = ((*q).head + 1) % (*q).cap;
    (*q).count--;
    return val;
}

// ================================================
int main(void) {
    int n;
    printf("Введіть кількість елементів n: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    // --- ЗАВДАННЯ 1: СТЕК ---
    Stack s0 = {(int*)malloc((n + 1) * sizeof(int)), -1};
    Stack s1 = {(int*)malloc(n * sizeof(int)), -1};

    printf("\n[Стек] Введіть %d цілих чисел: ", n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        push(&s0, x);
    }

    int sum = 0;
    while (!isStackEmpty(&s0)) {
        int val = pop(&s0);
        sum += val;
        push(&s1, val);
    }
    push(&s0, sum); // сума лягла на дно
    while (!isStackEmpty(&s1)) {
        push(&s0, pop(&s1));
    }

    printf("Стек (вершина -> дно): ");
    while (!isStackEmpty(&s0)) printf("%d ", pop(&s0));
    printf("\n");

    free(s0.arr);
    free(s1.arr);

    // --- ЗАВДАННЯ 2: ЧЕРГА ---
    Queue q = {(int*)malloc((n + 1) * sizeof(int)), 0, 0, 0, n + 1};

    printf("\n[Черга] Введіть %d чисел (+ та -): ", n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }

    int abs_sum = 0;
    for (int i = 0; i < n; i++) {
        int val = dequeue(&q);
        abs_sum += abs(val);
        enqueue(&q, val);
    }
    enqueue(&q, abs_sum); // додаємо в кінець

    printf("Черга (початок -> кінець): ");
    while (q.count > 0) printf("%d ", dequeue(&q));
    printf("\n");

    free(q.arr);
    return 0;
}
