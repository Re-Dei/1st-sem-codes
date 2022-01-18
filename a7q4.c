/**@file a7q4.c
 * @brief checks if the given string is a palindrome.
 * 
 * This program takes a string from the user and then uses passes the given string to another function
 * check_palindrome() which returns an integer value which is either 0 or 1 where 0 and 1 represents false and
 * true respectively. Then the returned value is use to give back an output to user depending the returned
 * value is 0 or 1.
 * 
 * @author: Hridaya Pradhan
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
/**@brief checks if the given string is a palindrome or not.
 * 
 * This function take in the string, word, and its string length, slength, as its parameters. Then it uses i
 * and j for pointing the position of the characters and x which is an integer but acts as a boolean where 0
 * is false and 1 is true. The function uses a loop to compare the string's first and last then 2nd and 2nd
 * to last then so on. If any of the character is different, then x is changed to 0 which was initially 1.
 * Then x is returned.
 */
int check_palindrome(char *word, int slength)
{
    int i = 0, j = slength-1, x=1;   //intialize i as the position of 1st and j as the last and x = 1
    while (j>1)                      //loop until j reaches the 1st position 
    {
        if (tolower(word[i++]) != tolower(word[j--])){      //convert any lowercase letter to uppercase and compare
            x=0;         //if condition is fulfilled x = 0 representing false
            break;       //breaking loop because no need to continue
        }
    }
    return x;            //returns x
}
/**@brief main function
 * 
 * This function takes the string from the user and calls check_palindrome() function to check if the
 * given string is a palindrome then gives a message back to the user.
 */
int main()
{
    char str[30];      //array of character for the given string
    int condition;     //acting boolean
    printf("Enter a word.\n");
    scanf("%s", str);
    condition=check_palindrome(str, strlen(str));  //calling check_palindrome() function and assigning any value returned to condition
    if (condition == 1){                      //giving appropriate output according to the value assigned to condition
        printf("%s is a palindrome.\n", str);
    }else{
        printf("%s is not a palindrome.\n", str);
    }
    return 0;
}