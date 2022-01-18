#include <stdio.h>
int main(){
    int dnum, bnum, result, count, onum;
    printf("Enter a number.\n");
    scanf("%d",&dnum);
    onum= dnum;
    bnum=0;
    count=1;
    while (dnum>0){
       result = dnum%2;
       dnum = dnum/2;
       bnum = count*result+bnum;
       count = count * 10;
    }
    printf("The binary value of %d is %d.\n", onum, bnum);
}