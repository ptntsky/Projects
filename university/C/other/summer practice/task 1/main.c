#include <stdio.h>
#include "shapes.h"

int main() {
    int choice;
    double a, b, c, r, h, v;
    do {
        printf("\nЩо обчислити?\n1. Призма\n2. Циліндр\n3. Куля\n4. Конус\n5. Піраміда\n0. Вихід\nВаш вибір: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Довжина, ширина, висота: ");
                scanf("%lf %lf %lf", &a, &b, &c);
                v = box(a, b, c);
                printf("Об'єм = %.2f\n", v);
                break;
            case 2:
                printf("Радіус, висота: ");
                scanf("%lf %lf", &r, &h);
                v = cylinder(r, h);
                printf("Об'єм = %.2f\n", v);
                break;
            case 3:
                printf("Радіус: ");
                scanf("%lf", &r);
                v = sphere(r);
                printf("Об'єм = %.2f\n", v);
                break;
            case 4:
                printf("Радіус, висота: ");
                scanf("%lf %lf", &r, &h);
                v = cone(r, h);
                printf("Об'єм = %.2f\n", v);
                break;
            case 5:
                printf("Сторони основи, висота: ");
                scanf("%lf %lf %lf", &a, &b, &h);
                v = pyramid(a, b, h);
                printf("Об'єм = %.2f\n", v);
                break;
            case 0:
                printf("Вихід.\n");
                break;
            default:
                printf("Невірний вибір!\n");
        }
    } while (choice != 0);
    return 0;
}
