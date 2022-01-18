#include <stdio.h>
#include <math.h>

int main ()
{
    float a, b, c, x1, x2, temp;
    printf("Enter three number.\n");
    scanf ("%f", &a);
    scanf ("%f", &b);
    scanf ("%f", &c);
    temp = b*b - 4 *a*c;
    x1= (-b +sqrt(temp))/2/a; 
    x2=(-b -sqrt(temp))/2/a;
    printf ("The value of x are %f and %f.\n", x1, x2);

} 