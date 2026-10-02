/*Задано два масиви цілих чисел Х(n) тa Y(n), n ≤ 300 
Розробити програму яка обчислює добуток елементів об'єднання цих масивів.
Об'єднання двох масивів — це всі елементи масиву X(n) і всі елементи масиву Y(n),
взяті по одному разу. Надрукувати елементи об'єднання та їх суму.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{   int i=0,j=0,p=0, q=0,w=0,e=0;
    int n,sum=0,product=1;
    while(1){
    printf("n<=300:");
    scanf("%d",&n);
    if(n<=300 && n>0){
    break;}
    }
    int n2=n;
    int *X = (int*)malloc(n*sizeof(int));
    int *Y = (int*)malloc(n*sizeof(int));
    
    while(i<n){
        printf("\nX[%d]:",i);
        scanf("%d",&X[i]);
        i++;
    }
    while(j<n){
        printf("\nY[%d]:",j);
        scanf("%d",&Y[j]);
        j++;
    }
    
    for(int f=0; f<n2;f++){
        p=0;
        while(p<n){
            if(Y[f]==X[p]){
                break;
            }
            p++;
        }
        if(p==n){
            X=realloc(X, (n+1)*sizeof(int));
            X[n]=Y[f];
            n++;
        }
    }
    
    while(q<n){
        product *= X[q];
        q++;
    }
    printf("Добуток:%d", product);
    
    while(w<n){
        sum += X[w];
        w++;
    }
    printf("\nСума:%d", sum);
    
    printf("\nОб'єднаний масив:\n");
    while(e<n){
       printf("%d ",X[e]);
       e++;
    }
    
    free(X);
    free(Y);
    
    return 0;
}
