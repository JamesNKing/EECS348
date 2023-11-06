#include <stdio.h>

const int TD_2PT = 8;
const int TD_FG = 7;
const int TD = 6;
const int FG = 3;
const int SAFETY = 2;
const char *plays[] = {"TD + 2pt", "TD + FG", "TD", "3pt FG", "Safety"};
const int scores[] = {8, 7, 6, 3, 2};

void findCombinations(int score, int counts[5], int start) {
    if (score == 0) {
        for (int i = 0; i < 5; i++) {
            if (counts[i] > 0) {
                printf("%d %s, ", counts[i], plays[i]);
            }
        }
        printf("\n");
        return;
    }
    
    if (start >= 5) return;

    for (int i = 0; score - i * scores[start] >= 0; i++) {
        counts[start] = i;
        findCombinations(score - i * scores[start], counts, start + 1);
    }
    counts[start] = 0;
}

int main() {
    while (1) {
        int score;
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            break;
        }
        
        printf("possible combinations of scoring plays:\n");
        int counts[5] = {0};
        findCombinations(score, counts, 0);
    }

    return 0;
}

