#include <stdio.h>
int main()
{
    int num, condition;
    printf ("Enter number.\n");
    scanf("%d", &num);
    condition= num & (num-1);
    condition ==0? printf("%d is a power of 2.\n", num): printf("%d is not a power of 2.\n");
}