/**@file a8q1.c
 * @brief creates a matrix of random numbers
 * 
 * This program creates a matrix of random numbers with the help of the function rand() and srand().
 * 
 * @author Hridaya Pradhan
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**@brief main function
 * 
 * This function takes the total number of rows and columns of the matrix and upper limit of random numbers from the user. Then creates
 * a 2D-array of size of the row and column and then uses rand() and srand() function to create a matrix of random numbers in a
 * nested-for loop.
 */
int main()
{
    int row, column, limit;                  //number of rows, columns and upper limit
    printf("Enter number of rows:\t");
    scanf("%d", &row);
    printf("Enter number of columns:\t");
    scanf("%d", &column);
    printf("Enter the upper limit:\t");
    scanf("%d", &limit);
    int matrix[row][column];               //matrix of random numbers
    srand(time(0));
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            matrix[i][j] = rand() % limit;    //assigning a random number to each position in the 2D-array within 0 to (limit-1)
        }
    }
    for(int i = 0; i < row; i++)           //printing array
    {
        for(int j = 0; j < column; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}