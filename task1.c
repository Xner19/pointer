#include <stdio.h>
#include <stdlib.h>

int* VectorSum(int *x, int *y, int size, int a, int b);

int main() {
    int N, a, b;
    printf("Enter the size of the vectors: ");
    scanf("%d", &N);

    printf("Enter scalar a: ");
    scanf("%d", &a);
    printf("Enter scalar b: ");
    scanf("%d", &b);

    int *x = (int*) malloc(N * sizeof(int));
    int *y = (int*) malloc(N * sizeof(int));

    printf("Enter elements of vector x: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &x[i]);
    }

    printf("Enter elements of vector y: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &y[i]);
    }

    int *sum = VectorSum(x, y, N, a, b);

    printf("Sum of scaled vectors (a*x + b*y): ");
    for (int i = 0; i < N; i++) {
        printf("%d ", sum[i]);
    }
    printf("\n");

    free(x);
    free(y);
    free(sum);

    return 0;
}

int* VectorSum(int *x, int *y, int size, int a, int b) {
    int *sum = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        sum[i] = a * x[i] + b * y[i];
    }
    return sum;
}

