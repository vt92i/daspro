#if defined(_WIN32) || defined(_WIN64)
    #define PLATFORM_NAME "windows"
    #include <conio.h>
#endif

#if defined(__linux__)
    #define PLATFORM_NAME "linux"
    #include <ncurses.h>
#endif

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define phi 3.14
typedef char string[64];

float volumeTabung(float jari, float tinggi);
float luasPermukaanTabung(float jari, float tinggi);
float bilanganKuadrat(float bilangan);

void clear_screen_f();
void pause_f();

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

int main(int argc, char const *argv[]) {
    if (strcmp(PLATFORM_NAME, "linux") == 0) {
        initscr();
        getch();
        endwin();
    }

    int menu;
    float jari, tinggi;
    string answer;

    printf("\n---- Verifikasi ----\n");
    printf("Apakah kamu manusia? (Y/n)");
    scanf("%s", answer);

    if (strcmp(answer, "Y") == 0) {
        printf("\n");
        printf("Selamat anda adalah Manusia[!]\n");
        printf("Press any key to continue[!]\n");
        pause_f();

        do {
            clear_screen_f();

            printf("\n---= Guided Fungsi =---");
            printf("\n[1] Input data tabung");
            printf("\n[2] Hitung volume tabung");
            printf("\n[3] Hitung luas permukaan tabung");
            printf("\n[0] Exit");
            printf("\n---------------------");
            printf("\nMenu >> ");

            scanf("%d", &menu);
            switch (menu) {
                case 1:
                    printf("\n---- Input Data Tabung ----\n");
                    printf("Jari Jari \t : ");
                    scanf("%f", &jari);

                    printf("Tinggi \t\t : ");
                    scanf("%f", &tinggi);

                    printf("\nInput data berhasil[!]\n");
                    break;

                case 2:
                    printf("\n---- Menghitung Volume Tabung ----\n");
                    printf("===========================\n");
                    printf("Volume tabung adalah %.2f\n", volumeTabung(jari, tinggi));
                    printf("===========================\n");
                    break;

                case 3:
                    printf("\n---- Menghitung Luas Permukaan Tabung ----\n");
                    printf("===========================\n");
                    printf("Luas permukaan tabung adalah %.2f\n", luasPermukaanTabung(jari, tinggi));
                    printf("===========================\n");
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

            printf("\nPress any key to continue[!]\n");
            pause_f();

        } while (menu != 0);
    }

    if (strcmp(answer, "n") == 0) {
        printf("\nExiting program[!]");
        printf("\nKernel Panic[!] \n");
    }

    printf("\nSampai jumpa di UGD[!]\n");

    return 0;
}

float volumeTabung(float jari, float tinggi) {
    return phi * bilanganKuadrat(jari) * tinggi;
}

float luasPermukaanTabung(float jari, float tinggi) {
    return (2 * phi * bilanganKuadrat(jari)) + (2 * phi * jari * tinggi);
}

float bilanganKuadrat(float bilangan) {
    return bilangan * bilangan;
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