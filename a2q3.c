#include <stdio.h>

int main()
{
    int num, num1, num2, num3, reversenum;
    printf("Enter a three digit number.\n");
    scanf("%d", &num);
    num1= num/100;
    num2= (num%100)/10;
    num3= num%10;
    reversenum= num3*100 +num2*10 +num1;
    printf("The reverse of num %d is %d.\n", num, reversenum);

}