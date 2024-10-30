#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseString(char *str);
int main() {
    char *input = (char *)malloc(100 * sizeof(char));
    if (input == NULL) {
        printf("Memory allocation failed\n");
        return 1;
	//checks if it is null or not, so it can start exacuting.
    }
    printf("Enter a string: ");
    scanf("%s", input);
    //goes into the funtion 
    char *reversed = reverseString(input);
    printf("Reversed string is: %s\n", reversed);
    
    //freeing both input and output
    free(input);
    free(reversed);
    return 0;
}

char* reverseString(char *str) {
    int length = strlen(str);
    char *reversed = (char *)malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - i - 1];
    }
    reversed[length] = '\0';
    return reversed;
}

