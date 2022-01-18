/**@file a8q2.c
 * @brief adds two matrices
 * 
 * This program adds two matrices given by the user and returns it sum with function add() and display().
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
/**@brief adds two matrices
 * 
 * This function takes the parameters r(no. of rows), c(no. of columns), A(1st matrix) and B(2nd matrix) and adds the two matrices
 * passed by other function. It adds each element of the corresponding position by using nested-for loops and calls the display()
 * function to print the sum of the two matrices.
 */
void add( int r, int c, int A[][c], int B[][c])
{
    int s[r][c];           //sum of the matrices
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            s[i][j] = A[i][j] + B[i][j];  //adding numbers of same position and storing it in s.
        }
    }
    printf("The sum of the matrices are:\n");
    display(r, c, s);              //calling display() function to print s.
}
/**@brief main function
 * 
 * This function takes size of row and column of the matrices from the user and creates two 2D-arrays of the size of the row and column.
 * Then it takes the numbers from the user and stores it in the corresponding positon and calls the add() function to add the two
 * matrices
 */
int main()
{
    int row, column;      //numbers of rows and columns

    printf("Enter number of rows:\t");
    scanf("%d", &row);

    printf("Enter number of columns:\t");
    scanf("%d", &column);

    int matA[row][column], matB[row][column];    //matrices of size of rows and columns

    printf("Enter numbers for matrix A:\n");
    for(int i = 0; i < row; i++)               //storing numbers in matA
    {
        for(int j = 0; j < column; j++)
        {
            printf("a[%d][%d]=\t", i, j);
            scanf("%d", &matA[i][j]);
        }
    }

    printf("Enter numbers for matrix B:\n");     //storing numbers in matB
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            printf("b[%d][%d]=\t", i, j);
            scanf("%d", &matB[i][j]);
        }
    }
    add(row, column, matA, matB);            //calling add function to add the two matrices
}