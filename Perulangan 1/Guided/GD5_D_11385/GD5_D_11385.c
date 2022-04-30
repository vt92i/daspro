#if defined(_WIN32) || defined(_WIN64)
    #define PLATFORM_NAME "windows"
    #include <conio.h>
#endif

#if defined(__linux__)
    #define PLATFORM_NAME "linux"
    #include <ncurses.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

typedef char string[64];

int main(int argc, char const *argv[]) {
    int menu, bilangan, umur;
    int temp = 0, random = 0;

    string nama;
    char huruf;

    srand(time(NULL));

    do {
        if (PLATFORM_NAME == "linux")
            system("clear");

        if (PLATFORM_NAME == "windows")
            system("cls");

        printf("\n---= MENU GUIDED =---");

        printf("\n1. Menu menjumlahkan bilangan");
        printf("\n2. Menu menampilkan huruf A-Z");
        printf("\n3. Menu input data diri");
        printf("\n4. Menu cari angka random (20-80)");
        printf("\n0. Keluar");
        printf("\n---------------------");

        printf("\nMasukan pilihan menu > ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\nMasukan bilangan      : ");
                scanf("%d", &bilangan);

                while (bilangan > 0) {
                    temp += bilangan;
                    printf("\nTemp  = %d", temp);
                    bilangan--;
                }

                printf("\n\nJumlah bilangannya  : %d\n", temp);
                break;

            case 2:
                printf("\nAlphabet      : ");

                for (huruf = 'A'; huruf <= 'Z'; huruf++)
                    printf("%c ", huruf);
                printf("\n");
                break;

            case 3:
                do {
                    printf("\nNama      : ");
                    getchar();
                    fflush(stdin);
                    gets(nama);
                } while (strlen(nama) < 1);

                do {
                    printf("Umur      : ");
                    scanf("%d", &umur);
                } while (umur <= 1);

                printf("\nNama      : %s", nama);
                printf("\nUmur      : %d", umur);
                printf("\n");
                break;

            case 4:
                printf("\nMemberhentikan perulangan disaat angka menunjukan (20-80) : ");
                scanf("%d", &bilangan);

                do {
                    random = (rand() % (80 - 20 + 1)) + 20;
                    printf("\nRandom    : %d", random);
                } while (random != bilangan);

                printf("\n");
                break;

            case 0:
                printf("\nTerimakasih banyak :)\n");
                break;

            default:
                printf("\nMenu hanya ada 1-4[!]\n");
                break;
        }
        if (PLATFORM_NAME == "linux") {
            initscr();
            getch();
            endwin();
        }

        if (PLATFORM_NAME == "windows")
            getch();
    } while (menu != 0);

    return 0;
}