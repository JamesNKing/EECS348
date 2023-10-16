#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/* output format:
 * 
 * Monthly sales report for 202X:
 * Month    Sales
 * January  $23457.01
 * ...
 *
 * Sales summary:
 * Minimum sales: $1 (Month)
 * Maximum sales: $2 (Month)
 * Averages sales: $1.5 
 *
 * Six-Month Moving Average Report:
 * January - June $1
 * February - July $2
 * ...
 *
 * Sales Report (Highest to Lowest):
 * Month    Sales
 * December     $1
 * November     $8
 * ...
*/ 

const char *months[] = {"January", "Februrary", "March", "April", "May",
    "June", "July", "August", "September", "October", "November",
    "December"
};

int getMaxMonthWidth() {
    int max = 0;
    for (int i=0; i < 12; i++) {
        int len = strlen(months[i]);
        if (len > max) {
            max = len;
        }
    }
    return max;
}

int main() {
    // read in floats
    FILE *file = fopen("sample_input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    float *numbers = NULL;
    int numOfFloats = 0;
    float currentFloat;

    while(fscanf(file, "%f", &currentFloat) == 1) {
        // resize array and store float
        numbers = realloc(numbers, (numOfFloats + 1) * sizeof(float));
        numbers[numOfFloats] = currentFloat;
        numOfFloats++;
    }

    fclose(file);

    // monthly sales
    int monthWidth = getMaxMonthWidth();
    int salesWidth = 5;
    printf("Monthly sales report for 2023:\n");
    printf("%-*s %*s\n", monthWidth, "Month", salesWidth, "Sales");
    for (int i=0; i < 12; i++) {
        printf("%-*s %*.2f\n", monthWidth, months[i], salesWidth, numbers[i]);
    }

    // sales summary
    float totalSales = 0; 

    float max = numbers[0];
    int maxIndex = 0;
    for (int i=0; i < 12; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
            maxIndex = i;
        }
    }

    float min = numbers[0];
    int minIndex = 0;
    for (int i=0; i < 12; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
            minIndex = i;
        }
        totalSales += numbers[i];
    }
    
    float averageSales = totalSales / 12;

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min, months[minIndex]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[maxIndex]);
    printf("Average sales: $%.2f\n", averageSales);

    // six-month moving average report
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 5; i < 12; i++) {
        float six_month_total = 0;
        for (int j = i-5; j <= i; j++) {
            six_month_total += numbers[j];
        }
        float six_month_avg = six_month_total / 6;
        printf("%s - %s $%.2f\n", months[i-5], months[i], six_month_avg);
    }

    // sales report 
    int indices[12];
    for (int i = 0; i < 12; i++) {
        indices[i] = i;
    }

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11 - i; j++) {
            if (numbers[indices[j]] < numbers[indices[j + 1]]) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }

    printf("\nSales Report (Highest to Lowest):\n");
    printf("%-*s %*s\n", monthWidth, "Month", salesWidth, "Sales");
    for (int i = 0; i < 12; i++) {
        printf("%-*s %*.2f\n", monthWidth, months[indices[i]], salesWidth, numbers[indices[i]]);
    }

    return 0;
}
