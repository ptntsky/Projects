/*
 * Задано натуральне n. Розробити програму для обчислення заданих сум.
 * При обчисленні сум використати рекурсивні функції.
                                 _______________________________________________
                                |             __________________________________
                               |             |            ______________________
 _n_                          |             |            |                  ____
 \      a_k             1    | 1     1     | 1     1    | 1           1    | 1
 /__   -----     a^k=  ---\ | --- + ---\  | --- + ---\ | --- +     + ---\ | ---
 k=1    3^k             2  |   1     2  \|   2     2  |   3   . . .   2  |   k
 
 */

#include <stdio.h>
#include <math.h>

double nested_sqrt(int i, int k) {
    if(i==k) return sqrt(1.0 / i);                 
    return sqrt(  (1.0 / i) + 0.5 * nested_sqrt(i + 1, k)  );  //obchyslennya osnovnoyi chastyny
}

double get_ak(int k) {
    return 0.5 * nested_sqrt(1, k);                        //ostanniy chlen mnozhytsya na 1/2
}

double calculate_sum(int k) {
    if(k==1) return get_ak(1) / 3.0;                      
                                                            //obchyslennya summy   
    return (  get_ak(k) / pow(3, k)  ) + calculate_sum(k-1);
}


 int main() {
    int n;

    while (1) {
        printf("Введіть n (n >= 1): ");
        if (scanf("%d",&n)==1 && n>=1) { break; }             //perevirka
 
        while(getchar()!='\n'); //shob ne vvely bukvu bo bude bezkinechny zikl
        printf("ERROR ");
    }

    printf("S = %.12f\n", calculate_sum(n));   //vyklyk funkziyi yaka potim vyklykaye inshi
    

    return 0;
}
