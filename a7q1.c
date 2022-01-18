/**@file a7q1.c
 * @brief program to compare the numbers entered by user and print the smallest number
 * 
 * This program uses array to store the numbers input by number
 * and passes array to a different function to get the smallest number
 * then gives an output to user
 * 
 * @author: Hridaya Pradhan
 */
#include <stdio.h>
/**@brief returns the smallest number
 * 
 * This function gets the array num and n(total number of numbers as parameters)
 * and assigns the first number in num[0] as small(current smallest number)
 * then uses a for-loop to compare small with num[i] where i is the positon 
 * and if the one number is less than the first one the the second number is assigned as small.
 * The loop continues while i < n.
 * After the loop ends, the function returns small back to the main function.
 */
int compare(int num[], int n)
{
    int small;                 //smallest number in the array
    small = num[0];            //assigning the first number of the array as the current smallest
    for (int i = 1; i< n; i++) //loop for i = 1 to n-1
    {
        if (small > num[i]){   //if smaller number is found than small
            small = num[i];    //update small
        }
    }
    return small;              //returns small
}
/**@brief main function
 * 
 * This function takes input from user and stores it in an array
 * and gives output by calling the compare() function.
 */
int main()
{
    int count;                                      //total number of numbers
    printf("Enter total number of numbers.\n"); 
    scanf("%d", &count);
    int num[count-1];                              //declaring array
    printf("Enter the numbers.\n");
    for (int i =0; i < count; i++)                 //scans input and store it in array
    {
        scanf("%d", &num[i]);
    }
    printf("The smallest number is %d.\n", compare(num, count));     //return smallest number to user

}