#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

typedef char string[64];
long int factorial(long int n);

int main(int argc, char const *argv[]) {
    string user_input;
    long int n;

    while (true) {
        printf("Enter a number: ");
        fgets(user_input, 64, stdin);
        sscanf(user_input, "%ld", &n);

        if (n < 0) {
            printf("Invalid input [!]\n\n");
        } else {
            printf("Factorial of %ld is %ld [!]\n", n, factorial(n));
            break;
        }
    }

    return 0;
}

long int factorial(long int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}