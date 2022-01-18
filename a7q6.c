/**@file a7q6.c
 * @brief picks out unique elements in a string and prints it
 * 
 * This program gets a string from the user and uses an array to check if each element in the string is in the array. If it is not in
 * the array, it stores the element and the process loops until all the elements are checked. Then prints it.
 * 
 * @author: Hridaya Pradhan
 */
#include <stdio.h>
#include <string.h>
/**@brief main function
 * 
 * This function gets a string from the user and stores it in a array of characters str[] of size 30. Then it calculates the length of
 * the given string and assigns it to len and another array of character unique[] of size of value of len is created and initialized.
 * Then a nested-loop is used to store all the unique elements of the given string in the array unique[] which is then printed.
 */
int main()
{
    char str[30];     //given string
    printf("Enter a string.\n");
    scanf("%s", str);
    int len = strlen(str);       //length of the given string
    char unique[len];             //array of unique elements
    for (int a=0; a <= len; a++)      //initializes unique[]
    {
        unique[a]='\0';
    }
    int position = 0;              //position of element in unique[] initially set to 0(1st position)
    for (int i = 0; i < len; i++)      //1st loop which changes i where i is the position of the element in str[]
    {
        int check = 0;               //acting boolean initially set to 0 false
        for (int j = 0; j < position; j++)    //2nd loop with changing j where j is the postion of element in unique[]
        {
            if(unique[j] == str[i]){     //check if the element in the arrays match
                check = 1;               //if matched, check becomes 1(true)
                break;               //no need for further looping
            }
        }
        if(check == 0){              //if element in not in unique[]
            unique[position++] = str[i];   //store the element
        }
    }
    printf("The unique elements of %s are: ", str);         //printing the unique elements
    for (int x=0; x <= strlen(unique); x++)
    {
        printf("%c ", unique[x]);
    }
}