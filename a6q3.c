#include <stdio.h>
int getfib(int i)         //funtion to get Fibonacci number of ith position
{
    if(i==0){              //base conditon to return error message if the position is 0
        printf("Error\n");
    }else{
        if (i==1){        //base condition if position is 1
            return 0;     //returns 0
        }else{
            if (i==2){    //base condition if position is 2
                return 1;  //returns 1
            }else{
                return (getfib(i-1)+getfib(i-2)); //recursion part which returns the value by adding previous two numbers
            }
        }
    }

}

int main()       //main function
{
    int position, num;
    printf("Enter the position of number.\n");  //prompt
    scanf("%d", &position);    //getting position of number from user
    num = getfib(position);    //calling function
    printf("The %dth number of Fibonacci sequence is %d.\n", position, num);  //giving output to user
}