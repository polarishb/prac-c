#include <stdio.h>

#define MONTHS 12
#define YEARS 3

int main(){
    double year2016[MONTHS] = { -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 };
    double year2017[MONTHS] = { -1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 };
    double year2018[MONTHS] = { -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 };

    double arr[YEARS][MONTHS];
    for(int i = 0; i < MONTHS; i++){
        arr[0][i] = year2016[i];
    }
    for(int i = 0; i < MONTHS; i++){
        arr[1][i] = year2017[i];
    }
    for(int i = 0; i < MONTHS; i++){
        arr[2][i] = year2018[i];
    }


    
    printf("[Temperature Data]\n");
    printf("Year index\t:");
    for(int i = 1; i <= MONTHS; i++)
        printf("\t%d", i);
    printf("\n");
    for(int j = 0; j < YEARS; j++){
        printf("Year %d\t\t:", j);
        for(int i = 0; i < MONTHS; i++){
            printf("\t%.1f", arr[j][i]);

        }
        printf("\n");
    }
    printf("\n");
    printf("[Yearly average temperatures of 3 years]\n");
    for(int j = 0; j < YEARS; j++){
        double avg = 0;
        double sum = 0;
        for(int i = 0; i < MONTHS; i++){
            sum += arr[j][i];
        }
        avg = sum / MONTHS;
        printf("Year %d : average temperature = %.1f", j, avg);
        printf("\n");
    }
    printf("\n");
    printf("[Monthly average temperatures for 3 years]\n");
    printf("Year index\t:");
    for(int i = 1; i <= MONTHS; i++)
        printf("\t%d", i);
    printf("\n");
    printf("Avg temps\t:");
    for(int i = 0; i < MONTHS; i++){
        double sum = 0;
        double avg = 0;
        for(int j = 0; j < YEARS; j++){
            sum += arr[j][i];
        }
        avg = sum / YEARS;
        printf("\t%.1f", avg);
    }

    return 0;
}