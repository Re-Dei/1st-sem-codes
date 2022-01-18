/**
 * @file p1.c
 * @author Hridaya Pradhan
 * @brief a linked list program which function like search, add, and delete a node from the list and display the list
 * @version 0.1
 * @date 2021-08-15
 * 
 * @copyright Copyright (c) 2021
 * 
 * This program is a linked list program which is created by using a user-defined structure, node, which contains data and address of
 * the next node as its members. It uses a global pointer, head, to point the start of the list and a global temporary variable, gtemp,
 * to assist in codes of other functions. Here, the main function is responsible for calling the function to add, remove, and search a
 * node according to the choices made by the user. It displays the list each time a function is called and in the menu section.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*a structure named node which has member an array of char(string) and a pointer to the data type of itself*/
struct node{
    char data[30];           //data stored in each node
    struct node *ptr;        //pointer which contains the address of the next node
};

struct node *head = NULL;   //pointer to head of list
struct node *gtemp;         //global temporary pointer
int listsize = 0;           //size of list

/*function declarations*/
void displaylist();
void add();
void pop();
int search(char object[]);
void getaddress(int p);

/**
 * @brief main function
 * 
 * @return int 0
 * 
 * This function takes choices from the user and calls other function to do different tasks in linked list.
 */
int main()
{
    int choice = 0, position;   //variable that stroes the choice made by the user and positon of the node
    char word[30];              //word searched by user
    printf("__________________________________________________________________________________________________\n");
    printf("***************************LINKED LIST************************************************************\n");
    printf("*****************************************************By: Hridaya Pradhan**************************\n");
    printf("__________________________________________________________________________________________________\n");
    while (choice != 2)
    {
        displaylist();        //displays current list
        printf("\nEnter the respective number for the following tasks:\n");
        printf("1. Add data to list.\n");
        printf("2. Exit\n");
        /*if list not empty*/
        if (head != NULL){
            printf("3. Search a data from the list.\n");
            printf("4. Delete a data of the list.\n");
        }
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:                 //adds data to the list
                printf("\n************************************************************************************************\n");
                add();
                break;
            case 2:                 //exits program
                break;
            case 3:                 //searchs position of the data
                printf("\n************************************************************************************************\n");
                /*take a string to search in the list*/
                printf("Enter the word to search:\t");
                scanf("%s", word);

                /*call search() function to get position of the given string*/
                position = search(word);

                /*if value returned by the function is 0, print object not found, else print the position of the string in array*/
                if(position == 0){
                    printf("\nMESSAGE: Object not found\n");
                }else{
                    printf("\nMESSAGE: Object found\nThe position of %s in the list is %d.\n", word, position);
                }
                break;
            case 4:                 //removes data from the list
                printf("\n************************************************************************************************\n");
                pop();
                break;
            default:                 //gives and error message for the invalid choice
                printf("\nERROR: Invalid choice.\n");
                break;
        }
        printf("\n************************************************************************************************\n");
    }
}

/**
 * @brief assigns the address of the node given by the positon
 * 
 * @param p , position of the node in the list
 * 
 * This function uses a loop to get the address of the node until the required position is reached and the assigns the address to
 * a global variable, gtemp.
 */
void getaddress(int p)
{
    int count = 1;                       //position of the nodes
    struct node *l;                      //temporary variable that points to the list
    l = head;

    /*loop while count < p and update l and count to get address of the required position*/
    while(count < p)
    {
        l = l->ptr;
        count++;
    }

    /*assign the address of the required position to gtemp*/
    gtemp = l;
}

/**
 * @brief displays the list
 * 
 * This function prints the list pointed by head until null pointer is reached.
 */
void displaylist()
{
    struct node *l = head;                         //temporary variable which points to the list
    int count = 1;                                 //position of the nodes
    printf("\nCurrent list:\n");

    /*loop until the null pointer is reached*/
    while(l != NULL)
    {
        /*print data of the node pointed by l and update l*/
        printf("%d.\t%s\n", count++, l->data);
        l = l->ptr;
    }
}

/**
 * @brief add a new node to the list
 * 
 * This function adds a new node to the list by first getting a valid position of the new node in the list, target, then it creates
 * the new node and assigns its address to temp. If the creation of the new node is unsuccessful, it prints an error message and the
 * control returns back to main function, else it prints a message for successful creation of the new node and adjust the list
 * according to the various condition of the list and position of the node with help of getaddress function and updates listsize.
 */
void add()
{
    int target;                    //position of the target
    struct node *temp;             //temporary pointer that stores the address of the new node
    struct node *l = head;         //variable pointer which points to the list
    
    displaylist();                 //displays current lis

    /*takes position of the target from the user*/
    printf("\nEnter the positon of the data.\n");
    printf("NOTE: Enter 1 to add data to start of the list");
    if(head == NULL){
        printf(".\n");
    }else{
        printf(" and enter %d to add data to end of the list.\n", listsize + 1);
    }
    scanf("%d", &target);

    /*check if the position of the target is invalid and print error message. If not print, continue*/
    if(target > listsize+1 || target <= 0){
        printf("\nERROR: Invalid position\n");
    }else{
        /*allocate an address for the new */
        temp = malloc(sizeof(struct node));

        /*check if allocation for the new address is unsuccessful and print error message, else continue*/
        if (temp == NULL){
            printf("\nERROR: Creation of new node unsuccessful!\n");
        }else{
            /*print a message to show allocation is successful*/
            printf("\nMESSAGE: Creation of new node successful!\n");

            /*check if list is empty*/
            if(head == NULL){
                /*update head and assign null poointer as ptr of the node*/
                head = temp;
                l = temp;
                l->ptr = NULL;
            }else{
                /*get address of the targeted position by using getaddress() function and assign it to a pointer*/
                getaddress(target);
                struct node *targetptr = gtemp;

                /*check if targeted postion is the head of the list*/
                if(targetptr == head){
                    /*jump to the address of the new node and assign the address of previous head to ptr and update head*/
                    l = temp;
                    l->ptr = head;
                    head = l;
                }else{
                    /*get address of the node infront of the targeted position and assign it to a pointer*/
                    getaddress(target - 1);
                    struct node *previousprt = gtemp;      //pointer to address of the node infront of the targeted node

                    /*jump to the address of the node infront of the targeted position and assign the address of new node to its ptr */
                    l = previousprt;
                    l->ptr = temp;

                    /*jump to the address of new node and assign the address of the node prevoiusly in the targeted position to its ptr*/
                    l = temp;
                    l->ptr = targetptr;
                    
                }
            }

            /*take data from the user to be stored in the node*/
            printf("\nEnter the data for node:\t");
            scanf("%s", l->data);

            /*update size of list*/
            listsize++;
        }

    }
}

/**
 * @brief returns the position of the object searched
 * 
 * @param object , string to be searched given by user
 * @return int p, position of the string in the list
 * 
 * This function compares data of each node with object with help of strcmp() function and if a match is found, p is assigned the
 * value of count which is equal to the number of successful passes in the loop. Then it returns p and if data is not found, returns 0.
 */
int search(char object[])
{
    int p = 0;                           //position of the searched node
    int count = 1;                       //position of an individual node
    struct node *l = head;               //pointer pointing to the head of the list
    
    /*loop until null pointer is reached*/
    while(l != NULL)
    {
        /*if the string given by the user and a data in list is same, value of p is changed to the position of the node*/
        if(strcmp(object, l->data) == 0){
            p = count;
            break;
        }
        
        /*update count and l to shift to next node*/
        count++;
        l = l->ptr;
    }
    return p;
}

/**
 * @brief destroys a node
 * 
 * This function takes a valid position of a node from the user and destroys it by freeing the pointer of the node and adjusting
 * the pointers in the list.
 */
void pop()
{
    struct node *l = head;              //pointer pointing the head of the list
    int target;                         //position of the target

    displaylist();                      //displays current list

    /*take position of the target from the user*/
    printf("\nEnter the position of the node to be removed:\t");
    scanf("%d", &target);

    /*check if the given target is invalid and print error message, else continue*/
    if(target <= 0 || target > listsize){
        printf("\nERROR: Invalid target!\n");
    }else{
        /*call getaddress() function to alter to get address of the target and copying it to a new pointer*/
        getaddress(target);
        struct node *target_ptr = gtemp;    //pointer containing pointer of the target

        printf("\nMESSAGE: Target found\n");

        /*check if target is the only node in the array*/
        if(listsize == 1){
            /*update head to NULL and free the node*/
            head = NULL;
            free(l);
        }else{
            /*check if targeted position is the head of the list then update head and free the node*/
            if(target_ptr == head){
                head = l->ptr;
                free(l);
            }else{
                struct node *nextprt;      //pointer pointing to the next node

                /*jump to the address target and copies the address of the next node in next pointer*/
                l = target_ptr;
                nextprt = l->ptr;

                /*jump to address of the node infront of the targeted node and assigns the copied address to its ptr*/
                getaddress(target - 1);
                l = gtemp;
                l->ptr = nextprt;

                /*jump back to address of the target and frees it*/
                l = target_ptr;
                free(l);
            }
        }

        /*if removing is successful update size of list*/
        listsize--;
    }
}