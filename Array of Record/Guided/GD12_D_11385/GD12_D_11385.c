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

#define tampungBuku 2
#define tampungRak 3

#define STRING_LENGTH 64
typedef char string[STRING_LENGTH];

typedef struct {
    string judul_buku;
    string kode_buku;
} Buku;

typedef struct {
    string jenis_rak;
    int no_rak;
    Buku buku[tampungBuku];
} Rak;

void inisialisasiRak(Rak rak[]);
void tampilDataRak(Rak rak[]);

Buku isiDataBuku(string judul_buku, string kode_buku);
Rak isiDataRak(string jenis_rak, int no_rak, Buku buku[]);

int cekEmptyRak(Rak rak[]);
int cekIsiRak(Rak rak[]);
int searchRak(Rak rak[], int no_rak);

void clear_screen_f();
void pause_f();

// Benidiktus Violaz Morello Anjolie4
// 210711385
// D

int main(int argc, char const *argv[]) {
    if (strcmp(PLATFORM_NAME, "linux") == 0)
        pause_f();

    Buku buku[tampungBuku];
    Rak rak[tampungRak];

    string user_input;
    string hyphen = "-";
    string jenis_rak, judul_buku, kode_buku;
    int no_rak;

    int i;
    int menu;

    inisialisasiRak(rak);

    do {
        clear_screen_f();

        printf("\n --= MENU RAK =-- ");
        printf("\n[1]. Isi Data Rak");
        printf("\n[2]. Tampil Data Rak");
        printf("\n[3]. Delete Data Rak");
        printf("\n[0]. Exit");

        printf("\n\nMenu >> ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%d", &menu);

        switch (menu) {
            case 1:
                if (cekEmptyRak(rak) != 1) {
                    printf("\n[ Isi Data Rak ]\n");

                    while (true) {
                        no_rak = -1;

                        printf("No Rak        : ");
                        fgets(user_input, STRING_LENGTH, stdin);
                        sscanf(user_input, "%d", &no_rak);

                        if (no_rak >= 1)
                            break;
                    }

                    while (true) {
                        strcpy(jenis_rak, "");

                        printf("Jenis Rak     : ");
                        fgets(user_input, STRING_LENGTH, stdin);
                        sscanf(user_input, "%[^\n]", jenis_rak);

                        if (strlen(jenis_rak) != 0)
                            break;
                    }

                    printf("\n\t[ Isi Data Buku ]\n");

                    for (i = 0; i < tampungBuku; i++) {
                        printf("\t[ Data Buku Ke-%d ]\n", i + 1);

                        while (true) {
                            strcpy(judul_buku, "");

                            printf("\tJudul Buku    : ");
                            fgets(user_input, STRING_LENGTH, stdin);
                            sscanf(user_input, "%[^\n]", judul_buku);

                            if (strlen(judul_buku) != 0)
                                break;
                        }

                        while (true) {
                            strcpy(kode_buku, "");

                            printf("\tKode Buku     : ");
                            fgets(user_input, STRING_LENGTH, stdin);
                            sscanf(user_input, "%[^\n]", kode_buku);

                            if (strlen(kode_buku) != 0)
                                break;
                        }

                        printf("\n");

                        buku[i] = isiDataBuku(judul_buku, kode_buku);
                    }
                    rak[cekEmptyRak(rak)] = isiDataRak(jenis_rak, no_rak, buku);

                    printf("\nBerhasil Tambah Data [!]\n");
                } else {
                    printf("\nData Full [!]\n");
                }
                break;

            case 2:
                if (cekIsiRak(rak) != -1)
                    tampilDataRak(rak);
                else
                    printf("\nSemua Rak Masih Kosong [!]\n");
                break;

            case 3:
                if (cekIsiRak(rak) != -1) {
                    printf("\nNo rak yang ingin dihapus : ");
                    fgets(user_input, STRING_LENGTH, stdin);
                    sscanf(user_input, "%d", &no_rak);

                    if (searchRak(rak, no_rak) != -1) {
                        for (i = 0; i < tampungBuku; i++) {
                            strcpy(buku[i].judul_buku, "-");
                            strcpy(buku[i].kode_buku, "-");
                        }
                        rak[searchRak(rak, no_rak)] = isiDataRak(hyphen, 0, buku);
                        printf("\nBerhasil Delete Data [!]\n");
                    } else {
                        printf("\nData Tidak Ditemukan [!]\n");
                    }
                } else {
                    printf("\nSemua Rak Masih Kosong [!]\n");
                }
                break;

            case 0:
                printf("\n[!] Have a nice day [!]");
                printf("\n[ Benidiktus Violaz Morello Anjolie - 210711385 - Praktikum Dasar Pemprograman D ]\n");
                break;

            default:
                printf("\n[!] Menu Tidak Ditemukan [!]\n");
                break;
        }
        pause_f();
    } while (menu != 0);
}

void inisialisasiRak(Rak rak[]) {
    int i, j;

    for (i = 0; i < tampungRak; i++) {
        strcpy(rak[i].jenis_rak, "-");
        rak[i].no_rak = 0;

        for (j = 0; j < tampungBuku; j++) {
            strcpy(rak[i].buku[j].judul_buku, "-");
            strcpy(rak[i].buku[j].kode_buku, "-");
        }
    }
}

void tampilDataRak(Rak rak[]) {
    int i, j;
    printf("\n[ DATA RAK ]\n");
    for (i = 0; i < tampungRak; i++) {
        if (strcmp(rak[i].jenis_rak, "-") != 0) {
            printf("No Rak    : %d\n", rak[i].no_rak);
            printf("Jenis Rak : %s\n", rak[i].jenis_rak);

            printf("\t[ DATA BUKU ]\n");
            for (j = 0; j < tampungBuku; j++) {
                printf("\t[ Data Buku Ke-%d ]\n", j + 1);
                printf("\tJudul Buku    : %s\n", rak[i].buku[j].judul_buku);
                printf("\tKode Buku     : %s\n\n", rak[i].buku[j].kode_buku);
            }
        }
    }
}

Buku isiDataBuku(string judul_buku, string kode_buku) {
    Buku B;
    strcpy(B.judul_buku, judul_buku);
    strcpy(B.kode_buku, kode_buku);
    return B;
}

Rak isiDataRak(string jenis_rak, int no_rak, Buku buku[]) {
    Rak rak;
    int i;

    rak.no_rak = no_rak;
    strcpy(rak.jenis_rak, jenis_rak);
    for (i = 0; i < tampungBuku; i++) {
        rak.buku[i] = buku[i];
    }
    return rak;
}

int cekEmptyRak(Rak rak[]) {
    int i;
    for (i = 0; i < tampungRak; i++) {
        if (strcmp(rak[i].jenis_rak, "-") == 0) {
            return i;
        }
    }
    return -1;
}

int cekIsiRak(Rak rak[]) {
    int i;
    for (i = 0; i < tampungRak; i++) {
        if (strcmp(rak[i].jenis_rak, "-") != 0) {
            return i;
        }
    }
    return -1;
}

int searchRak(Rak rak[], int no_rak) {
    int i;
    for (i = 0; i < tampungRak; i++) {
        if (rak[i].no_rak == no_rak)
            return i;
    }
    return -1;
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