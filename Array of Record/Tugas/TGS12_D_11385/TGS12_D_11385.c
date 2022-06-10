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

#define STRING_LENGTH 64
typedef char string[STRING_LENGTH];

typedef struct {
    string kode_petak;
    string nama_petugas;
    int jumlah_ayam;
    int jumlah_telur_ayam;
} Petak;

typedef struct {
    string nama_peternakan;
    Petak petak[8];
} Peternakan;

bool isDataInitialized(Peternakan P[]);
void initDataPeternakan(Peternakan P[]);

int findPeternakan(Peternakan peternakan[], string nama_peternakan);
int findPetak(Peternakan peternakan[], int index_peternakan, string kode_petak);
int findEmptyPetak(Peternakan peternakan[], int index_peternakan);
bool isPetakEmpty(Peternakan peternakan[], int index_peternakan);

void clear_screen_f();
void pause_f();

// Benidiktus Violaz Morello Anjolie4
// 210711385
// D

string user_input;

int main(int argc, char const *argv[]) {
    if (strcmp(PLATFORM_NAME, "linux") == 0)
        pause_f();

    int i, j, k;
    int menu, submenu;

    int index_peternakan, index_petak;
    string nama_peternakan, kode_petak;
    string temp_var;

    Peternakan peternakan[2];
    initDataPeternakan(peternakan);

    do {
        clear_screen_f();

        printf("\n---= Peternakan Vila =---\n");
        printf("1. Set Nama Peternakan\n");
        printf("2. Set Data Peternakan\n");
        printf("3. Tampil Data Peternakan\n");
        printf("0. Exit\n");

        printf("\nMenu >> ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%d", &menu);

        switch (menu) {
            case 1:
                if (!isDataInitialized(peternakan)) {
                    printf("\n---= Set Nama Peternakan =---\n");

                    for (i = 0; i < 2; i++) {
                        while (true) {
                            strcpy(temp_var, "");

                            printf("Nama Peternakan %d : ", i + 1);
                            fgets(user_input, STRING_LENGTH, stdin);
                            sscanf(user_input, "%[^\n]", temp_var);

                            if (strlen(temp_var) == 0)
                                continue;

                            index_peternakan = findPeternakan(peternakan, temp_var);

                            if (index_peternakan == -1) {
                                strcpy(peternakan[i].nama_peternakan, temp_var);
                                break;
                            } else {
                                printf("\nNama Peternakan harus Unique [!]\n");
                            }
                        }
                    }

                    printf("\nBerhasil Set Nama Peternakan [!]\n");
                } else {
                    printf("\nAnda telah melakukan Set Nama Peternakan [!]\n");
                }

                break;

            case 2:
                printf("\n---= Set Data Peternakan =---\n");

                while (true) {
                    strcpy(nama_peternakan, "");

                    printf("Nama Peternakan : ");
                    fgets(user_input, STRING_LENGTH, stdin);
                    sscanf(user_input, "%[^\n]", nama_peternakan);

                    if (strlen(nama_peternakan) != 0)
                        break;
                }

                index_peternakan = findPeternakan(peternakan, nama_peternakan);

                if (index_peternakan == -1) {
                    printf("\nNama Peternakan tidak ditemukan [!]\n");
                    break;
                }

                printf("\n");
                printf("1. Mengisi Petak\n");
                printf("2. Edit Petak\n");
                printf("3. Swap Petak\n");
                printf("0. Kembali\n");

                printf("\nMenu >> ");
                fgets(user_input, STRING_LENGTH, stdin);
                sscanf(user_input, "%d", &submenu);

                switch (submenu) {
                    case 1:
                        printf("\n---= Mengisi Petak =---\n");

                        index_petak = findEmptyPetak(peternakan, index_peternakan);

                        if (index_petak == -1) {
                            printf("\nSemua Petak sudah penuh [!]\n");
                            break;
                        }

                        while (true) {
                            strcpy(temp_var, "");

                            printf("Kode Petak          : ");
                            fgets(user_input, STRING_LENGTH, stdin);
                            sscanf(user_input, "%[^\n]", temp_var);

                            if (strlen(temp_var) == 0)
                                continue;

                            int index_petak_temp = findPetak(peternakan, index_peternakan, temp_var);

                            if (index_petak_temp == -1) {
                                strcpy(peternakan[index_peternakan].petak[index_petak].kode_petak, temp_var);
                                break;
                            } else {
                                printf("\nKode Petak harus Unique [!]\n");
                            }
                        }

                        while (true) {
                            strcpy(temp_var, "");

                            printf("Nama Petugas        : ");
                            fgets(user_input, STRING_LENGTH, stdin);
                            sscanf(user_input, "%[^\n]", temp_var);

                            if (strlen(temp_var) != 0) {
                                strcpy(peternakan[index_peternakan].petak[index_petak].nama_petugas, temp_var);
                                break;
                            }
                        }

                        while (true) {
                            peternakan[index_peternakan].petak[index_petak].jumlah_ayam = -1;

                            printf("Jumlah Ayam         : ");
                            fgets(user_input, STRING_LENGTH, stdin);
                            sscanf(user_input, "%d", &peternakan[index_peternakan].petak[index_petak].jumlah_ayam);

                            if (peternakan[index_peternakan].petak[index_petak].jumlah_ayam >= 0) {
                                break;
                            }
                        }

                        while (true) {
                            peternakan[index_peternakan].petak[index_petak].jumlah_telur_ayam = -1;

                            printf("Jumlah Telur Ayam   : ");
                            fgets(user_input, STRING_LENGTH, stdin);
                            sscanf(user_input, "%d", &peternakan[index_peternakan].petak[index_petak].jumlah_telur_ayam);

                            if (peternakan[index_peternakan].petak[index_petak].jumlah_telur_ayam >= 0) {
                                break;
                            }
                        }

                        printf("\nBerhasil mengisi Data Petak [!]\n");

                        break;

                    case 2:
                        printf("\n---= Edit Petak =---\n");

                        if (isPetakEmpty(peternakan, index_peternakan)) {
                            printf("\nSemua Petak masih kosong [!]\n");
                            break;
                        }

                        while (true) {
                            strcpy(kode_petak, "");

                            printf("Kode Petak (Lama)          : ");
                            fgets(user_input, STRING_LENGTH, stdin);
                            sscanf(user_input, "%[^\n]", kode_petak);

                            if (strlen(kode_petak) == 0)
                                continue;

                            index_petak = findPetak(peternakan, index_peternakan, kode_petak);

                            if (index_petak != -1)
                                break;
                            else
                                printf("\nKode Petak tidak ditemukan [!]\n");
                        }

                        while (true) {
                            strcpy(temp_var, "");

                            printf("Kode Petak (Baru)          : ");
                            fgets(user_input, STRING_LENGTH, stdin);
                            sscanf(user_input, "%[^\n]", temp_var);

                            if (strlen(temp_var) == 0)
                                continue;

                            int index_petak_temp = findPetak(peternakan, index_peternakan, temp_var);

                            if (index_petak_temp == -1) {
                                strcpy(peternakan[index_peternakan].petak[index_petak].kode_petak, temp_var);
                                break;
                            } else {
                                printf("\nKode Petak harus Unique [!]\n");
                            }
                        }

                        while (true) {
                            strcpy(temp_var, "");

                            printf("Nama Petugas (Baru)        : ");
                            fgets(user_input, STRING_LENGTH, stdin);
                            sscanf(user_input, "%[^\n]", temp_var);

                            if (strlen(temp_var) != 0) {
                                strcpy(peternakan[index_peternakan].petak[index_petak].nama_petugas, temp_var);
                                break;
                            }
                        }

                        while (true) {
                            peternakan[index_peternakan].petak[index_petak].jumlah_ayam = -1;

                            printf("Jumlah Ayam (Baru)         : ");
                            fgets(user_input, STRING_LENGTH, stdin);
                            sscanf(user_input, "%d", &peternakan[index_peternakan].petak[index_petak].jumlah_ayam);

                            if (peternakan[index_peternakan].petak[index_petak].jumlah_ayam >= 0) {
                                break;
                            }
                        }

                        while (true) {
                            peternakan[index_peternakan].petak[index_petak].jumlah_telur_ayam = -1;

                            printf("Jumlah Telur Ayam (Baru)   : ");
                            fgets(user_input, STRING_LENGTH, stdin);
                            sscanf(user_input, "%d", &peternakan[index_peternakan].petak[index_petak].jumlah_telur_ayam);

                            if (peternakan[index_peternakan].petak[index_petak].jumlah_telur_ayam >= 0) {
                                break;
                            }
                        }

                        printf("\nBerhasil Edit Petak [!]\n");

                        break;

                    case 3:
                        printf("\n---= Swap Petak =---\n");

                        if (isPetakEmpty(peternakan, index_peternakan)) {
                            printf("\nSemua Petak masih kosong [!]\n");
                            break;
                        }

                        int n = 0;
                        for (i = 0; i < 8; i++) {
                            if (strcmp(peternakan[index_peternakan].petak[i].kode_petak, "-") != 0)
                                n++;
                        }

                        if (!(n >= 2)) {
                            printf("\nJumlah Petak harus lebih dari 1 [!]\n");
                            break;
                        }

                        int index_petak_1, index_petak_2;

                        while (true) {
                            strcpy(kode_petak, "");

                            printf("Kode Petak 1          : ");
                            fgets(user_input, STRING_LENGTH, stdin);
                            sscanf(user_input, "%[^\n]", kode_petak);

                            if (strlen(kode_petak) == 0)
                                continue;

                            index_petak_1 = findPetak(peternakan, index_peternakan, kode_petak);

                            if (index_petak_1 != -1)
                                break;
                            else
                                printf("\nKode Petak tidak ditemukan [!]\n");
                        }

                        while (true) {
                            strcpy(kode_petak, "");

                            printf("Kode Petak 2          : ");
                            fgets(user_input, STRING_LENGTH, stdin);
                            sscanf(user_input, "%[^\n]", kode_petak);

                            if (strlen(kode_petak) == 0)
                                continue;

                            index_petak_2 = findPetak(peternakan, index_peternakan, kode_petak);

                            if (index_petak_2 == index_petak_1)
                                continue;

                            if (index_petak_2 != -1)
                                break;
                            else
                                printf("\nKode Petak tidak ditemukan [!]\n");
                        }

                        Petak petak_tmp = peternakan[index_peternakan].petak[index_petak_1];
                        peternakan[index_peternakan].petak[index_petak_1] = peternakan[index_peternakan].petak[index_petak_2];
                        peternakan[index_peternakan].petak[index_petak_2] = petak_tmp;

                        printf("\nBerhasil Swap Petak [!]\n");

                        break;

                    case 0:
                        break;
                }

                break;

            case 3:
                printf("\n---= Tampil Data Peternakan =---\n");

                while (true) {
                    strcpy(nama_peternakan, "");

                    printf("Nama Peternakan : ");
                    fgets(user_input, STRING_LENGTH, stdin);
                    sscanf(user_input, "%[^\n]", nama_peternakan);

                    if (strlen(nama_peternakan) != 0)
                        break;
                }

                index_peternakan = findPeternakan(peternakan, nama_peternakan);

                if (index_peternakan == -1) {
                    printf("\nNama Peternakan tidak ditemukan [!]\n");
                    break;
                }

                if (isPetakEmpty(peternakan, index_peternakan)) {
                    printf("\nSemua Petak masih kosong [!]\n");
                    break;
                }

                printf("\n[ Daftar Petak ]\n");
                for (i = 0; i < 8; i++) {
                    printf("[%s] \t", peternakan[index_peternakan].petak[i].kode_petak);

                    if (i == 3 || i == 7)
                        printf("\n");
                }

                printf("\nKode Petak : ");
                fgets(user_input, STRING_LENGTH, stdin);
                sscanf(user_input, "%[^\n]", kode_petak);

                index_petak = findPetak(peternakan, index_peternakan, kode_petak);

                if (index_petak == -1) {
                    printf("\nKode Petak tidak ditemukan [!]\n");
                    break;
                }

                printf("\n[ Data Petak %d]\n", index_petak + 1);
                printf("Kode Petak          : %s\n", peternakan[index_peternakan].petak[index_petak].kode_petak);
                printf("Nama Petugas        : %s\n", peternakan[index_peternakan].petak[index_petak].nama_petugas);
                printf("Jumlah Ayam         : %d\n", peternakan[index_peternakan].petak[index_petak].jumlah_ayam);
                printf("Jumlah Telur Ayam   : %d\n", peternakan[index_peternakan].petak[index_petak].jumlah_telur_ayam);

                break;

            case 0:
                printf("\n[ Benidiktus Violaz Morello Anjolie - 210711385 - Praktikum Dasar Pemprograman D ]\n");
                break;

            default:
                printf("\nMenu tidak ditemukan [!]\n");
                break;
        }
        pause_f();
    } while (menu != 0);
    return 0;
}

bool isDataInitialized(Peternakan P[]) {
    int i;
    for (i = 0; i < 2; i++) {
        if (strcmp(P[i].nama_peternakan, "") != 0)
            continue;
        else
            return false;
    }
    return true;
}

void initDataPeternakan(Peternakan P[]) {
    int i, j;
    for (i = 0; i < 2; i++) {
        strcpy(P[i].nama_peternakan, "");
        for (j = 0; j < 8; j++) {
            strcpy(P[i].petak[j].kode_petak, "-");
            strcpy(P[i].petak[j].nama_petugas, "-");
            P[i].petak[j].jumlah_ayam = 0;
            P[i].petak[j].jumlah_telur_ayam = 0;
        }
    }
}

int findPeternakan(Peternakan peternakan[], string nama_peternakan) {
    int i;

    for (i = 0; i < 2; i++) {
        if (strcmp(peternakan[i].nama_peternakan, nama_peternakan) == 0)
            return i;
    }

    return -1;
}

int findPetak(Peternakan peternakan[], int index_peternakan, string kode_petak) {
    int i;

    for (i = 0; i < 8; i++) {
        if (strcmp(peternakan[index_peternakan].petak[i].kode_petak, kode_petak) == 0)
            return i;
    }

    return -1;
}

int findEmptyPetak(Peternakan peternakan[], int index_peternakan) {
    int i;

    for (i = 0; i < 8; i++) {
        if (strcmp(peternakan[index_peternakan].petak[i].kode_petak, "-") == 0)
            return i;
    }

    return -1;
}

bool isPetakEmpty(Peternakan peternakan[], int index_peternakan) {
    int i;

    for (i = 0; i < 8; i++) {
        if (strcmp(peternakan[index_peternakan].petak[i].kode_petak, "-") != 0)
            return false;
    }

    return true;
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