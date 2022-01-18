/**@file a8q5.c
 * @brief sorts array of names in ascending order
 * 
 * This program sorts array of names given by the user in ascending order with help of bubblesort algorithm and strcmp() and strcpy()
 * functions.
 * 
 * @author Hridaya Pradhan
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define cols 30       //word limit to names set to 30
/**@brief main function
 * 
 * This function takes the total number of names, rows, from the user and creates an array of string, names, of size of rows. Then
 * takes the names from the user and uses a bubblesort-like algorithm to sort the algorithm using srtcmp() and strcpy() function
 * to compare and swap the string. Finally it prints back the sorted array of names to the user.
 */
int main()
{
    int rows;     //number of names
    
    printf("Enter total number of names:\t");
    scanf("%d", &rows);

    char names[rows][cols], temp[cols];   //array of names and temporary variable to store strings in bubblesort algorithm

    printf("Enter names:\n");
    for(int i = 0; i < rows; i++)
    {
        scanf("%s", &names[i]);
    }

    for(int i=rows-1; i>=0; i--)            //bubblesort
    {
        for(int j = 0; j<i; j++)
        {
            if(strcmp(names[j], names[j+1])>0){    //compares string and if the value returned by strcmp() is positive, swaps the values
                strcpy(temp, names[j]);
                strcpy(names[j], names[j+1]);
                strcpy(names[j+1], temp);
            }
        }
    }

    printf("The sorted order is:\n");    //prints sorted array
    for(int i = 0; i<rows; i++)
    {
        printf("%s\n", names[i]);
    }
}