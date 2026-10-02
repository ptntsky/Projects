#include <stdio.h>
#include <string.h>
struct monument {
    char name[100];
    int year;
    char architect[100];
    char address[100];
    int number;
};
void show(FILE *f) {
    struct monument m;
    rewind(f);
    while(fread(&m,sizeof(m),1,f))
        printf("%s %d %s %s %d\n",m.name,m.year,m.architect,m.address,m.number);
}
void search(FILE *f) {
    struct monument m;
    int a,b;
    printf("Від: ");scanf("%d",&a);
    printf("До: ");scanf("%d",&b);
    rewind(f);
    while(fread(&m,sizeof(m),1,f))
        if(m.year>=a && m.year<=b)
            printf("%s %d %s %s %d\n",m.name,m.year,m.architect,m.address,m.number);
}
void seed(FILE *f) {
    struct monument data[]={
        {"Колізей",80,"Веспасіан","Рим, Італія",1},
        {"Собор Паризької Богоматері",1163,"Моріс де Сюллі","Париж, Франція",2},
        {"Акрополь",-447,"Іктін","Афіни, Греція",3},
        {"Велика китайська стіна",-221,"Мен Тянь","Китай",4},
        {"Тадж-Махал",1632,"Устад Ахмад Лахорі","Агра, Індія",5}
    };
    rewind(f);
    fwrite(data,sizeof(struct monument),5,f);
}
int main() {
    FILE *f=fopen("data.bin","w+b");
    seed(f);
    int c;
    do {
        printf("1.Всі 2.Пошук 0.Вихід: ");
        scanf("%d",&c);
        if(c==1) show(f);
        else if(c==2) search(f);
    } while(c!=0);
    fclose(f);
    return 0;
}
