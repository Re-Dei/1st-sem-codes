#include <stdio.h>
#include <math.h>
int main()
{
    int num, temp, sum = 0, count = 0;
    printf("Enter a number.\n");
    top:
    scanf("%d", &num);
    if (num < 0){
        printf("Enter a valid number.\n");
        goto top;
    }
    temp = num;
    while (temp>0)
    {
        temp /= 10;
        if (temp > 0){
            count++;
        }
    }
    temp = num;
    for(int i = pow(10, count); i > 0; i/=10)
    {
        sum = sum + pow(temp/i, count+1);
        temp %= i;
    }
    if (sum == num){
        printf("%d is an Armstrong number.\n", num);
    }else{
        printf("%d is not an Armstrong number.\n", num);
    }
}