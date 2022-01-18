#include <stdio.h>
int main()
{
   int marks;
   printf("Enter marks.\n");
   scanf("%d", &marks);
   if (marks < 40 && marks>=0) {
      printf("Grade: Fail\n");
   }else{
      if (marks < 45){
         printf ("Grade: D\n");
      }else{
         if (marks < 50){
            printf("Grade: C-\n");
         }else{
            if (marks < 55){
               printf("Grade: C\n");
            }else{
               if (marks < 60){
                  printf("Grade: C+\n");
               }else{
                  if (marks < 65){
                     printf("Grade: B-\n");
                  }else{
                     if (marks < 70){
                        printf("Grade: B\n");
                     }else{
                        if (marks < 75){
                           printf("Grade: B+\n");
                        }else{
                           if (marks < 80){
                              printf("Grade: A-\n");
                           }else{
                              if (marks <= 100){
                                 printf("Grade: A\n");
                              }else{
                                 if (marks < 0 || marks >100){
                                    printf("Error: Invalid marks!");
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
   }
}
   