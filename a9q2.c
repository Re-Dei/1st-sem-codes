/**@file a9q2.c
 * @brief sorts array of floats in ascending order
 * 
 * This program takes an array of floating-point numbers and then uses the bubblesort() function to sort the array in ascending order
 * using pointers and uses swap() to swap the numbers in bubblesort() function.
 * 
 * @author Hridaya Pradhan
 */
#include <stdio.h>
/**@brief swaps two numbers
 * 
 * This program takes pointers of two floats as parameters and swaps them using pass by reference.
 */
void swap(float *a, float *b)
{
    float temp;          //temporary variable to assist in swaping numbers
    temp = *a;           //stores value of the first number
    *a = *b;             //assigns the value of second number in the address of the first number
    *b = temp;           //stores the value in temp in address of the address of the second number
}
/**@brief sorts array of floats in ascending order
 * 
 * This function takes f, the frequency of numbers, and address of the first element of the array then uses the bubblesort algorithm
 * and the swap() function to arrange the array of floats in ascending order.
 */
void bubblesort(int f, float *list)
{
    for(int i = f-1; i >= 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(*(list + j) > *(list + (j+1))){       //swaps if number in the front is greater than the number in the back
                swap((list + j), (list + (j+1)));    //calling swap function to swap the numbers
            }
        }
    }
}
/**@brief main function
 * 
 * This function takes frequency, frequency of numbers, from the user and creates an array of floating-point numbers and gets it values
 * from the user and then calls the bubblesort() function to sort the array of the numbers and prints the array.
 */
int main()
{
    int frequency;          //frequency of the numbers

    printf("Enter the frequency of numbers:\t");
    scanf("%d", &frequency);

    float floats[frequency]; //array of flooating-point numbers

    printf("Enter floating point numbers.\n");
    for(int i = 0; i < frequency; i++)
    {
        scanf("%f", &floats[i]);
    }

    bubblesort(frequency, floats);    //calling the bubblesort() function

    printf("The sorted array is:\n");
    for(int i = 0; i < frequency; i++)
    {
        printf("%f\n", floats[i]);
    }
}