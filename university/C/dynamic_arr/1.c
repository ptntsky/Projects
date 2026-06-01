#include <stdio.h>    //Пятницький Данило, 101 група, 7 лабораторна, 7 завдання.
#include <stdlib.h>
int main()
{

int N,diff=0,size,g=0;
while (1){
printf("Enter N:\n");
scanf("%d",&N);//Введення N
if (N>0) break;
}
int *A = (int*)malloc(N * sizeof(int));
   
   for(int i=0;i<N;i++){        //Введення
       printf("\nA[%d]=", i);
       scanf("%d", &A[i]);
   }
          
   for(int j=0;j<N;j++){        
      if(A[j]>10){
          diff++;
      }
   }
   int *B = (int*)malloc(diff * sizeof(int));
   for(int f=0;f<N;f++){
        if(A[f]>10){
            B[g]=A[f];
            g++;
        }
   }
   if (diff == 0){
       printf("Масив порожній");
   }
        for(int p=0;p<diff;p++){
         printf("%d ",B[p]);
      }    
      free(A);
      free(B);
    return 0;
}
