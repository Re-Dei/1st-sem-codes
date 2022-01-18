#include <stdio.h>
int main()
{
    int num, sum=0, result;
    printf("Enter a positive integer.\n");
    scanf("%d", &num);
    for(int count = 1; count < num; count++)
    {
        result = num % count;
        if (result == 0){
            sum += count;
        }
    }
    if (num == sum){
        printf("%d is a perfect number.\n", num);
    }else{
        printf("%d is not a perfect number.\n", num);
    }
}