/**@file a7q2.c
 * @brief This program calculates the binary of number given by the user
 * 
 * This program uses a function, getdigits(), to calculate the total num of digits to
 * when the number is converted into binary and another function, getbinary(), to print
 * the calculated binary number.
 * 
 * @author: Hridaya Pradhan
 */
#include <stdio.h>
/**@brief returns the total number of digits when n is converted to binary
 * 
 * This funtion gets integer parameter n and calculates to total number of digits by
 * using a for-loop where i = n while i is greater than 0 where i updates by dividing itself
 * with 2. In each loop, the value of count increases which is initially 0 to give the total
 * number of digits.
 */
int getdigits(int n)
{
    int count=0;                //intialize count which represents number of digits in binary form
    for (int i=n; i > 0; i/=2)  //for-loop which repeats itself while i>0
    {
        count++;                //increments count
    }
    return count;               //returns count
}
/**@ brief prints the binary form of x
 * 
 * This function first stores all the remainders in an array of size equal to the number of digits
 * of x in binary form. Then, its prints all the remainders in the array in reverse order with
 * respect to the order from which it was stored.
 */
int getbinary(int x)
{
    //getting total number of digits form getdigits() function and creating an array of size (digits-1) because array starts from 0
    int digits = getdigits(x), bnum[digits-1];   
    for(int i=0; i <digits; i++)           //storing remainders in array with help of for-loop
    {
        bnum[i]= x % 2;
        x /= 2;                            //updating x
    }
    for(int i = (digits-1); i >= 0; i--)   //printing number in reverse order which is the binary form of x
    {
        printf("%d", bnum[i]);
    }
    printf("\n");
    return 0;                              //returns 0
}
/**@brief main function
 * 
 * This function gets the value from the user and calls the getbinary function for the required output.
 */
int main()
{
    int num;
    printf("Enter a number.\n");      //prompt
    scanf("%d", &num);                //storing input in num
    getbinary(num);                   //calling get binary function
}