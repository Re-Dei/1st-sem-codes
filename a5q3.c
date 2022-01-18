#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float getdistance(int x1, int y1, int x2, int y2)            //function to get distance between two points with parameter x1, x2, y1, y2
{
    float distance;
    distance = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));          //using distance formula 
    return distance;                                         //returning distance
}

float getareaoftri(int x1, int y1, int x2, int y2, int x3, int y3)       //function to get area of triangle with parameter x1, x2, x3, y1, y2, y3
{
    float area, s, a, b, c;
    a = getdistance(x1, y1, x2, y2);                                     //calling getdistance function to get distance between 2 points
    b = getdistance(x2, y2, x3, y3);               
    c = getdistance(x3, y3, x1, y1);
    s = (a + b + c) / 2;                                                 //calculating semi-perimeter and assigning it to s
    area = sqrt(s * (s-a) * (s-b) * (s-c));                              //using Heron's formula
    return area;                                                         //returning area
}

float getareaofquad(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)        //function to get area of quadrilateral with parameter x1, x2, x3, x4, y1, y2, y3, y4
{
    float area1, area2, totarea;
    area1 = getareaoftri(x1, y1, x2, y2, x3, y3);                                          //calling getareaoftri function to get area of triangle of three points
    area2 = getareaoftri(x1, y1, x3, y3, x4, y4);
    totarea = area1 + area2;                                                               //adding area of triangles to get area of quadrilateral
    return totarea;                                                                        //returning total area
}

int main()
{
    int X1, X2, X3, X4, Y1, Y2, Y3, Y4, choice; 
    float d, At, Aq;
    printf("Enter the respective number for the following task.\n");      //prompt
    printf("1. Calculate distance between two points.\n");
    printf("2. Calculate area of a triangle.\n");
    printf("3. Calculate area of a quadrilateral.\n");
    scanf("%d", &choice);                                                 //input
    switch(choice)                                                        //use of switch to make different choices
    {
        case 1:                                                           //calculates distance between any 2 points
            printf("Enter x1, y1, x2 & y2 respectively.\n");              //prompt
            scanf("%d", &X1);                                             //input
            scanf("%d", &Y1);
            scanf("%d", &X2);
            scanf("%d", &Y2);
            d = getdistance(X1, Y1, X2, Y2);                              //calling function to get distance
            printf("The distance between the points is %f.\n", d);        //output
            break;
        case 2:                                                           //calculates area of triangle
            printf("Enter x1, y1, x2, y2, x3 & y3 respectively.\n");      //prompt
            scanf("%d", &X1);                                             //input
            scanf("%d", &Y1);
            scanf("%d", &X2);
            scanf("%d", &Y2);
            scanf("%d", &X3);
            scanf("%d", &Y3);
            At = getareaoftri(X1, Y1, X2, Y2, X3, Y3);                   //calling function to get area of triangle
            printf("The area of the triangle is %f.\n", At);             //output
            break;
        case 3:                                                                    //calculates area of quadrilateral
            printf("Enter x1, y1, x2, y2, x3, y3, x4 & y4 respectively.\n");       //prompt
            printf("where:\n");
            printf("     (x1, y1)____________________ (x2, y2)\n");
            printf("            /                    |\n");
            printf("           /                     |\n");
            printf(" (x4, y4) /______________________|(x3,y3)\n");
            scanf("%d", &X1);                                                       //input
            scanf("%d", &Y1);
            scanf("%d", &X2);
            scanf("%d", &Y2);
            scanf("%d", &X3);
            scanf("%d", &Y3);
            scanf("%d", &X4);
            scanf("%d", &Y4);
            Aq = getareaofquad(X1, Y1, X2, Y2, X3, Y3, X4, Y4);                     //calling function to get area of quadrilateral
            printf("The area of the quadrilateral is %f.\n", Aq);                   //output
            break;
        default:
            printf("Invalid choice.");                                              //error message
            exit(1);                                                                //exiting program unsuccessfully
    }

}