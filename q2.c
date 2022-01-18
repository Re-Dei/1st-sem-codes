#include <stdio.h>

int main()
{
    char lcase, ucase;
    printf("Enter a lower case letter.\n");
    scanf("%c", &lcase);
    ucase = lcase - 32;
    printf("The uppercase of %c is %c.\n", lcase, ucase);
}