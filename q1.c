#include <stdio.h>

int main()
{
    float num, square;
    printf("Enter the number to be squared.\n");
    scanf("%f", &num);
    square = num*num;
    printf("The square of the %f is %f.\n", num, square);
}