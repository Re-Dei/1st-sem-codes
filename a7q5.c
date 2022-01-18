/**@file a7q5.c
 * @brief concatenates two strings and stores it in another string
 * 
 * This program takes two string from the user and concatenates them together with the use of library functions from
 * string.h and stores it in another string.
 * 
 * @author Hridaya Pradhan
 */
#include <stdio.h>
#include <string.h>
/**@brief main function
 * 
 * This function takes two strings from the user and first initializes a third string then uses the strcpy() function to
 * first copy the string from 1st string to 3rd string and then concatenates the 3rd string with the 2nd string with strcat() function 
 * to produce the result to print it back to the user. 
 */
int main()
{
    char str1[30], str2[30];       //1st and 2nd string
    printf("Enter two words.\n");
    scanf("%s", str1);
    scanf("%s", str2);
    char str3[strlen(str1)+strlen(str2)];   //3rd string of size equal to the sum of length of 1st and 2nd string
    strcpy(str3, str1);                 //copy 1st string to 3rd string
    strcat(str3, str2);                 //concatenate 3rd string with 2nd string
    printf("%s is the new string.\n", str3);
}