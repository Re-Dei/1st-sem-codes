#include <stdio.h>
int main()
{
    int num, count, result, check;
    char re;
    top:
    count = 2;
    check = 0;
    printf("Enter a number.\n");
    scanf("%d%*c", &num);
    do{
        result = num % count;
        if (result == 0){
            check = 1;
            break;
        }
        count++;
    }while(count < num - 1);
    if (check == 0){
        printf("%d is a prime number.\n", num);
    }else{
        printf("%d is not a a prime number.\n", num);
    }
    point:
    printf("Do you want to check again?(Y/N)\n");
    scanf("%c", &re);
    switch(re){
        case 'Y':
           goto top;
        case 'N':
           break;
        default:
           printf("Invalid choice. Please use Y/N.\n");
           goto point;
    }
}

