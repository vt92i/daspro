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

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

int main(int argc, char const *argv[]) {
    int i, j, n;
    int menu, cekMenu;

    cekMenu = 0;

    do {
        if (PLATFORM_NAME == "linux")
            system("clear");

        if (PLATFORM_NAME == "windows")
            system("cls");

        printf("\n---= GUIDED PERULANGAN 2 =---");

        printf("\n[1] Masukan jumlah baris");
        printf("\n[2] Show");
        printf("\n[0] Keluar");
        printf("\n---------------------");

        printf("\nMenu >> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                do {
                    printf("Masukan jumlah baris : ");
                    scanf("%d", &n);

                    if (n < 1) {
                        printf("\nInput tidak boleh kurang dari 1[!]\n");
                    } else {
                        printf("\nBerhasil input data[!]\n");
                        cekMenu++;
                    }
                } while (n < 1);
                break;

            case 2:
                if (cekMenu == 0) {
                    printf("\nHarap input data terlebih dahulu[!]\n");
                } else {
                    printf("\nTampilan bentuk dari jumlah baris [%d]\n", n);
                    printf("\n");

                    char huruf = 'A';

                    for (i = 1; i <= n + 2; i++) {
                        for (j = 1; j <= n + 2; j++) {
                            if (i == 1 || j == 1 || i == n + 2 || j == n + 2)
                                printf(" * ");
                            else
                                printf(" %c ", huruf++);

                            if (huruf > 'Z')
                                huruf = 'A';
                        }
                        printf("\n");
                    }
                }
                break;

            case 0:
                printf("\n[Guided Perulangan 2 | Benidiktus Violaz Morello Anjolie | 210711385 | D]\n");
                break;

            default:
                printf("\nMenu tidak tersedia[!]\n");
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
