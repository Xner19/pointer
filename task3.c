#include <stdio.h>
#include <stdlib.h>

int main() {
    char addsamp;
    int *number = (int*) malloc(1 * sizeof(int));
    int count = 0;
    int sum = 0;

    if (number == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    while (1) {
        printf("Please enter an integer sample: ");
        scanf("%d", &number[count]);
        
        sum += number[count];
        count++;

        printf("If you want to add a sample, press 'y' or '1'. Press 'n' or '0' to stop: ");
        scanf(" %c", &addsamp);

        if (addsamp == 'y' || addsamp == '1') {
            number = (int*) realloc(number, (count + 1) * sizeof(int));
            if (number == NULL) {
                printf("Memory reallocation failed\n");
                return 1;
            }
        } else if (addsamp == 'n' || addsamp == '0') {
            break;
        }
    }

    int average = sum / count;
    printf("Average: %d\n", average);

    printf("New values after subtracting average:\n");
    for (int i = 0; i < count; i++) {
        printf("%d\n", number[i] - average);
    }

    free(number);
    return 0;
}

