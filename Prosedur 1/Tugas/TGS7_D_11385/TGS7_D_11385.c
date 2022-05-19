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

void initData(int *jumlah_tebakan, int *min_range, int *max_range, bool *sudah_bermain, bool *status_permainan_terakhir, bool *tampil_selisih_jarak, int *nilai_tebakan, int *tebakan_ke);
void tampilMenu();

void tampilSelisihJarak(bool *tampil_selisih_jarak);
void statusPermainan(int jumlah_tebakan, int min_range, int max_range, bool tampil_selisih_jarak);
void historyPermainan(int jumlah_tebakan, int min_range, int max_range, bool sudah_bermain, bool status_permainan_terakhir, int nilai_tebakan, int tebakan_ke);
void setJumlahTebakan(int *jumlah_tebakan, int min_range, int max_range);
void setRentangAngka(int jumlah_tebakan, int *min_range, int *max_range);
void mulaiPermainan(int jumlah_tebakan, int min_range, int max_range, bool *sudah_bermain, bool *status_permainan_terakhir, bool tampil_selisih_jarak, int *nilai_tebakan, int *tebakan_ke);

void exitProgram();
void menuErrorHandler();

void clear_screen_f();
void pause_f();

// Benidiktus Violaz Morello Anjolie2
// 210711385
// D

int main(int argc, char const *argv[]) {
    if (strcmp(PLATFORM_NAME, "linux") == 0) {
        initscr();
        getch();
        endwin();
    }

    srand(time(NULL));

    int menu;
    int jumlah_tebakan;
    int min_range, max_range;
    int nilai_tebakan, tebakan_ke;

    bool sudah_bermain;
    bool status_permainan_terakhir;
    bool tampil_selisih_jarak;

    initData(&jumlah_tebakan, &min_range, &max_range, &sudah_bermain, &status_permainan_terakhir, &tampil_selisih_jarak, &nilai_tebakan, &tebakan_ke);

    do {
        tampilMenu();
        printf("\nMenu >> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                tampilSelisihJarak(&tampil_selisih_jarak);
                break;

            case 2:
                statusPermainan(jumlah_tebakan, min_range, max_range, tampil_selisih_jarak);
                break;

            case 3:
                historyPermainan(jumlah_tebakan, min_range, max_range, sudah_bermain, status_permainan_terakhir, nilai_tebakan, tebakan_ke);
                break;

            case 4:
                setJumlahTebakan(&jumlah_tebakan, min_range, max_range);
                break;

            case 5:
                setRentangAngka(jumlah_tebakan, &min_range, &max_range);
                break;

            case 6:
                mulaiPermainan(jumlah_tebakan, min_range, max_range, &sudah_bermain, &status_permainan_terakhir, tampil_selisih_jarak, &nilai_tebakan, &tebakan_ke);
                break;

            case 0:
                exitProgram();
                break;

            default:
                menuErrorHandler();
                break;
        }

        pause_f();

    } while (menu != 0);

    return 0;
}

void initData(int *jumlah_tebakan, int *min_range, int *max_range, bool *sudah_bermain, bool *status_permainan_terakhir, bool *tampil_selisih_jarak, int *nilai_tebakan, int *tebakan_ke) {
    *jumlah_tebakan = 1;
    *min_range = 1;
    *max_range = 10;

    *sudah_bermain = false;
    *status_permainan_terakhir = false;
    *tampil_selisih_jarak = false;

    *nilai_tebakan = 0;
    *tebakan_ke = 0;
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

void tampilSelisihJarak(bool *tampil_selisih_jarak) {
    string konfirm;

    printf("\n---= Set Tampil Selisih =---\n");

    while (true) {
        printf("\nTampilkan selisih jarak? (Y/n)");
        scanf("%s", konfirm);

        if (strcmp(konfirm, "Y") == 0) {
            *tampil_selisih_jarak = true;
            printf("\nMenampilkan selisih jarak[!]\n");
            break;
        } else if (strcmp(konfirm, "n") == 0) {
            *tampil_selisih_jarak = false;
            printf("\nMenyembunyikan selisih jarak[!]\n");
            break;
        } else {
            printf("\nInput tidak valid[!]\n");
        }
    }
}

void statusPermainan(int jumlah_tebakan, int min_range, int max_range, bool tampil_selisih_jarak) {
    printf("\n---= Status Permainan =---\n");
    printf("Tampil selisih jarak \t : %d\n", tampil_selisih_jarak);
    printf("Jumlah tebakan \t\t : %d\n", jumlah_tebakan);
    printf("Min range \t\t : %d\n", min_range);
    printf("Max range \t\t : %d\n", max_range);
}

void historyPermainan(int jumlah_tebakan, int min_range, int max_range, bool sudah_bermain, bool status_permainan_terakhir, int nilai_tebakan, int tebakan_ke) {
    if (sudah_bermain) {
        printf("\n---= History Permainan =---\n");
        if (status_permainan_terakhir)
            printf("Status permainan terakhir \t : Menang\n");
        else
            printf("Status permainan terakhir \t : Kalah\n");
        printf("Jumlah tebakan \t\t\t : %d\n", jumlah_tebakan);
        printf("Min range \t\t\t : %d\n", min_range);
        printf("Max range \t\t\t : %d\n", max_range);
        printf("Nilai tebakan \t\t\t : %d\n", nilai_tebakan);
        if (status_permainan_terakhir)
            printf("Benar ditebakan ke \t\t : %d\n", tebakan_ke);
    } else {
        printf("\n---= History Permainan =---\n");
        printf("Belum pernah main[!]\n");
    }
}

void setJumlahTebakan(int *jumlah_tebakan, int min_range, int max_range) {
    printf("\n---- Set Jumlah Tebakan ----\n");

    int jumlah_tebakan_tmp;
    int range = max_range - min_range + 1;

    while (true) {
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

    int max_range_tmp;
    int min_range_tmp;
    int range_tmp;

    while (true) {
        printf("\nInput rentang min \t : ");
        scanf("%d", &min_range_tmp);
        printf("Input rentang min berhasil diupdate[!]\n");
        *min_range = min_range_tmp;
        break;
    }

    while (true) {
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

void mulaiPermainan(int jumlah_tebakan, int min_range, int max_range, bool *sudah_bermain, bool *status_permainan_terakhir, bool tampil_selisih_jarak, int *nilai_tebakan, int *tebakan_ke) {
    int kesempatan;
    int userInput;

    clear_screen_f();
    *nilai_tebakan = rand() % (max_range + 1 - min_range) + min_range;
    *tebakan_ke = 1;

    int range = (max_range - min_range + 1) / 4;

    for (kesempatan = jumlah_tebakan; kesempatan >= 1; kesempatan--) {
        printf("\n---- Tebak Angka ----\n");

        printf("Jumlah tebakan \t : %d\n", jumlah_tebakan);
        printf("Min range \t : %d\n", min_range);
        printf("Max range \t : %d\n", max_range);
        printf("Kesempatan \t : %d\n", kesempatan);

        printf("\nTebak angka \t : ");
        scanf("%d", &userInput);

        if (userInput == *nilai_tebakan) {
            printf("\nTebakan anda benar[!]");
            printf("\nJawabannya adalah %d[!]", *nilai_tebakan);
            if (tampil_selisih_jarak)
                printf("\nSelisih adalah %d\n", *nilai_tebakan - userInput);
            printf("\nBenar di Tebakan ke %d[!]\n", *tebakan_ke);
            *status_permainan_terakhir = true;
            break;
        } else if (*nilai_tebakan - userInput <= range) {
            printf("\nTebakan anda salah dan semakin dekat[!]");
            if (tampil_selisih_jarak) {
                if (*nilai_tebakan - userInput >= 1)
                    printf("\nSelisih adalah %d\n", *nilai_tebakan - userInput);
                else
                    printf("\nSelisih adalah %d\n", (*nilai_tebakan - userInput) * -1);
            }
            printf("\nSilahkan coba lagi[!]\n");
        } else {
            printf("\nTebakan anda salah dan semakin jauh[!]");
            if (tampil_selisih_jarak) {
                if (*nilai_tebakan - userInput >= 1)
                    printf("\nSelisih adalah %d\n", *nilai_tebakan - userInput);
                else
                    printf("\nSelisih adalah %d\n", (*nilai_tebakan - userInput) * -1);
            }
            printf("\nSilahkan coba lagi[!]\n");
        }

        if (kesempatan == 1) {
            printf("\nKesempatan habis[!]");
            printf("\nKamu gagal[!]");
            printf("\nJawabannya adalah %d[!]\n", *nilai_tebakan);
            *status_permainan_terakhir = false;
            break;
        }
        *tebakan_ke += 1;
        pause_f();
        clear_screen_f();
    }
    *sudah_bermain = true;
}

void exitProgram() {
    printf("\n");
    printf("[!] Program keluar [!] \n");
    printf("[!] Benidiktus Violaz Morello Anjolie - 210711385 [!] \n");
}

void menuErrorHandler() {
    printf("\nMenu tidak tersedia[!]\n");
}

void clear_screen_f() {
    if (strcmp(PLATFORM_NAME, "linux") == 0)
        system("clear");

    if (strcmp(PLATFORM_NAME, "windows") == 0)
        system("cls");
}

void pause_f() {
    if (strcmp(PLATFORM_NAME, "linux") == 0) {
        initscr();
        getch();
        endwin();
    }

    if (strcmp(PLATFORM_NAME, "windows") == 0)
        getch();
}