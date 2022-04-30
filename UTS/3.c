#include <stdio.h>

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

int main(int argc, char const *argv[]) {
    int x, y, z;

    printf("Enter number 1: ");
    scanf("%d", &x);

    printf("Enter number 2: ");
    scanf("%d", &y);

    printf("Enter number 3: ");
    scanf("%d", &z);

    if (x < y && x < z) {
        if (y < z)
            printf("\n %d %d %d \n", x, y, z);
        else
            printf("\n %d %d %d \n", x, z, y);
    } else if (y < x && y < z) {
        if (z < x)
            printf("\n %d %d %d \n", y, z, x);
        else
            printf("\n %d %d %d \n", y, x, z);
    } else {
        if (x < y)
            printf("\n %d %d %d \n", z, x, y);
        else
            printf("\n %d %d %d \n", z, y, x);
    }

    return 0;
}
