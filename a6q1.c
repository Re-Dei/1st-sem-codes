#include <stdio.h>
int getgcd(int a, int b)    //function to get GCD of a and b
{
    if (b==0){              //base condition
        return a;           //returns a 
    }else{
        getgcd(b, a%b);     //recursive part
    }
}

int main()
{
    int num1, num2, gcd, temp;
    printf("Enter two numbers for the GCD.\n");  //prompt
    scanf("%d", &num1);              //input from user
    scanf("%d", &num2);
    if (num2 > num1){   //rearranging num1 and num2 if num2 is greater than num1
        temp = num2;
        num2 = num1;
        num1 = temp;
    }
    gcd = getgcd(num1, num2);  //calling function
    printf("%d is the GCD of %d and %d.\n", gcd, num1, num2);  //output to user
}