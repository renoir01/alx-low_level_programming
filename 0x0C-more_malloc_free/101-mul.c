#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int multiply(const char *num1, const char *num2) {
    int len1 = 0, len2 = 0, i, j;
    int *result, carry, n1, n2, sum;

    // Calculate the length of both numbers
    while (num1[len1])
        len1++;
    while (num2[len2])
        len2++;

    // Allocate memory for the result
    result = malloc(sizeof(int) * (len1 + len2));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize the result array with 0
    for (i = 0; i < len1 + len2; i++)
        result[i] = 0;

    // Multiply each digit and store the result in the result array
    for (i = len1 - 1; i >= 0; i--) {
        n1 = num1[i] - '0';
        carry = 0;

        for (j = len2 - 1; j >= 0; j--) {
            n2 = num2[j] - '0';
            sum = n1 * n2 + result[i + j + 1] + carry;
            result[i + j + 1] = sum % 10;
            carry = sum / 10;
        }

        result[i] += carry;
    }

    // Find the first non-zero digit in the result array
    i = 0;
    while (result[i] == 0 && i < len1 + len2 - 1)
        i++;

    // Print the result
    for (; i < len1 + len2; i++)
        printf("%d", result[i]);
    printf("\n");

    free(result);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Error: Invalid number of arguments\n");
        return 98;
    }

    // Check if num1 and num2 are composed of digits
    for (int i = 1; i < argc; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if (!isdigit(argv[i][j])) {
                fprintf(stderr, "Error: Arguments must be composed of digits\n");
                return 98;
            }
        }
    }

    multiply(argv[1], argv[2]);

    return 0;
}
