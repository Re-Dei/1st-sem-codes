#include <stdio.h>
int main()
{
    int num, result, i;
    printf("Enter a number for its factorial.\n");
    scanf("%d", &num);
    result = 1;
    for (i=num; i>=1; i--)
    {
        result *= i;
    }
    printf("The factorial of %d is %d.\n", num, result);
}