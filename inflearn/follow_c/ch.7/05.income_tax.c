#include <stdio.h>

#define BASE1 12000000 * 0.06
#define BASE2 34000000 * 0.15
#define BASE3 42000000 * 0.24
#define BASE4 62000000 * 0.35
#define BASE5 150000000 * 0.38
#define BASE6 200000000 * 0.40
#define BASE7 500000000 * 0.42

int main()
{
    float income;
    float tax = 0;
    
    printf("Input income : ");
    scanf("%f", &income);
    income -= 1500000;

    if (income > 1000000000)
    {
        income -= 1000000000;
        tax = income * 0.40 + BASE1 + BASE2 + BASE3 + BASE4 + BASE5 + BASE6 + BASE7;
    }
    else if (income > 500000000)
    {
        income -= 500000000;
        tax = income * 0.40 + BASE1 + BASE2 + BASE3 + BASE4 + BASE5 + BASE6;
    }
    else if (income > 300000000)
    {
        income -= 300000000;
        tax = income * 0.38 + BASE1 + BASE2 + BASE3 + BASE4 + BASE5;
    }
    else if (income > 150000000)
    {
        income -= 150000000;
        tax = income * 0.38 + BASE1 + BASE2 + BASE3 + BASE4;
    }
    else if (income > 88000000)
    {
        income -= 88000000;
        tax = income * 0.35 + BASE1 + BASE2 + BASE3;
    }
    else if (income > 46000000)
    {
        income -= 46000000;
        tax = income * 0.24 + BASE1 + BASE2;
    }
    else if (income > 12000000)
    {
        income -= 12000000;
        tax = income * 0.15 + BASE1;
    }
    else
        tax = income * 0.06;

    printf("Tax is = %f\n", tax);

    return 0;
}