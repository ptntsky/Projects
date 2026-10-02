/*Розробити програму, яка: 
а) створює текстовий файл TF201, із символьних рядків різної довжини, слова в яких розділені пробілами і розділовими знаками; 
б) читає вміст файла TF201, знаходить всі слова найбільшої довжини і записує їх, розділяючи пробілами, у файл TF202; 
в) читає вміст файла TF202 і друкує його по п'ять слів у рядок*/
#include <stdio.h>
#include <string.h>

int main() {
    char buf[500], words[100][50], *t;
    int count =0, maxL = 0;
    FILE *f1, *f2;

    f1 = fopen("TF201","w");
    printf("TF201:");
    fgets(buf, 500, stdin);
    fputs(buf, f1);
    fclose(f1);

    f1 = fopen("TF201","r");
    fgets(buf, 500, f1);
    fclose(f1);

    t=strtok(buf, " ,.\n");
    while (t) {
    int len = strlen(t);
    if (len > maxL) { maxL = len; count = 0; strcpy(words[count++], t); }
    else if (len==maxL) strcpy(words[count++], t);
    t = strtok(NULL, " ,.\n");
    }

    f2 = fopen("TF202","w");
    for (int i = 0; i < count; i++) fprintf(f2, "%s ", words[i]);
    fclose(f2);

    f2 = fopen("TF202","r");
    printf("TF202:\n");
    for (int i = 0;i < count;i++) {
    fscanf(f2, "%s", buf);
    printf("%s ", buf);
    if ((i+1)%5 == 0) printf("\n");
    }
    fclose(f2);

    return 0;
}
