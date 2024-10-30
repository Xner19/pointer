#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void push(int **arr, int *count, int *max_size, int num);
void pop(int *arr, int *count);
void display(int *arr, int count);

int main() {
    int *stackArr = NULL;
    int elementCount = 0;
    int capacity = 1;
    char cmd;
    int inputVal;

    stackArr = (int*)malloc(capacity * sizeof(int));
    if (stackArr == NULL) {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    while (1) {
        printf("Enter command (p: push, o: pop, d: display, e: exit): ");
        scanf(" %c", &cmd);

        if (cmd == 'p') {
            printf("Enter an integer to push: ");
            scanf("%d", &inputVal);
            push(&stackArr, &elementCount, &capacity, inputVal);
        } 
        else if (cmd == 'o') {
            pop(stackArr, &elementCount);
        } 
        else if (cmd == 'd') {
            display(stackArr, elementCount);
        } 
        else if (cmd == 'e') {
            free(stackArr);
            printf("Exiting program.\n");
            break;
        } 
        else {
            printf("Invalid command. Please enter a valid command.\n");
        }
    }

    return 0;
}

void push(int **arr, int *count, int *max_size, int num) {
    if (*count == *max_size) {
        *max_size *= 2;
        *arr = (int*)realloc(*arr, (*max_size) * sizeof(int));
        if (*arr == NULL) {
            printf("Memory reallocation failed.\n");
            exit(1);
        }
    }
    (*arr)[(*count)++] = num;
}

void pop(int *arr, int *count) {
    if (*count == 0) {
        printf("Stack is empty, cannot pop.\n");
    } else {
        printf("Popped value: %d\n", arr[--(*count)]);
    }
}

void display(int *arr, int count) {
    if (count == 0) {
        printf("Stack is empty.\n");
    } else {
        printf("Current stack: ");
        for (int i = count - 1; i >= 0; i--) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

