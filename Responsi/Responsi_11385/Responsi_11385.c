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
    string nama;
    int sks;
} MataKuliah;

typedef struct {
    string username;
    string password;
    string nama;
    MataKuliah mata_kuliah[3];
} Mahasiswa;

void initDataMahasiswa(Mahasiswa mahasiswa[]);
int findEmptyMahasiswa(Mahasiswa mahasiswa[]);
int findMahasiswa(Mahasiswa mahasiswa[], string username);
int findEmptyMataKuliah(Mahasiswa mahasiswa[], int index_mahasiswa);
int findMataKuliah(Mahasiswa mahasiswa[], int index_mahasiswa, string nama_mata_kuliah);

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
    int menu;

    string username, password, temp_var;
    string current_user = "-";
    string status_user = "-";

    Mahasiswa mahasiswa[3];
    int index_mahasiswa, index_mata_kuliah;
    initDataMahasiswa(mahasiswa);

    while (true) {
        if (strcmp(current_user, "-") == 0) {
            while (true) {
                clear_screen_f();

                printf("\n---= Login =---\n");
                printf("Username    : ");
                fgets(user_input, STRING_LENGTH, stdin);
                sscanf(user_input, "%[^\n]", username);

                printf("Password    : ");
                fgets(user_input, STRING_LENGTH, stdin);
                sscanf(user_input, "%[^\n]", password);

                if (strcmp(username, "Logout") == 0 && strcmp(password, "Logout") == 0) {
                    printf("\n[ Benidiktus Violaz Morello Anjolie - 210711385 - Praktikum Dasar Pemprograman D ]\n");
                    exit(0);
                }

                if (strcmp(username, "Admin") == 0 && strcmp(password, "Admin") == 0) {
                    printf("\nBerhasil Login sebagai Admin [!]\n");
                    strcpy(current_user, username);
                    strcpy(status_user, "Admin");
                }

                for (i = 0; i < 3; i++) {
                    if (strcmp(username, "-") == 0 && strcmp(password, "-") == 0) {
                        break;
                    }

                    if (strcmp(username, mahasiswa[i].username) == 0 && strcmp(password, mahasiswa[i].password) == 0) {
                        printf("\nBerhasil Login sebagai Mahasiswa [!]\n");
                        strcpy(current_user, username);
                        strcpy(status_user, "Mahasiswa");
                        break;
                    }
                }

                if (strcmp(current_user, "-") != 0) {
                    pause_f();
                    break;
                } else {
                    printf("\nUsername atau Password salah [!]\n");
                    pause_f();
                }
            }
        }

        do {
            if (strcmp(status_user, "Admin") == 0) {
                clear_screen_f();

                printf("\n---= Responsi Admin =---\n");
                printf("[ Selamat datang, %s !]\n", status_user);
                printf("1. Input Mahasiswa\n");
                printf("2. Tampil Mahasiswa\n");
                printf("0. Logout\n");

                printf("\nMenu >> ");
                fgets(user_input, STRING_LENGTH, stdin);
                sscanf(user_input, "%d", &menu);

                switch (menu) {
                    case 1:
                        printf("\n---= Input Mahasiswa =---\n");

                        index_mahasiswa = findEmptyMahasiswa(mahasiswa);

                        if (index_mahasiswa != -1) {
                            while (true) {
                                strcpy(user_input, "");
                                strcpy(temp_var, "");

                                printf("Username      : ");
                                fgets(user_input, STRING_LENGTH, stdin);
                                sscanf(user_input, "%[^\n]", temp_var);

                                if (strcmp(temp_var, "Admin") == 0)
                                    continue;

                                if (strcmp(temp_var, "-") == 0)
                                    continue;

                                if (findMahasiswa(mahasiswa, temp_var) != -1)
                                    continue;

                                if (strcmp(temp_var, "") != 0) {
                                    strcpy(mahasiswa[index_mahasiswa].username, temp_var);
                                    break;
                                }
                            }

                            while (true) {
                                strcpy(user_input, "");
                                strcpy(temp_var, "");

                                printf("Password      : ");
                                fgets(user_input, STRING_LENGTH, stdin);
                                sscanf(user_input, "%[^\n]", temp_var);

                                if (strcmp(temp_var, "") != 0) {
                                    strcpy(mahasiswa[index_mahasiswa].password, temp_var);
                                    break;
                                }
                            }

                            while (true) {
                                strcpy(user_input, "");
                                strcpy(temp_var, "");

                                printf("Nama          : ");
                                fgets(user_input, STRING_LENGTH, stdin);
                                sscanf(user_input, "%[^\n]", temp_var);

                                if (strcmp(temp_var, "") != 0) {
                                    strcpy(mahasiswa[index_mahasiswa].nama, temp_var);
                                    break;
                                }
                            }

                            printf("\nBerhasil Input Mahasiswa [!]\n");
                        } else {
                            printf("\nData Mahasiswa sudah penuh [!]\n");
                        }

                        break;

                    case 2:
                        printf("\n---= Tampil Mahasiswa =---\n");

                        for (i = 0; i < 3; i++) {
                            printf("\n[ Mahasiswa %d ]\n", i + 1);
                            printf("Username     : %s\n", mahasiswa[i].username);
                            printf("Password     : %s\n", mahasiswa[i].password);
                            printf("Nama         : %s\n", mahasiswa[i].nama);
                        }

                        break;

                    case 0:
                        strcpy(current_user, "-");
                        strcpy(status_user, "-");
                        break;

                    default:
                        printf("\nMenu tidak ditemukan [!]\n");
                        break;
                }
            }

            if (strcmp(status_user, "Mahasiswa") == 0) {
                clear_screen_f();

                index_mahasiswa = findMahasiswa(mahasiswa, current_user);

                printf("\n---= Responsi Mahasiswa =---\n");
                printf("[ Selamat datang, %s !]\n", mahasiswa[index_mahasiswa].nama);
                printf("1. Input Mata Kuliah\n");
                printf("2. Hapus Mata Kuliah\n");
                printf("3. Tampil Data Mahasiswa\n");

                printf("0. Logout\n");

                printf("\nMenu >> ");
                fgets(user_input, STRING_LENGTH, stdin);
                sscanf(user_input, "%d", &menu);

                switch (menu) {
                    case 1:
                        printf("\n---= Input Mata Kuliah =---\n");

                        index_mata_kuliah = findEmptyMataKuliah(mahasiswa, index_mahasiswa);

                        if (index_mata_kuliah != -1) {
                            while (true) {
                                strcpy(user_input, "");
                                strcpy(temp_var, "");

                                printf("Nama Mata Kuliah    : ");
                                fgets(user_input, STRING_LENGTH, stdin);
                                sscanf(user_input, "%[^\n]", temp_var);

                                if (strcmp(temp_var, "-") == 0) {
                                    continue;
                                }

                                if (strcmp(temp_var, "") == 0) {
                                    continue;
                                }

                                strcpy(mahasiswa[index_mahasiswa].mata_kuliah[index_mata_kuliah].nama, temp_var);
                                break;
                            }

                            while (true) {
                                strcpy(user_input, "");

                                printf("Jumlah SKS          : ");
                                fgets(user_input, STRING_LENGTH, stdin);
                                sscanf(user_input, "%d", &mahasiswa[index_mahasiswa].mata_kuliah[index_mata_kuliah].sks);

                                if (mahasiswa[index_mahasiswa].mata_kuliah[index_mata_kuliah].sks >= 1) {
                                    break;
                                }
                            }

                            printf("\nBerhasil Input Mata Kuliah [!]\n");

                        } else {
                            printf("\nData Mata Kuliah sudah penuh [!]\n");
                        }
                        break;

                    case 2:
                        printf("\n---= Hapus Mata Kuliah =---\n");

                        while (true) {
                            strcpy(user_input, "");
                            strcpy(temp_var, "");

                            printf("Nama Mata Kuliah : ");
                            fgets(user_input, STRING_LENGTH, stdin);
                            sscanf(user_input, "%[^\n]", temp_var);

                            if (strcmp(temp_var, "-") == 0) {
                                continue;
                            }

                            if (strcmp(temp_var, "") == 0) {
                                continue;
                            }

                            break;
                        }

                        index_mata_kuliah = findMataKuliah(mahasiswa, index_mahasiswa, temp_var);

                        if (index_mata_kuliah != -1) {
                            strcpy(mahasiswa[index_mahasiswa].mata_kuliah[index_mata_kuliah].nama, "-");
                            mahasiswa[index_mahasiswa].mata_kuliah[index_mata_kuliah].sks = 0;

                            printf("\nBerhasil Hapus Mata Kuliah [!]\n");
                        } else {
                            printf("\nMata Kuliah tidak ditemukan [!]\n");
                        }

                        break;

                    case 3:
                        printf("\n---= Tampil Data Mahasiswa =---\n");

                        printf("\n[ Data Mahasiswa ]\n");
                        printf("Username     : %s\n", mahasiswa[index_mahasiswa].username);
                        printf("Password     : %s\n", mahasiswa[index_mahasiswa].password);
                        printf("Nama         : %s\n", mahasiswa[index_mahasiswa].nama);

                        for (i = 0; i < 3; i++) {
                            printf("\n\t[ Mata Kuliah %d ]\n", i + 1);
                            printf("\tNama Mata Kuliah : %s\n", mahasiswa[index_mahasiswa].mata_kuliah[i].nama);

                            if (mahasiswa[index_mahasiswa].mata_kuliah[i].sks == 0)
                                printf("\tSKS              : -\n");
                            else
                                printf("\tSKS              : %d\n", mahasiswa[index_mahasiswa].mata_kuliah[i].sks);
                        }

                        break;

                    case 0:
                        strcpy(current_user, "-");
                        strcpy(status_user, "-");
                        break;

                    default:
                        printf("\nMenu tidak ditemukan [!]\n");
                        break;
                }
            }

            pause_f();
        } while (menu != 0);
    }

    return 0;
}

void initDataMahasiswa(Mahasiswa mahasiswa[]) {
    int i, j;

    for (i = 0; i < 3; i++) {
        strcpy(mahasiswa[i].username, "-");
        strcpy(mahasiswa[i].password, "-");
        strcpy(mahasiswa[i].nama, "-");

        for (j = 0; j < 3; j++) {
            strcpy(mahasiswa[i].mata_kuliah[j].nama, "-");
            mahasiswa[i].mata_kuliah[j].sks = 0;
        }
    }
}

int findEmptyMahasiswa(Mahasiswa mahasiswa[]) {
    int i;

    for (i = 0; i < 3; i++) {
        if (strcmp(mahasiswa[i].username, "-") == 0)
            return i;
    }

    return -1;
}

int findMahasiswa(Mahasiswa mahasiswa[], string username) {
    int i;

    for (i = 0; i < 3; i++) {
        if (strcmp(mahasiswa[i].username, username) == 0)
            return i;
    }

    return -1;
}

int findEmptyMataKuliah(Mahasiswa mahasiswa[], int index_mahasiswa) {
    int i;

    for (i = 0; i < 3; i++) {
        if (mahasiswa[index_mahasiswa].mata_kuliah[i].sks == 0)
            return i;
    }

    return -1;
}

int findMataKuliah(Mahasiswa mahasiswa[], int index_mahasiswa, string nama_mata_kuliah) {
    int i;

    for (i = 0; i < 3; i++) {
        if (strcmp(mahasiswa[index_mahasiswa].mata_kuliah[i].nama, nama_mata_kuliah) == 0)
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