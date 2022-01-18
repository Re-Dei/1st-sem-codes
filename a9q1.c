/**@file a9q1.c
 * @breif finds the largest number in an array
 * 
 * This program takes a array of numbers from the user. Then uses the searchlargest() function that to return the pointer of the
 * largest number in the array.
 * 
 * @author Hridaya Pradhan
 */
#include <stdio.h>
/**@brief returns the pointer of largest number in the array
 * 
 * This function takes the n, frequency of the numbers in the array, and the address of the first element of the array. Then it
 * initializes l, the pointer of the largest number, to the address of the first element of the array as the current largest number.
 * Then it uses a for-loop to compare each element with the current largest element and if a larger element is found l is assigned the
 * address of the largest element. Then it returns l.
 */
int *searchlargest(int n, int *num)
{
    static int *l;        //pointer to the largest number
    l = (num + 0);        //setting first element as the current largest
    for(int i = 1; i < n; i++)
    {
        if(*l < *(num + i)){    //if a greater number than the largest number is found
            l = (num + i);      //assign l the pointer of that number
        }
    }
    return l;             //returns l
}
/**@brief main function
 * 
 * This function takes f, frequency of numbers, from the user and then creates an array of size of the frequency and then calls the
 * searchlargest() function and stores the address of the largest number in largest, then prints the value in largest back to user.
 */
int main()
{
    int f, *largest;        //frequency of the array of numbers and pointer of the largest number
    
    printf("Enter the frequency of numbers:\t");
    scanf("%d", &f);

    int numbers[f];        //array of number of size of f
    
    printf("Enter the numbers.\n");
    for(int i = 0; i < f; i++)
    {
        scanf("%d", &numbers[i]);
    }

    largest=searchlargest(f, numbers);       //calling searchlargest() function to get pointer to the largest number

    printf("The largest number is %d.\n", *largest);
}