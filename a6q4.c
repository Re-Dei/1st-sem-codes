#include <stdio.h>
int getbinary(int i)                            //function to get binary of i
{
    if (i==0){                //base condition to end recursion
        return 0;             //returns 0
    }else{
        return(i%2 + 10*getbinary(i/2));         //recursive part
    }
}

int main()             //main function
{
    int num, binary;
    printf("Enter a positive number.\n");       //prompt
    scanf("%d", &num);                         //input
    binary = getbinary(num);                   //calling getbinary() function
    printf("The binary of %d is %d.\n", num, binary);        //output
}