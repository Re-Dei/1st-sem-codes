#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int getfactorial(int i)                            //function to get factorial of i
{
    int factorial = 1;                             //initializing factorial
    for(int count = i; count > 0; count--)         //use of for loop to get factorial of i
    {
        factorial *= count;                        //multiplying factorial with count in decreasing order and storing it in factorial
    }
    return factorial;                              //returning factorial to main function
}

int getdigits(int j)          // function to get total number of digits of j
{
    int count = 0;           //initializing count
    while (j > 0)
    {
        j /= 10;             //updating j and increasing count until j = 0
        count++;
    }
    return count;            //returning count to the main function
}

int main()
{
    int num, num1, digits, temp, sum=0, divisor, power;
    printf("Enter a positive number.\n");                 //prompt
    scanf("%d", &num);                                    //taking input from user
    if (num < 0){                                         //checking if the input number is negative
        printf("The number entered is not a positive number.\n");  //error message
        exit(1);                                                   //exiting program without success
    }
    digits = getdigits(num);                     //calling function to get digits in the number
    temp = num;                                  //assigning the input to temp so it doesn't change
    for(int i = digits-1; i>=0; i--)             //using for loop to separate each digit and adding its factorial to sum
    {
        divisor = pow(10, i);
        num1 = temp / divisor;
        temp %= divisor;
        sum += getfactorial(num1);
    }
    if(sum == num){            //checking if the input num and sum is equal
        printf("%d is a strong number.\n", num);           //output back to user
    }else{
        printf("%d is not a strong number.\n", num);        //output back to user
    }
}