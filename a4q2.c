#include <stdio.h>
int main()
{
    int limit, num, num1, num2;
    printf("Enter a limit for the Fibonacci sequence to be printed.\n");
    scanf("%d", &limit);
    num1 = -1;
    num2 = 1;
    num = 0;
    do{
        num = num1 + num2;
        num1 = num2;
        num2 = num;
        if (num <= limit){
           printf("%d ", num);
        }
    }while(num <= limit);
    printf("\n");
}
