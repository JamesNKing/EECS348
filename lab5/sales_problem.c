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
    int max = 0;
    int maxIndex = 0;
    for (int i=0; i < 12; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
            maxIndex = i;
        }
    }

    printf("

    return 0;
}
