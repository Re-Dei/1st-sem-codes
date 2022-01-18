/**
 * @file a9q3.c
 * @author Hridaya Pradhan
 * @brief uses a structure student to take data of students in a class and sorts them by either roll number or their names accoring to
 * the choice made by the user
 * @version 0.1
 * @date 2021-08-07
 * 
 * This program uses a structure, student, to take the roll no. and the names of the students and store then in array of structure
 * student and calls either sortbyname() function which sorts the array by names of the student, or the sortbyrollnum() function which
 * sorts the array by roll number. Both function uses a bubblesort algorithm and the swap() function, which swaps the value of the
 * data stored in the positions passed as parameters, to sort the array.
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <string.h>
/**
 * @brief a structure, student
 * 
 * This is a structure, student, which has a array of characters, name, which has the maximum word limit of 30 to store the name of a
 * student and integer, rollnum, to store the roll number assigned to that student.
 * 
 */
struct student
{
    char name[30];
    int rollnum;
};
/**
 * @brief swaps the values in the given address
 * 
 * @param a , address of 1st element
 * @param b , address of 2nd element
 * 
 * This function takes two parameters, a and b, which is the address of the elements in the array of the stucture student and swaps
 * the values in the address with help of temp.
 */
void swap(struct student *a, struct student *b)
{
    struct student temp;         //temporary variable
    temp = *a;                   //swapping values in address a and b
    *a = *b;
    *b = temp;
}
/**
 * @brief sorts the array of structure student by name
 * 
 * @param f , size of array
 * @param namesort , address of array of structure student
 * 
 * This function uses bubblesort to sort the array pointed by namesort by name of the students and uses swap() function to exchange the
 * values when required by comparing the name with library function strcmp().
 */
void sortbyname(int f, struct student *namesort)
{
    for(int i = f-1; i >= 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if (strcmp((namesort+j)->name, (namesort+(j+1))->name) > 0){     //if the name in front is greater than the name in back
                swap((namesort+j), (namesort+(j+1)));            //calling swap() function to swap the values
            }
        }
    }
}
/**
 * @brief sorts the array of structure student by rollnum
 * 
 * @param f , size of array
 * @param rollsort , address of array of structure student
 * 
 * This function uses bubblesort to sort the array pointed by rollsort by roll no. of the students and uses swap() function to exchange the
 * values when required by comparing the rollnum of the students.
 */
void sortbyrn(int f, struct student *rollsort)
{
    for(int i = f-1; i >= 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if((rollsort+j)->rollnum > (rollsort+(j+1))->rollnum){      //if the rollnum in front is greater than the rollnum in the back
                swap((rollsort+j), (rollsort+(j+1)));           //calling swap() function to swap the values
            }
        }
    }
}
/**
 * @brief prints the array of structure student
 * 
 * @param f , size of the array
 * @param list , address of the array of structure student
 * 
 * This function prints the array of structure student using a for-loop.
 */
void display(int f, struct student list[])
{
    for(int i = 0; i < f; i++)
    {
        printf("Roll no.: %d\t Name: %s\n", list[i].rollnum, list[i].name);
    }
}
/**
 * @brief main function
 * 
 * @return int 0
 * 
 * This function takes frequency of students and creates an array of structure student, class, of size of frequency, and takes the names
 * and roll number of the students from the user and then uses choice and switch to sort the array by names of the students or roll
 * number of the students as preferred by the user to call either sortbyname() function or sortbyrollnum() function and then uses
 * display() function to print the array of structure student.
 */
int main()
{
    int frequency, choice;

    printf("Enter frequency of student:\t");
    scanf("%d", &frequency);

    struct student class[frequency];
    for(int i = 0; i < frequency; i++)
    {
        printf("Enter name for student %d:\t", i+1);
        scanf("%s", &class[i].name);
        printf("Enter roll no. assigned to student %d:\t", i+1);
        scanf("%d", &class[i].rollnum);
        printf("\n");
    }

    printf("Enter 1 to sort by name.\nEnter 2 to sort by roll number.\nEnter any other key to exit.\n");
    scanf("%d", &choice);
    printf("\n");
    switch(choice)
    {
        case 1:
            sortbyname(frequency, class);
            display(frequency, class);
            break;
        case 2:
            sortbyrn(frequency, class);
            display(frequency, class);
            break;
        default:
            break;
    }
    return 0;
}
