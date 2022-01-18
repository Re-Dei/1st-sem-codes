/**
 * @file a9q5.c
 * @author Hridaya Pradhan
 * @brief shuffles deck of cards
 * @version 0.1
 * @date 2021-08-10
 * 
 * This program creates a deck of cards with user defined data types and shuffles it using suffle() function and swap() function and
 * uses display(), showface() and showsuit() to display the suffled deck of cards.
 * 
 * @copyright Copyright (c) 2021
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*This user defined data type is of type enumaration which represents the suits of cards that are Diamond, Heart, Spade and Club.*/
typedef enum {Diamond, Heart, Spade, Club} suits;
/*This user defined data type is of type enumeration which represents the faces of the cards*/
typedef enum {Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King}faces;
/*This is a structure card with members suit and num*/
struct card
{
    suits suit;
    faces num;
};

struct card deck[52];     //deck of cards i.e array of structure card
/**
 * @brief swaps values of elements in structure card
 * 
 * @param a , address of 1st element
 * @param b , address of 2nd element
 * 
 * This program swaps the values pointed by a and b with help of a temporary variable, temp.
 */
void swap(struct card *a, struct card *b)
{
    struct card temp = *a;   //temporary variable assigned with the value pointed by a
    *a = *b;                 //value pointed by b stored in the address of a
    *b = temp;               //value in temp stored in the address of b
}
/**
 * @brief shuffles the deck of cards
 * 
 * This function suffles deck which is a global variable with help of srand(), rand() and swap() function by using for-loop to swap
 * position of each card in the deck to a random position in the deck.
 */
void shuffle()
{
    int random;           //random position in deck
    srand(time(0));          //changing seed of rand() function with respect to time
    for(int i = 0; i < 52; i++)
    {
        random = rand() % 52;          //max value of random set to 51
        swap(&deck[i], &deck[random]);     //swaping the card in ith position to a random card in the deck
    }
}
/**
 * @brief prints the suit of the card
 * 
 * @param c , card
 * 
 * This function prints the suit of the card represented by the enumeration with help of switch.
 */
void showsuit(struct card c)
{
    suits s = c.suit;   //suit of the card
    switch(s)
    {
        case Diamond:
            printf("Diamond");
            break;
        case Heart:
            printf("Heart");
            break;
        case Spade:
            printf("Spade");
            break;
        case Club:
            printf("Club");
            break;
        default:
            break;
    }
}
/**
 * @brief prints the face of the card
 * 
 * @param c , card
 * 
 * This function prints the face of the card represented by the enumeration with help of switch.
 */
void showface(struct card c)
{
    faces f = c.num;    //face of the card
    switch(f)
    {
        case Ace:
            printf("Ace");
            break;
        case Two:
            printf("2");
            break;
        case Three:
            printf("3");
            break;
        case Four:
            printf("4");
            break;
        case Five:
            printf("5");
            break;
        case Six:
            printf("6");
            break;
        case Seven:
            printf("7");
            break;
        case Eight:
            printf("8");
            break;
        case Nine:
            printf("9");
            break;
        case Ten:
            printf("10");
            break;
        case Jack:
            printf("Jack");
            break;
        case Queen:
            printf("Queen");
            break;
        case King:
            printf("King");
            break;
        default:
            break;
    }
}
/**
 * @brief prints the deck of cards
 * 
 * This function displays deck, the global structure variable, with help of showsuit() and showface() function.
 */
void display()
{
    printf("The shuffled deck is:\n");
    for(int i = 0; i < 52; i++)         //prints card in each position
    {
        showsuit(deck[i]);
        printf("\t");
        showface(deck[i]);
        printf("\n");
    }
}
/**
 * @brief main function
 * 
 * @return int 0
 * 
 * This function initializes deck and calls shuffle() and display() function.
 */
int main()
{
    int count = 0;    //position of cards
    for(suits i = Diamond; i <= Club; i++)    //initailizes deck of cards
    {
        for(faces j = Ace; j <= King; j++)
        {
            deck[count].suit = i;
            deck[count].num = j;
            count++;
        }
    }
    shuffle();     //calls shuffle() function
    display();      //calls display() funcion
    return 0;
}