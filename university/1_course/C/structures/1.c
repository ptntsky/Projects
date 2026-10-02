/*Відомість про результати зимової сесії містить інформацію:
прізвище та ініціали студента, номер групи, оцінки із 3-х предметів
а) мат аналізу
б) програмування
в) алгебри
написати програму що вводить інформацію  із відомомті друкує студентів що вчатся  на 4, 5
та друкує їхнє процентне співвіднощення з іншими */

#include <stdio.h>
#include <string.h>

struct info {
    char PIB[50];
    int matan;
    int programming;
    int algebra;
};

int main() {
    int n;
    printf("Введіть кількість студентів: ");
    scanf("%d", &n);

    struct info data[n];
    float grades[n];

    for (int i = 0; i < n; i++) {
        printf("\nСтудент %d:\n", i + 1);
        printf("Прізвище ініціали: ");
        
        int c;
        while ((c = getchar()) != '\n' && c != EOF); 

        fgets(data[i].PIB, 50, stdin);
        data[i].PIB[strcspn(data[i].PIB, "\n")] = 0;
        
        printf("Матаналіз: ");
        scanf("%d", &data[i].matan);
        printf("Програмування: ");
        scanf("%d", &data[i].programming);
        printf("Алгебра: ");
        scanf("%d", &data[i].algebra);

        grades[i] = (data[i].matan + data[i].programming + data[i].algebra) / 3.0;
    }

    printf("Результати (4 і 5)");
    for (int i = 0; i < n; i++) {
        if (grades[i] >= 4.0) {
            printf("Студент: %s (Середній бал: %.2f)\n", data[i].PIB, grades[i]);
            
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                float diff = ((grades[i] - grades[j]) / grades[j]) * 100;
                
                if (diff > 0) printf("  Краще за %s на %.1f%%\n", data[j].PIB, diff);
                else if (diff < 0) printf("  Гірше за %s на %.1f%%\n", data[j].PIB, -diff);
                else printf("  Бали однакові з %s\n", data[j].PIB);
            }
        }
    }
    return 0;
}
