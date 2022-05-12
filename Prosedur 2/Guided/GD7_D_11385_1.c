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

void tukarNilai(int *N1, int *N2);
void kuadrat(int *N);

void clear_screen_f();
void pause_f();

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

int main(int argc, char const *argv[]) {
    int nilai1, nilai2;

    printf("\n---= GUIDED PROSEDUR 2 =---\n");
    printf("[ Input Data ] \n");
    printf("Input Nilai 1 : ");
    scanf("%d", &nilai1);
    printf("Input Nilai 2 : ");
    scanf("%d", &nilai2);
    printf("\nBerhasil input[!]\n");
    pause_f();
    clear_screen_f();

    printf("\n---= GUIDED PROSEDUR 2 =---\n");
    printf("[ Nilai Awal ] \n");
    printf("Nilai 1 : %d \n", nilai1);
    printf("Nilai 2 : %d \n", nilai2);

    kuadrat(&nilai1);
    kuadrat(&nilai2);

    printf("\n");
    printf("[ Nilai Setelah Dikuadratkan ] \n");
    printf("Nilai 1 : %d \n", nilai1);
    printf("Nilai 2 : %d \n", nilai2);

    tukarNilai(&nilai1, &nilai2);

    printf("\n");
    printf("[ Nilai Setelah Nilai1 dan Nilai2 Ditukar ] \n");
    printf("Nilai 1 : %d \n", nilai1);
    printf("Nilai 2 : %d \n", nilai2);

    return 0;
}

void tukarNilai(int *N1, int *N2) {
    int tmp;

    tmp = *N1;
    *N1 = *N2;
    *N2 = tmp;
}

void kuadrat(int *N) {
    *N = (*N) * (*N);
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