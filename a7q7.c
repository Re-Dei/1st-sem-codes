/**@file a7q7.c
 * @brief sorts two arrays in descending order and combines them and again sorts it in descending order
 * 
 * This program takes two arrays of integer from the user and then sorts them in descending order with bubblesort algorithm in
 * descending order in *reverse_bubblesort() function which returns a pointer to the array of the sorted number and then copies the
 * sorted array in the main function to create another array to combine both arrays and then again use the *reverse_bubblesort()
 * function and then copies the array and prints them back to the user.
 * 
 * @author: Hridaya Pradhan
 */
#include <stdio.h>
/**@brief uses the bubblesort algorithm to rearrange the array of numbers in descending order
 * 
 * This function uses nested for-loops to rearrange the numbers by setting the smallest number
 * at the end of the array then the second smallest number to the second last position of the
 * array and so on until it reaches to the first positon.
 */
int *reverse_bubblesort(int number[], int count)
{
    int temp;                            //a temporary variable for swapping the numbers during bubblesort
    for(int i = count-2; i>=0; i--)      //first for-loop for determining the total number of numbers invovled in a pass
    {
        for(int j = 0; j<=i; j++)        //second for-loop for swapping and arranging the numbers
        {
            if (number[j]<number[j+1]){   //if the number is less than next number in the array
                temp=number[j];           //swap
                number[j]=number[j+1];
                number[j+1]=temp;
            }
        }
    }
    return number;
}
/**@brief main function
 * 
 * This function handles the input and output process. It takes values of two arrays of numbers and calls the *reverse_bubblesort()
 * function and receives a pointer for the array sorted in descending order and replaces the values with the original array and then
 * combines them and again calls the *reverse_bubblesort() to rearrange the merged array and stores the value with help of pointers to
 * print them.
 */
int main()
{
    int f1, f2, f3;         //frequencies of the arrays
    int *p, *q, *r;         //pointers

    printf("Enter frequency of 1st array.\n");
    scanf("%d", &f1);

    int numbers1[f1];              //first array
    printf("Enter numbers for 1st array.\n");
    for(int i = 0; i < f1; i++)         //storing values of the first array
    {
        scanf("%d", &numbers1[i]);
    }

    printf("Enter frequency of 2nd array.\n");
    scanf("%d", &f2);

    int numbers2[f2];                 //second array
    printf("Enter numbers for 2nd array.\n");
    for(int i = 0; i < f2; i++)         //storing values of the second array
    {
        scanf("%d", &numbers2[i]);
    }

    p = reverse_bubblesort(numbers1, f1);   //calling reverse_bubblesort() and receiving pointers
    for (int i = 0; i < f1; i++)            //replacing sorted values with original values
    {
        numbers1[i] = *(p + i);
    }

    printf("The descending order of the 1st array is ");  //printing first sorted array
    for(int i = 0; i < f1; i++)
    {
        printf("%d ", numbers1[i]);
    }
    printf("\n");

    q = reverse_bubblesort(numbers2, f2);         //same as first array
    for (int i = 0; i < f2; i++)
    {
        numbers2[i] = *(q + i);
    }

    printf("The descending order of the 2nd array is ");
    for(int i = 0; i < f2; i++)
    {
        printf("%d ", numbers2[i]);
    }
    printf("\n");

    f3 = f1 + f2;         //calculating frequency for third array
    int numbers3[f3];         //third array
    for (int a = 0; a < f1; a++)    //combining arrays
    {
        numbers3[a] = numbers1[a];
    }
    for(int b = f1; b < f3; b++)
    {
        numbers3[b] = numbers2[b-f1];
    }

    r = reverse_bubblesort(numbers3, f3);     //same as first array
    for (int i = 0; i < f3; i++)
    {
        numbers3[i] = *(r + i);
    }

    printf("The descending order of the merged array is "); //printing the final result
    for(int i = 0; i < f3; i++)
    {
        printf("%d ", numbers3[i]);
    }
    printf("\n");
    return 0;
}