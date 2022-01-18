/**@file a8q3.c
 * @brief makes a transpose of the given matrix
 * 
 * This program makes a transpose of the matrix given by the user with transpose() function and uses display() function to print the
 * transpose of the given matrix.
 * 
 * @author Hridaya Pradhan
 */
#include <stdio.h>
/**@brief prints the matrix
 * 
 * This function prints the matrix passed by other functions with help of nested-for loops. It takes the arguments r(no. of rows),
 * c(no. of columns) and m(matrix)
 */
void display(int r, int c, int m[][c])
{
    for(int i=0; i < r; i++)          //prints the matrix
    {
        for(int j=0; j < c; j++)
        {
            printf("%d\t", m[i][j]);  //prints the number on ith row and jth column
        }
        printf("\n");
    }
}
/**@brief makes transpose of matrix
 * 
 * This function takes parameters r(no. of rows), c(no. of columns) and m(matrix) and makes the transpose of m by first making a
 * 2D-array, trans, of size opposite to m i.e. c then r. Then it stores the values in trans with nested-for loop
 * in such a way that the number in ith row and jth column in m is stored in jth row and ith column in trans.
 */
int transpose(int r, int c, int m[][c])
{
    int trans[c][r];            //transpose of matrix
    for(int i=0; i<r; i++)         
    {
        for(int j=0; j<c; j++)
        {
            trans[j][i]= m[i][j];      //storing the number in ith row and jth column in m is stored in jth row and ith column in trans
        }
    }
    display(c, r, trans);      //calling display() function to print trans
}

int main()
{
    int row, column;      //numbers of rows and columns

    printf("Enter number of rows:\t");
    scanf("%d", &row);

    printf("Enter number of columns:\t");
    scanf("%d", &column);

    int mat[row][column];         //matrix of size of row and column

    printf("Enter numbers for matrix:\n");
    for(int i = 0; i < row; i++)               //storing numbers in mat
    {
        for(int j = 0; j < column; j++)
        {
            printf("a[%d][%d]=\t", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    transpose(row, column, mat);      //calling transpose() function to transpose mat
}