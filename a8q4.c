/**@file a4q8.c
 * @brief multiplies two matrices 
 * 
 * This program multiples two matrices given by the user and uses multiply() function to find the product of the two matrices and then
 * uses the display() function to print the product.
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
/**@brief multiplies the matrices
 * 
 * This function multiples takes two matrices, A and B, and their no. of rows(r1, r2) and columns(c1, c2) as parameters and creates a
 * 2D-array, product, of size r1 and c2 to store the numbers of the product of the matrices. It uses a nested-for loop to calculate
 * each elements and store it in the appropriate position in the array and then calls the display() function to print product.
 */
void multiply(int r1, int c1, int r2, int c2, int A[][c1], int B[][c2])
{
    int product[r1][c2], sum=0;       //product of two matrices and initialize sum as 0
    for(int i=0; i<c2; i++)
    {
        for(int j=0; j<r1; j++)
        {
            for(int k=0; k<r2; k++)
            {
                sum += A[j][k]*B[k][i]; //multiples the number at jth row and kth column of A and number at kth row and ith column and adds it to sum
            }
            product[j][i]=sum;   //assigns the number in sum to appropriate position in product
            sum=0;               //0 is assigned to sum to calculate sum for next loop
        }
    }
    display(r1, c2, product);     //calls display() function to print product
}
/**@brief main function
 * 
 * This function first takes number of rows and columns until it is valid for matrix multipication and then creates matrices of
 * respective sizes and then takes the elements of the matrices from the user. Then it calls the multiply() function to multiply the
 * two matrices.
 */
int main()
{
    int row1, row2, col1, col2; //no. of rows and columns of first and the second matrix
    
    do{    //loop until no. of rows and columns are valid for matrix multipication i.e. col1=row2
        printf("Enter number of rows of 1st matrix:\t");
        scanf("%d", &row1);

        printf("Enter number of columns of 1st matrix:\t");
        scanf("%d", &col1);

        printf("Enter number of rows:\t");
        scanf("%d", &row2);

        printf("Enter number of columns:\t");
        scanf("%d", &col2);
        if(col1 != row2){
            printf("Error: The number of columns of 1st matrix is not equal to number of rows of 2nd matrix.\n"); //error message
        }
    }while(col1 != row2);

    int matA[row1][col1], matB[row2][col2];

    printf("Enter numbers for matrix A:\n");
    for(int i = 0; i < row1; i++)               //storing numbers in matA
    {
        for(int j = 0; j < col1; j++)
        {
            printf("a[%d][%d]=\t", i, j);
            scanf("%d", &matA[i][j]);
        }
    }

    printf("Enter numbers for matrix B:\n");
    for(int i = 0; i < row2; i++)               //storing numbers in matB
    {
        for(int j = 0; j < col2; j++)
        {
            printf("a[%d][%d]=\t", i, j);
            scanf("%d", &matB[i][j]);
        }
    }

    multiply(row1, col1, row2, col2, matA, matB);    //calling multiply() function to multiply matA and matB
}