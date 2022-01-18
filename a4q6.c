#include <stdio.h>
#include <math.h>
int main()
{
    int num, sum=0, temp, count=0;
    printf("Enter a number.\n");
    scanf("%d", &num);
    temp = num;
    while (temp > 0)
    {
        temp /= 10;
        count++;
    }
    count--;
    temp = num;
    for (int i = pow(10, count); i>0; i/=10)
    {
        sum += temp/i;
        temp %= i;
    }
    if ( sum == cbrt(num)){
        printf("%d is a Dudeney number.\n", num);
    }else{
        printf("%d is not a Dudeney number.\n", num);
    }
}