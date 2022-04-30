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

void inputBilangan(string description, int *bilangan);
void setBilangan(int *bilanganAsli, int inputan);

void prosedurPenjumlahan(int *hasil, int input1, int input2);
void prosedurPengurangan(int *hasil, int input1, int input2);

void tampilOperasi(string operasi, int angka1, int angka2, int hasil);
void laporanOperasi(bool sudahJumlah, bool sudahkurang, int hasilJumlah, int hasilKurang);

void inputBilanganN(int *temp);
void tebakAngka();

void clear_screen_f();
void pause_f();

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

int main(int argc, char const *argv[]) {
    if (PLATFORM_NAME == "linux") {
        initscr();
        getch();
        endwin();
    }

    srand(time(NULL));

    int menu;
    int temp;
    int i;

    bool sudahInputBilangan = false;
    bool sudahPenjumlahan = false;
    bool sudahPengurangan = false;

    int bilangan1, bilangan2;
    int hasilPenjumlahan, hasilPengurangan;

    bool sudahInputN = false;
    int inputan;
    int n;

    do {
        tampilMenu();
        printf("\nMenu >> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n[Input Bilangan]\n");

                inputBilangan("pertama", &bilangan1);
                inputBilangan("kedua", &bilangan2);

                sudahInputBilangan = true;
                printf("\nBerhasil input bilangan[!]\n");

                break;

            case 2:
                if (!sudahInputBilangan) {
                    printf("\nBelum input bilangan[!]\n");
                } else {
                    printf("\n[Penjumlahan]\n");

                    prosedurPenjumlahan(&hasilPenjumlahan, bilangan1, bilangan2);
                    tampilOperasi("Penjumlahan", bilangan1, bilangan2, hasilPenjumlahan);
                    sudahPenjumlahan = true;
                }

                break;

            case 3:
                if (!sudahInputBilangan) {
                    printf("\nBelum input bilangan[!]\n");
                } else {
                    printf("\n[Pengurangan]\n");

                    prosedurPengurangan(&hasilPengurangan, bilangan1, bilangan2);
                    tampilOperasi("Pengurangan", bilangan1, bilangan2, hasilPengurangan);
                    sudahPengurangan = true;
                }

                break;

            case 4:
                if (!sudahInputBilangan) {
                    printf("\nBelum input bilangan[!]\n");
                } else {
                    printf("\n[Laporan]\n");
                    laporanOperasi(sudahPenjumlahan, sudahPengurangan, hasilPenjumlahan, hasilPengurangan);
                }

                break;

            case 5:
                inputBilanganN(&n);
                sudahInputN = true;
                break;

            case 6:
                tebakAngka();

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

    printf("\n---= GUIDED PROSEDUR 1 =---");

    printf("\n[1] Input bilangan");
    printf("\n[2] Penjumlahan");
    printf("\n[3] Pengurangan");
    printf("\n[4] Laporan");

    printf("\n---------------------");

    printf("\n[5] Input N");
    printf("\n[6] Tebak Angka");

    printf("\n[0] Keluar\n");
}

void inputBilangan(string description, int *bilangan) {
    int temp;

    do {
        printf("\nInput bilangan %s : ", description);
        scanf("%d", &temp);
        if (temp > 0)
            break;
        else
            printf("Input tidak boleh kurang dari 0[!]\n");
    } while (true);

    setBilangan(bilangan, temp);
}

void setBilangan(int *bilanganAsli, int inputan) {
    *bilanganAsli = inputan;
}

void prosedurPenjumlahan(int *hasil, int input1, int input2) {
    *hasil = input1 + input2;
}

void prosedurPengurangan(int *hasil, int input1, int input2) {
    *hasil = input1 - input2;
}

void tampilOperasi(string operasi, int angka1, int angka2, int hasil) {
    printf("%s %d dan %d\n", operasi, angka1, angka2);
    printf("Hasil   : %d\n", hasil);
}

void laporanOperasi(bool sudahJumlah, bool sudahKurang, int hasilJumlah, int hasilKurang) {
    printf("Hasil penjumlahan terakhir : ");
    if (sudahJumlah)
        printf("%d\n", hasilJumlah);
    else
        printf("<belum ada>\n");

    printf("Hasil pengurangan terakhir : ");
    if (sudahKurang)
        printf("%d\n", hasilKurang);
    else
        printf("<belum ada>\n");
}

void inputBilanganN(int *temp) {
    int menu;

    clear_screen_f();

    printf("\n---= Input N =---");

    printf("\n[1] Dari user");
    printf("\n[2] Random [1 - 10]");
    printf("\nMenu >> ");

    scanf("%d", &menu);

    switch (menu) {
        case 1:
            do {
                printf("\nInput N : ");
                scanf("%d", temp);
                if (*temp > 0)
                    break;
                else
                    printf("\nInput tidak boleh negatif[!]\n");
            } while (true);

            printf("\nBerhasil input[!]");
            printf("\nNilai N : %d\n", *temp);

            break;

        case 2:
            *temp = (rand() % (10 - 1 + 1) + 1);
            printf("\nBerhasil input[!]");
            printf("\nNilai N : %d\n", *temp);

            break;

        default:
            printf("\nMenu tidak tersedia[!]\n");
            break;
    }
}

void tebakAngka() {
    int kesempatan;
    int randomN;
    int userInput;

    clear_screen_f();
    randomN = (rand() % (10 - 1 + 1) + 1);

    for (kesempatan = 3; kesempatan >= 1; kesempatan--) {
        printf("\n---- Tebak Angka ----\n");

        printf("Kesempatan  : %d\n", kesempatan);
        printf("Range       : 1 - 10\n");

        if (randomN % 2 == 0)
            printf("Hint        : Genap\n");
        else
            printf("Hint        : Ganjil\n");

        printf("\nBerapa angka mu : ");
        scanf("%d", &userInput);

        if (userInput == randomN) {
            printf("\nTebakan anda benar[!]");
            printf("\nJawabannya adalah %d[!]\n", randomN);
            break;
        } else {
            printf("\nTebakan anda salah[!]");
            printf("\nSilahkan coba lagi[!]\n");
        }

        if (kesempatan == 1) {
            printf("\nKesempatan habis[!]");
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