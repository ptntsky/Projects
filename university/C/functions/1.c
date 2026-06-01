/*На площині задана множина n точок, n <= 200 і множина m точок, m <= 100
За означенням віддаль між множинами точок це віддаль між найближче розміщеними точками цих множин.
Розробити програму обчислення віддалі між заданими множинами
і визначення координат найближче розміщених точок(якщо таких пар точок декілька, то взяти одну із них).
Для обчислення віддалі між множинами та визначення координат найближче розміщених точок та для обчислення віддалі між точками
використати функції.*/

#include <stdio.h>
#include <math.h>

struct point{
        double x;
        double y;
    };
     
     double dist(struct point p1, struct point p2){
         double dx = p1.x - p2.x;                    //d=sqrt(  (x1-x2)^2 + (y1-y2)^2  )
         double dy = p1.y - p2.y;
         return sqrt(dx * dx + dy * dy);
     }

int main()
{
    struct point setN[200];
    struct point setM[100];
    int n,m;
    
    printf("N:");
     scanf("%d", &n);
     for(int i=0; i<n; i++){
         printf("N[%d] (x y): ", i);
         scanf("%lf %lf", &setN[i].x, &setN[i].y);
     }
     
    printf("M:");
     scanf("%d", &m);
     for(int j=0; j<m; j++){
         printf("M[%d] (x y): ", j);
         scanf("%lf %lf", &setM[j].x, &setM[j].y);
     }
     
     double mindist;
     
     struct point bestM, bestN;

     int firstpair = 1;
     
     for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
             double currentdist = dist(setN[i], setM[j]);
             if(firstpair || currentdist < mindist){

                 mindist = currentdist;

                 bestN = setN[i]; 
                 bestM = setM[j];
                 firstpair=0;
             }
         }
     }

    printf("distance:%.2f \n",mindist);
    

    return 0;
}
