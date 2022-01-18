#include <stdio.h>
int main()
{
    int spaces, num=0,no_num=1, nextnum=0;
    for( int no_spaces=9; no_spaces>=0; no_spaces--)
    {
        for(spaces=1; spaces<=no_spaces; spaces++)
        {
            printf(" ");
        }
        for(int pointer=1; pointer<=(no_num+1)/2; pointer++)
        {
            num++;
            nextnum = (num)%10;
            printf("%d", nextnum);
        }
        for(int pointer=1; pointer<=(no_num-1)/2; pointer++)
        {
            num--;
            nextnum = (num)%10;
            printf("%d", nextnum);
        }
        printf("\n");
        no_num += 2;
    }
}