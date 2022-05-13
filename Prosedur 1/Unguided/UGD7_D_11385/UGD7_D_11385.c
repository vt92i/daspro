#if defined(_WIN32) || defined(_WIN64)
    #define PLATFORM_NAME "windows"
    #include <conio.h>
#endif

#if defined(__linux__)
    #define PLATFORM_NAME "linux"
    #include <ncurses.h>
#endif

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char string[64];

void tampilMenu();

void statusPermainan(int jumlah_tebakan, int min_range, int max_range);
void setJumlahTebakan(int *jumlah_tebakan, int min_range, int max_range);
void setRentangAngka(int jumlah_tebakan, int *min_range, int *max_range);
void mulaiPermainan();

void clear_screen_f();
void pause_f();

// Benidiktus Violaz Morello Anjolie2
// 210711385
// D

int main(int argc, char const *argv[]) {
    if (PLATFORM_NAME == "linux") {
        initscr();
        getch();
        endwin();
    }

    int jumlah_tebakan;
    int min_range, max_range;

    jumlah_tebakan = 3;
    min_range = 1;
    max_range = 10;

    srand(time(NULL));

    int menu;

    do {
        tampilMenu();
        printf("\nMenu >> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                break;

            case 2:
                statusPermainan(jumlah_tebakan, min_range, max_range);
                break;

            case 3:
                break;

            case 4:
                setJumlahTebakan(&jumlah_tebakan, min_range, max_range);
                break;

            case 5:
                setRentangAngka(jumlah_tebakan, &min_range, &max_range);
                break;

            case 6:
                mulaiPermainan(jumlah_tebakan, min_range, max_range);
                break;

            case 0:
                printf("\n");
                printf("[!] Program keluar [!] \n");
                printf("[!] Benidiktus Violaz Morello Anjolie - 210711385 [!] \n");

                break;

            default:
                printf("\nMenu tidak tersedia[!]\n");
                break;
        }

        pause_f();

    } while (menu != 0);

    return 0;
}

void tampilMenu() {
    clear_screen_f();

    printf("\n---= Tugas/Bonus Prosedur 1 =---");
    printf("\n[1] Tampil selisih jarak");
    printf("\n[2] Status permainan");
    printf("\n[3] History permainan");

    printf("\n");
    printf("\n---= UGD Prosedur 1 =---");
    printf("\n[4] Set jumlah tebakan");
    printf("\n[5] Set rentang permainan (range angka)");
    printf("\n[6] Mulai permainan");
    printf("\n---------------------");

    printf("\n[0] Keluar\n");
}

void statusPermainan(int jumlah_tebakan, int min_range, int max_range) {
    printf("\n---= Status Permainan =---\n");
    printf("Jumlah tebakan \t : %d\n", jumlah_tebakan);
    printf("Min range \t : %d\n", min_range);
    printf("Max range \t : %d\n", max_range);
}

void setJumlahTebakan(int *jumlah_tebakan, int min_range, int max_range) {
    printf("\n---- Set Jumlah Tebakan ----\n");

    int run = 1;
    int jumlah_tebakan_tmp;

    int range = max_range - min_range + 1;

    while (run) {
        printf("\nInput jumlah tebakan \t : ");
        scanf("%d", &jumlah_tebakan_tmp);
        if (jumlah_tebakan_tmp <= range) {
            printf("Jumlah tebakan berhasil diupdate[!]\n");
            *jumlah_tebakan = jumlah_tebakan_tmp;
            break;
        } else {
            printf("Jumlah tebakan tidak boleh lebih dari range (%d) [!]\n", range);
        }
    }
}

void setRentangAngka(int jumlah_tebakan, int *min_range, int *max_range) {
    printf("\n---- Set Rentang Permainan ----\n");

    int run = 1;

    int max_range_tmp;
    int min_range_tmp;
    int range_tmp;

    while (run) {
        printf("\nInput rentang min \t : ");
        scanf("%d", &min_range_tmp);
        printf("Input rentang min berhasil diupdate[!]\n");
        *min_range = min_range_tmp;
        break;
    }

    while (run) {
        printf("\nInput rentang max \t : ");
        scanf("%d", &max_range_tmp);
        range_tmp = max_range_tmp - min_range_tmp + 1;
        if (range_tmp >= jumlah_tebakan) {
            printf("Input rentang max berhasil diupdate[!]\n");
            *max_range = max_range_tmp;
            break;
        } else {
            printf("Input rentang max tidak boleh kurang dari jumlah tebakan (%d) [!]\n", jumlah_tebakan);
        }
    }
}

void mulaiPermainan(int jumlah_tebakan, int min_range, int max_range) {
    int kesempatan;
    int randomN;
    int userInput;

    clear_screen_f();
    randomN = rand() % (max_range + 1 - min_range) + min_range;

    int range = (max_range - min_range + 1) / 2;

    for (kesempatan = jumlah_tebakan; kesempatan >= 1; kesempatan--) {
        printf("\n---- Tebak Angka ----\n");

        printf("Jumlah tebakan \t : %d\n", jumlah_tebakan);
        printf("Min range \t : %d\n", min_range);
        printf("Max range \t : %d\n", max_range);
        printf("Kesempatan \t : %d\n", kesempatan);

        printf("\nTebak angka \t : ");
        scanf("%d", &userInput);

        if (userInput == randomN) {
            printf("\nTebakan anda benar[!]");
            printf("\nJawabannya adalah %d[!]\n", randomN);
            break;
        } else if (randomN - userInput <= range) {
            printf("\nTebakan anda salah dan semakin dekat[!]");
            printf("\nSilahkan coba lagi[!]\n");
        } else {
            printf("\nTebakan anda salah dan semakin jauh[!]");
            printf("\nSilahkan coba lagi[!]\n");
        }

        if (kesempatan == 1) {
            printf("\nKesempatan habis[!]");
            printf("\nKamu gagal[!]");
            printf("\nJawabannya adalah %d[!]\n", randomN);
            break;
        }
    }
}

void clear_screen_f() {
    if (PLATFORM_NAME == "linux")
        system("clear");

    if (PLATFORM_NAME == "windows")
        system("cls");
}

void pause_f() {
    if (PLATFORM_NAME == "linux") {
        initscr();
        getch();
        endwin();
    }

    if (PLATFORM_NAME == "windows")
        getch();
}