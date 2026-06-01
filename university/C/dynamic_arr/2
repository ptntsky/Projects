/* 
Знайти номер останнього мінімального елемента, серед елементів,
менших Т1, і розташованих до першого елемента, більшого Т2.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main() {//Пятницький Данило, 101 група, 1 лабораторна, 7 завдання, 2 вправа.
    int j=0;
    int n, T1, T2, idxT2=-1, idxT1=-1, min=INT_MAX;
    while (1){
    printf("n, T1, T2: ");
    scanf("%d %d %d", &n, &T1, &T2);
    if (n>0) break;
    }
    int *A = (int*)malloc(n * sizeof(int));
    
    
    while(j<n){
        printf("A[%d]:",j);
        scanf("%d",&A[j]);
        j++;
    }

    
    for(int i = 0; i<n; i++){
        if(A[i]>T2){
            idxT2=i;
            break;
        }
    }
    for(int f = 0; f < (idxT2 != -1 ? idxT2 : n); f++) {
       if( A[f] < T1 && A[f]<=min){
           min=A[f];
                idxT1=f; 
       }
    }

    
if(idxT2 == -1){
    printf("T2 Index is not found: ");
    }
    else{
    printf("Index of first element>T2:%d", idxT2);
    }
if(idxT1 == -1){
    printf("\nT1 Index is not found: ");
    }
    else{
    printf("\nIndex of last minimal element < T1 and placed before T2:%d", idxT1);
    }

    
    free(A);
    return 0;
}
