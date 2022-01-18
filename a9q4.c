/**
 * @file a9q4.c
 * @author Hridaya Pradhan
 * @brief calculates distance between two points, area of triangle and quadrilateral
 * @version 0.1
 * @date 2021-08-08
 * 
 * This program takes points from the user and stores it in array of structure point which is passed to different function to calculate
 * distance by getdistance() function, area of triangle by gettriangle() function and area of quadrilateral by getquad() function.
 * 
 * @copyright Copyright (c) 2021
 */
#include <stdio.h>
#include <math.h>
/**
 * @brief structure point
 * 
 * This structure has integer x and y as its members.
 */
struct point
{
    int x;
    int y;
};
/**
 * @brief calculates distance between two points
 * 
 * @param p1 , 1st point
 * @param p2 , 2nd point
 * @return float d, distance
 * 
 * This function uses distance formula to calculate the distance between the two points passed as paramenters and returns d.
 */
float getdistance(struct point p1, struct point p2)
{
    float d = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));  //using distance formula
    return d;
}
/**
 * @brief calculates area of triangle formed by three points
 * 
 * @param p1 , 1st point
 * @param p2 , 2nd point
 * @param p3 , 3rd point
 * @return float area, area of triangle
 * 
 * This function calls getdistance() function to get length of sides of the triangle and then uses Heron's formula to calculate area of the
 * triangle returns the calculated area.
 */
float gettriangle(struct point p1, struct point p2, struct point p3)
{
    float a = getdistance(p1, p2), b = getdistance(p2, p3), c = getdistance(p3, p1);     //length of sides
    float s = (a + b + c)/2;                                                             //semi-perimeter
    float area = sqrt(s * (s-a) * (s-b) * (s-c));           //Heron's formula
    return area;
}
/**
 * @brief calculates area of quadrilateral formed by four points
 * 
 * @param p1 , 1st point
 * @param p2 , 2nd point
 * @param p3 , 3rd point
 * @param p4 , 4th point
 * @return float area of quadrilateral i.e. sum of two triangles
 * 
 * This function splits the quadrilateral into triangles and calculates their area and adds them to get the area of the quadrilateral.
 */
float getquad(struct point p1, struct point p2, struct point p3, struct point p4)
{
    float t1 = gettriangle(p1, p2, p3), t2 = gettriangle(p1, p3, p4);    //get area of two triangles by gettriangle() function 
    return t1 + t2;
}
/**
 * @brief main function
 * 
 * @return int 0
 * 
 * This function creates an array of structure point of size 4 and asks the user what he/she wants to do and calls either getdistance()
 * function or gettriangle() function or getquad() function after it takes the required values from the user. 
 */
int main()
{
    struct point p[4];   //array of structure point
    int choice;

    printf("Enter the respective number for the following task.\n");
    printf("1. Calculate distance between two points.\n");
    printf("2. Calculate area of a triangle.\n");
    printf("3. Calculate area of a quadrilateral.\n");
    printf("Enter any other key to exit.\n");
    scanf("%d", &choice);
    printf("\n");

    switch(choice)
    {
        case 1:           //calculates distance between two point
            for(int i = 0; i < 2; i++)
            {
                printf("Enter x for point %d:\t", i+1);
                scanf("%d", &p[i].x);
                printf("Enter y for point %d:\t", i+1);
                scanf("%d", &p[i].y);
                printf("\n");
            }
            printf("The distance between the points is %f.\n", getdistance(p[0], p[1]));        //calling getdistance() function
            break;
        case 2:           //calculates area of triangle formed by three points
            for(int i = 0; i < 3; i++)
            {
                printf("Enter x for point %d:\t", i+1);
                scanf("%d", &p[i].x);
                printf("Enter y for point %d:\t", i+1);
                scanf("%d", &p[i].y);
                printf("\n");
            }
            printf("The area of the triangle is %f", gettriangle(p[0], p[1], p[2]));      //calling gettriangle() function  
            break;
        case 3:             //calculates area of quadrilateral formed by four points
            printf("     (x1, y1)____________________ (x2, y2)\n");
            printf("            /                    |\n");
            printf("           /                     |\n");
            printf(" (x4, y4) /______________________|(x3,y3)\n");
            for(int i = 0; i < 4; i++)
            {
                printf("Enter x for point %d:\t", i+1);
                scanf("%d", &p[i].x);
                printf("Enter y for point %d:\t", i+1);
                scanf("%d", &p[i].y);
                printf("\n");
            }
            printf("The area of the quadrilateral is %f", getquad(p[0], p[1], p[2], p[3]));     //calling getquad() function
            break;
        default:
            break;
    }
    return 0;
}