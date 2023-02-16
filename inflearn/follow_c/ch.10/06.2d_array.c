#include <stdio.h>

#define MONTHS 12
#define YEARS 3

void showindex(void);
void showdata(double *data[]);
void showaverage_year(double *data[]);
void showaverage_month(double *data[]);

int main()
{
    double year2016[MONTHS] = { -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 };
    double year2017[MONTHS] = { -1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 };
    double year2018[MONTHS] = {-4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 };
    
    double *years[YEARS];

    years[0] = year2016;
    years[1] = year2017;
    years[2] = year2018;

    printf("[Temperature Data]\n");
    showindex();
    showdata(years);

    printf("[Yearly average temperatures of 3 years]\n");
    showaverage_year(years);

    printf("[Monthly average temperatures for 3 years]\n");
    showindex();
    showaverage_month(years);

    return 0;
}

void showdata(double *data[])
{
    for(int i = 0; i < YEARS; i++){
        printf("Year %d\t\t:", i);

        for(int j = 0; j < MONTHS; j++){
            printf(" %.1f\t", data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void showindex(void)
{
    printf("Year index\t:");
    for(int i = 1; i <= MONTHS; i++){
        printf(" %d\t", i);
    }
    printf("\n");
}

void showaverage_year(double *data[])
{
    for(int i = 0; i < YEARS; i++){
        printf("Year %d\t:", i);

        double sum = 0;
        for(int j = 0; j < MONTHS; j++){
            sum += data[i][j];
        }
        printf(" average temperature = %f\n", sum / MONTHS);
    }
    printf("\n");
}

void showaverage_month(double *data[])
{
    printf("Avg temps\t:");

    for(int i = 0; i < MONTHS; i++){

        double sum = 0;
        for(int j = 0; j < YEARS; j++){
            sum += data[j][i];
        }

        printf(" %.1f\t", sum / YEARS);
    }
    printf("\n");
}