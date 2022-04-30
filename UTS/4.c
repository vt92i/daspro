#include <stdio.h>

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

int main(int argc, char const *argv[]) {
    int i;

    for (i = 9; i >= 6; i--) {
        printf("%d %d %d", i, i - 1, i - 2);
        printf("\n");
    }

    return 0;
}