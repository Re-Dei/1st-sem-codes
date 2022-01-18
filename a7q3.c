
/**@file a7q3.c
 * @brief This program rearranges the numbers given by the user
 * 
 * This program gets numbers from the user and stores it in an array
 * then passes it to the function bubblesort() to rearrange the numbers and 
 * print them back to the user.
 * 
 * @author Hridaya Pradhan
 */
#include <stdio.h>
/**@brief This function uses the bubblesort algorithm to rearrange the array of numbers
 * 
 * This function uses nested for-loops to rearrange the numbers by setting the largest number
 * at the end of the array then the second largest number to the second last position of the
 * array and so on until it reaches to the first positon.
 */
void bubblesort(int number[], int count)
{
    int temp;                            //a temporary variable for swapping the numbers during bubblesort
    for(int i = count-2; i>=0; i--)      //first for-loop for determining the total number of numbers invovled in a pass
    {
        for(int j = 0; j<=i; j++)        //second for-loop for swapping and arranging the numbers
        {
            if (number[j]>number[j+1]){   //if the number is greater than next number in the array
                temp=number[j];           //swap
                number[j]=number[j+1];
                number[j+1]=temp;
            }
        }
    }
    printf("The correct ascending order is ");
    for(int x = 0; x < count; x++)         //printing the array to show the results
    {
        printf("%d ", number[x]);
    }
}
/**@breif main function
 * 
 * This function takes the input from the user and stores it in an array then calls
 * the bubblesort() function to rearrange the array and display the results.
 */
int main()
{
    int f;                                           //frequency of the numbers
    printf("Enter the total number of numbers.\n");
    scanf("%d", &f);                                 //gets frequency f
    int num[f-1];                                    //creating an array of size equal to the frequency of numbers
    printf("Enter numbers.\n");
    for(int i = 0; i < f; i++)                       //storing the numbers given by the user in the array
    {
        scanf("%d", &num[i]);
    }
    bubblesort(num, f);                               //calling the bubblesort() function
}