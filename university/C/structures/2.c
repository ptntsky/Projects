/*
 * ЗАВДАННЯ №7
 * Дано дійсні значення a та b. Отримати:
 * u = f(1.7, a) + f(b, a) + f(a + b, b - a)
 *
 * Де функція f(x, y) обчислюється як:
 * 
             x^2 + x*y - y^2
 * f(x,y) = -----------------
 *           1 + x^2 + y^2
 */

#include <stdio.h>

float f(float x, float y){
    return (  x*x + x*y - y*y  ) / (  1 + x*x + y*y  ); 
    }

int main()
{
    float u,a,b;
    printf("x,y: ");
    scanf("%f %f",&a, &b);
    
    u = f(1.7, a) + f(b, a) + f(a + b, b - a);
    printf("%f",u);

    return 0;
}
