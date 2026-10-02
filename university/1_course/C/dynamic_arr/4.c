/*Нехай дано натуральне число n та послідовність попарно різних дійсних чисел a1, a2, ..., an
у даній послідовності поміняти місцями:

a) найбільший член з першим по порядку(якщо їх індекси співпадають повідомити про це)

b) найменший член з останнім по порядку(якщо їх індекси співпадають повідомити про це)

c) найбільший і найменший члени

d) найменший член що стоїть на k-тому місці
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, k;
    int idx1, idx2;//Пятницький Данило, 101 група, 1 лабораторна, 7 завдання, 4 вправа.

    printf("N:");
    while(1) {
        scanf("%d",&n);
        if(n>0) break;
    }printf("k:");
    while(1) {
        scanf("%d",&k);
        if(k<=n && k>0) break;
    }

    double *A=(double*)malloc(n*sizeof(double));
    double max=(-INFINITY), min=INFINITY;

    printf("Enter array:");
    for(int i=0; i<n; i++) {
        scanf("%lf", &A[i]); 
        if(A[i]>max) {max=A[i]; idx1=i;}
        if(A[i]<min) {min=A[i]; idx2=i;}
    }

    if (idx1==0) { printf("перший елемент і є максимальним\n"); }
    else { double t=A[0]; A[0]=A[idx1]; A[idx1]=t; }

    for(int i=0; i<n; i++) if(A[i]<min) idx2=i;

    if (idx2==(n-1)) { printf("останній елемент і є мінімальним\n"); }
    else { double ta=A[n-1]; A[n-1]=A[idx2]; A[idx2]=ta; }

    for(int i=0; i<n; i++) {
        if(A[i]>=max) idx1=i;
        if(A[i]<=min) idx2=i;
    }
    double tb=A[idx1]; A[idx1]=A[idx2]; A[idx2]=tb;

    for(int i=0; i<n; i++) if(A[i] <= min) idx2=i;
    double tc=A[k-1]; A[k-1]=A[idx2]; A[idx2]=tc;

    printf("Result: ");
    for(int i=0; i<n; i++) {
        printf("%.0f ", A[i]); 
    }

    free(A);
    return 0;
}
