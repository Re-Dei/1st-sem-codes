#include <stdio.h>
int getgcd(int n1, int n2)        //function to get GCD with integer parameter n1 and n2
{
    int num=1;                   //initializing num
    if (n1 == 0){                //if n1 = 0, returning n2 because 0 can be divided by any number
        return n2;
    }else if(n2 == 0){          //if n2 = 0, returnig n1
        return n1;
    }else if (n1 == n2){           //if both are equal returning n1
        return n1;
    }else{
        if (n1 > n2){            //separating the condition to minimize load
            for(int i = n2; i>=1; i--)             //using for loop from the smaller number to 1 until a common factor is found
            {
                if (n1%i == 0 && n2%i == 0){
                    return i;
                    break;
                }
            }
        }else{
            for(int i = n1; i>=1; i--)              //same as above
            {
                if (n1%i == 0 && n2%i == 0){
                    return i;
                    break;
                }
            }
        }

    }
}

int main()              //main function
{
    int num1, num2, gcd;
    printf("Enter two numbers for their GCD.\n");      //prompt
    scanf("%d", &num1);                                //inputs from user
    scanf("%d", &num2);
    gcd = getgcd(num1, num2);                 //calling function and assigning its result to user
    printf("The GCD of %d and %d  is %d.\n", num1, num2, gcd);       //output back to user
}