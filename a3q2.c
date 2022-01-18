#include <stdio.h>
int main(){
    int salary, bonus, premium, income;
    float tax, temptax;
    printf("Enter monthly salary.\n");
    scanf("%d", &salary);
    printf("Enter annual bonus.\n");
    scanf("%d", &bonus);
    printf("Enter annual life insurance premium.\n");
    scanf("%d", &premium);
    tax = 0;
    temptax = 0;
    income = salary * 12 + bonus - premium;
    if (income > 400000) {
        tax += 4000;
        income -= 400000;
        if (income>100000) {
            tax += 10000;
            income -= 100000;
            if (income>200000){
                tax += 40000;
                income -= 200000;
                if (income > 1300000){
                    income -= 1300000;
                    temptax = 390000 + (income*36/100);
                    tax += temptax;
                }else{
                    temptax = income * 30 / 100;
                    tax += temptax;
                }
            }else{
                temptax = income * 20 /100;
                tax += temptax;
            }
        }else{
            temptax = income * 10/100;
            tax += temptax;
        }
    }else{
        temptax = income/100;
        tax += temptax;
    }
    printf("Your annual income tax is %f.\n", tax);
}