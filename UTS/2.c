#include <stdio.h>

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

int main(int argc, char const *argv[]) {
    int i, j;

    for (i = 1; i <= 6; i++) {
        for (j = 0; j < i; j++) {
            printf(" %d ", j);
        }
        printf("\n");
    }

    for (i = 5; i >= 1; i--) {
        for (j = 0; j < i; j++) {
            printf(" %d ", j);
        }
        printf("\n");
    }

    return 0;
}