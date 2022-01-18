#include <stdio.h>

int main()
{
    float centigrade, fahrenheit;
    printf ("Enter temperature in centigrade.\n");
    scanf("%f", &centigrade);
    fahrenheit= centigrade * 9 /5 +32;
    printf ("The value of %f C in fahrenheit is %f F.\n", centigrade, fahrenheit);
}
