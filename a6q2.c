#include <stdio.h>
int getnum(int i)            //function to get number sequence from 1 to i
{
    if (i == 1){             //base condition to end the recursive function
        printf("%d\n", i);
    }else{
        getnum(i-1);          //recursion part to get number from 1 to i-1
        printf("%d\n", i);    //print i after recursion part
    }
}

int main()
{
    int num;
    printf("Enter a number.\n");  //prompt
    scanf("%d", &num);            //getting upper limit for the sequence
    getnum(num);              //calling function
}