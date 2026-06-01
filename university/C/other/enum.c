/*Створіть програму, яка моделює роботу автоматизованої парковки. 
Використовуйте злічений тип для типу транспорту (легковий автомобіль, вантажівка, мотоцикл).
Програма повинна приймати введений тип транспортного засобу,
перевіряти доступні паркувальні місця для кожного типу та виводити відповідне повідомлення.*/

#include <stdio.h>

typedef enum {
        car = 1,
        truck,
        motorcycle
    } VechileType;
    
int main()
{
    int choice;
    int free_cars = 5;
    int free_trucks = 0;
    int free_motos = 10;
    
    printf("Oberyt tip transporty\n");
    printf("1.Lehkoviy\n");
    printf("2.Vantazhivka\n");
    printf("3. Mototsykl\n");
    scanf("%d", &choice);

    switch(choice) {
        /////////////////////////////////////////////////mashini
        case car:
        if (free_cars > 0){
            printf("Dostypno misz %d",free_cars);
        }
        else {
            printf("Nema misz");
        }
        break;
        ///////////////////////////////////////////////vantzhivki
        case truck:
        if (free_trucks > 0){
            printf("Dostypno misz %d",free_trucks);
        }
        else {
            printf("Nema misz");
        }
        break;
        /////////////////////////////////////////////////moto
        case motorcycle:
        if (free_motos > 0){
            printf("Dostypno misz %d",free_motos);
        }
        else {
            printf("Nema misz");
        }
        break;
    }
    return 0;
}
