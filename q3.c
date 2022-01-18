#include <stdio.h>

int main()
{
    int num1, num2, num3, sum;
    printf("enter three numbers.\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);
    sum = num1 + num2 + num3;
    printf ("The entered numbers are: %d, %d, %d\n", num1, num2, num3);
    printf ("%d + %d + %d = %d", num1, num2, num3, sum);
}