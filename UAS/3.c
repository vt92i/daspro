#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

typedef char string[64];

int ratusan(int n);
int ratusan2(int n, bool b);

int main(int argc, char const *argv[]) {
    string user_input;
    int n, menu;
    bool b;

    printf("\n --= Menu =--\n");
    printf("1. Ratusan\n");
    printf("2. Ratusan 2\n");

    printf("\nInput Pilihan >> ");
    fgets(user_input, 64, stdin);
    menu = atoi(user_input);

    switch (menu) {
        case 1:
            printf("\n[ Ratusan ]\n");
            printf("Input N     : ");
            fgets(user_input, 64, stdin);
            n = atoi(user_input);

            printf("Output N    : %d\n", ratusan(n));
            break;

        case 2:
            printf("\n[ Ratusan 2 ]\n");
            printf("Input N     : ");
            fgets(user_input, 64, stdin);
            n = atoi(user_input);

            printf("Input B     : ");
            fgets(user_input, 64, stdin);
            b = atoi(user_input);

            printf("Output N    : %d\n", ratusan2(n, b));
            break;

        default:
            printf("Menu tidak tersedia []!\n");
            break;
    }

    return 0;
}

int ratusan(int n) {
    if (n < 0)
        return 0;

    return 100 * ceil(n / 100.0);
}

int ratusan2(int n, bool b) {
    int c;

    if (n < 0)
        return 0;

    if (b)
        c = 100 * ceil(n / 100.0);
    else
        c = 100 * floor(n / 100.0);

    return c;
}