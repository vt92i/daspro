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
    string gender;
} AnakAnjing;

typedef struct {
    string nama;
    string jenis;
    string gender;
    int umur;
    string status;
    AnakAnjing anak_anjing[2];
} Anjing;

typedef struct {
    int id;
    string status;
    Anjing anjing[2];
} Kandang;

bool isDataInitialized(Kandang K[]);
void initData(Kandang K[]);

void inputAnjing(Kandang K[], int id, int index_anjing);
void inputAnakAnjing(Kandang K[], int id, int index_anjing);

void pilihAnjing(Kandang K[], int id, int index_anjing);
void pilihSlot(Kandang K[], int id);
void pilihKandang(Kandang K[]);

void tampilIlustrasiKandang(Kandang K[]);
void tampilKandang(Kandang K[], int id);

void clear_screen_f();
void pause_f();

string user_input, confirm;
int menu, submenu;

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

int main(int argc, char const *argv[]) {
    if (strcmp(PLATFORM_NAME, "linux") == 0)
        pause_f();

    Kandang kandang[5];
    int i;

    do {
        clear_screen_f();

        printf("\n---= Manage Your Dogs =---\n");
        printf("1. Init Data\n");
        printf("2. Tambah Data\n");
        printf("3. Tampil Data\n");
        printf("0. Exit\n");

        printf("\nMenu >> ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%d", &menu);

        switch (menu) {
            case 1:
                if (isDataInitialized(kandang)) {
                    printf("\nSudah init data [!]\n");
                } else {
                    printf("\nBerhasil init data [!]\n");
                    initData(kandang);
                }
                break;

            case 2:
                if (!isDataInitialized(kandang)) {
                    printf("\nBelum init data [!]\n");
                } else {
                    pilihKandang(kandang);
                }
                break;

            case 3:
                if (!isDataInitialized(kandang)) {
                    printf("\nBelum init data [!]\n");
                } else {
                    printf("\n---= Tampil Data =---\n");
                    printf("1. Tampil Ilustrasi Kandang\n");
                    printf("2. Tampil Kandang\n");
                    printf("0. Kembali\n");

                    printf("\nMenu >> ");
                    fgets(user_input, STRING_LENGTH, stdin);
                    sscanf(user_input, "%d", &submenu);

                    switch (submenu) {
                        case 1:
                            printf("\n---= Tampil Ilustrasi Kandang =---\n");
                            tampilIlustrasiKandang(kandang);
                            break;

                        case 2:
                            printf("\n---= Tampil Kandang =---\n");
                            for (i = 0; i < 5; i++) {
                                printf("%d. Kandang %d (%s)\n", i + 1, i + 1, kandang[i].status);
                            }
                            printf("0. Kembali\n");

                            printf("\nMenu >> ");
                            fgets(user_input, STRING_LENGTH, stdin);
                            sscanf(user_input, "%d", &submenu);

                            switch (submenu) {
                                case 1:
                                    printf("\n---= Tampil Kandang 1 =---\n");
                                    tampilKandang(kandang, 0);
                                    break;

                                case 2:
                                    printf("\n---= Tampil Kandang 2 =---\n");
                                    tampilKandang(kandang, 1);
                                    break;

                                case 3:
                                    printf("\n---= Tampil Kandang 3 =---\n");
                                    tampilKandang(kandang, 2);
                                    break;

                                case 4:
                                    printf("\n---= Tampil Kandang 4 =---\n");
                                    tampilKandang(kandang, 3);
                                    break;

                                case 5:
                                    printf("\n---= Tampil Kandang 5 =---\n");
                                    tampilKandang(kandang, 4);
                                    break;

                                case 0:
                                    break;

                                default:
                                    printf("\nMenu tidak tersedia [!]\n");
                                    break;
                            }
                            break;

                        case 0:
                            break;

                        default:
                            printf("\nMenu tidak tersedia [!]\n");
                            break;
                    }
                }
                break;

            case 0:
                printf("\n[!] Terima kasih [!]");
                printf("\n[ Benidiktus Violaz Morello Anjolie - 210711385 - Dasar Pemprograman D ]\n");
                break;

            default:
                printf("\nMenu tidak tersedia [!]\n");
                break;
        }
        pause_f();
    } while (menu != 0);
}

bool isDataInitialized(Kandang K[]) {
    int i;
    for (i = 0; i < 5; i++) {
        if (K[i].id != 0 && strlen(K[i].status) != 0)
            continue;
        else
            return false;
    }
    return true;
}

void initData(Kandang K[]) {
    int i, j, k;
    for (i = 0; i < 5; i++) {
        K[i].id = i + 1;
        strcpy(K[i].status, "Available");

        for (j = 0; j < 2; j++) {
            strcpy(K[i].anjing[j].nama, "-");
            strcpy(K[i].anjing[j].jenis, "-");
            strcpy(K[i].anjing[j].gender, "-");
            strcpy(K[i].anjing[j].status, "-");

            K[i].anjing[j].umur = 0;

            for (k = 0; k < 2; k++) {
                strcpy(K[i].anjing[j].anak_anjing[k].nama, "-");
                strcpy(K[i].anjing[j].anak_anjing[k].gender, "-");
            }
        }
    }
}

void inputAnjing(Kandang K[], int id, int index_anjing) {
    printf("[ Anjing %d ]\n", index_anjing + 1);

    while (true) {
        printf("Nama Anjing : ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%[^\n]", K[id].anjing[index_anjing].nama);

        if (strcmp(K[id].anjing[index_anjing].nama, "-") != 0)
            break;
        else
            printf("\nNama Anjing tidak boleh kosong [!]\n");
    }

    while (true) {
        printf("Jenis Anjing : ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%[^\n]", K[id].anjing[index_anjing].jenis);

        if (strcmp(K[id].anjing[index_anjing].jenis, "-") != 0)
            break;
        else
            printf("\nJenis Anjing tidak boleh kosong [!]\n");
    }

    while (true) {
        printf("Gender Anjing : ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%[^\n]", K[id].anjing[index_anjing].gender);

        if (strcmp(K[id].anjing[index_anjing].gender, "-") != 0)
            break;
        else
            printf("\nGender Anjing tidak boleh kosong [!]\n");
    }

    while (true) {
        printf("Umur Anjing : ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%d", &K[id].anjing[index_anjing].umur);

        if (K[id].anjing[index_anjing].umur >= 1)
            break;
        else
            printf("\nUmur Anjing harus >= 1 [!]\n");
    }

    strcpy(K[id].anjing[index_anjing].status, "OK");

    printf("\nBerhasil menambah Anjing [!]\n");
    printf("\n");
}

void inputAnakAnjing(Kandang K[], int id, int index_anjing) {
    int index_anak_anjing, i;

    for (i = 0; i < 2; i++) {
        if (strcmp(K[id].anjing[index_anjing].anak_anjing[i].nama, "-") == 0) {
            index_anak_anjing = i;
            break;
        } else {
            index_anak_anjing = -1;
        }
    }

    if (index_anak_anjing != -1) {
        printf("[ Anjing %d ]\n", index_anjing + 1);
        printf("[ Anak Anjing %d ]\n", index_anak_anjing + 1);

        while (true) {
            printf("Nama Anak Anjing : ");
            fgets(user_input, STRING_LENGTH, stdin);
            sscanf(user_input, "%[^\n]", K[id].anjing[index_anjing].anak_anjing[index_anak_anjing].nama);

            if (strcmp(K[id].anjing[index_anjing].anak_anjing[index_anak_anjing].nama, "-") != 0)
                break;
            else
                printf("\nNama Anak Anjing tidak boleh kosong [!]\n");
        }

        while (true) {
            printf("Gender Anak Anjing : ");
            fgets(user_input, STRING_LENGTH, stdin);
            sscanf(user_input, "%[^\n]", K[id].anjing[index_anjing].anak_anjing[index_anak_anjing].gender);

            if (strcmp(K[id].anjing[index_anjing].anak_anjing[index_anak_anjing].gender, "") != 0)
                break;
            else
                printf("\nGender Anak Anjing tidak boleh kosong [!]\n");
        }

        printf("\nBerhasil menambah Anak Anjing [!]\n");
        printf("\n");
    } else {
        printf("\nAnak anjing sudah Full [!]\n");
    }
}

void pilihAnjing(Kandang K[], int id, int index_anjing) {
    printf("\n---= Tambah Data =---\n");
    printf("1. Tambah Anjing\n");
    printf("2. Tambah Anak Anjing\n");
    printf("0. Kembali\n");

    printf("\nMenu >> ");
    fgets(user_input, STRING_LENGTH, stdin);
    sscanf(user_input, "%d", &submenu);

    switch (submenu) {
        case 1:
            printf("\n---= Tambah Anjing =---\n");
            if (strcmp(K[id].anjing[index_anjing].status, "OK") != 0)
                inputAnjing(K, id, index_anjing);
            else
                printf("\nSudah input Anjing [!]\n");
            break;

        case 2:
            printf("\n---= Tambah Anak Anjing =---\n");
            if (strcmp(K[id].anjing[index_anjing].status, "OK") == 0)
                inputAnakAnjing(K, id, index_anjing);
            else
                printf("\nBelum input Anjing [!]\n");
            break;

        case 0:
            break;

        default:
            printf("\nMenu tidak tersedia [!]\n");
            break;
    }
}

void pilihSlot(Kandang K[], int id) {
    int i;
    printf("\n---= Pilih Slot =---\n");

    for (i = 0; i < 2; i++) {
        printf("%d. Slot %d (%s)\n", i + 1, i + 1, K[id].anjing[i].status);
    }

    printf("\nMenu >> ");
    fgets(user_input, STRING_LENGTH, stdin);
    sscanf(user_input, "%d", &submenu);

    switch (submenu) {
        case 1:
            pilihAnjing(K, id, 0);
            break;

        case 2:
            pilihAnjing(K, id, 1);
            break;

        case 0:
            break;

        default:
            printf("\nMenu tidak tersedia [!]\n");
            break;
    }
}

void pilihKandang(Kandang K[]) {
    int i, j;

    printf("\n---= Pilih Kandang =---\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            if (strcmp(K[i].anjing[j].status, "OK") == 0)
                strcpy(K[i].status, "Full");
            else
                strcpy(K[i].status, "Available");
        }
        printf("%d. Kandang %d (%s)\n", i + 1, i + 1, K[i].status);
    }
    printf("0. Kembali\n");

    printf("\nMenu >> ");
    fgets(user_input, STRING_LENGTH, stdin);
    sscanf(user_input, "%d", &submenu);

    switch (submenu) {
        case 1:
            pilihSlot(K, 0);
            break;

        case 2:
            pilihSlot(K, 1);
            break;

        case 3:
            pilihSlot(K, 2);
            break;

        case 4:
            pilihSlot(K, 3);
            break;

        case 5:
            pilihSlot(K, 4);
            break;

        case 0:
            break;

        default:
            printf("\nMenu tidak tersedia [!]\n");
            break;
    }
}

void tampilIlustrasiKandang(Kandang K[]) {
    int i, j, k;

    for (i = 0; i < 5; i++) {
        printf("%d. Kandang %d\n", i + 1, i + 1);

        for (j = 0; j < 2; j++) {
            printf("\t[ Anjing %d ]\n", j + 1);
            printf("\tNama Anjing   : %s\n", K[i].anjing[j].nama);
            printf("\tJenis Anjing  : %s\n", K[i].anjing[j].jenis);
            printf("\tGender Anjing : %s\n", K[i].anjing[j].gender);

            if (K[i].anjing[j].umur == 0)
                printf("\tUmur Anjing   : -\n");
            else
                printf("\tUmur Anjing   : %d\n", K[i].anjing[j].umur);

            for (k = 0; k < 2; k++) {
                printf("\t\t[ Anak Anjing %d ]\n", k + 1);
                printf("\t\tNama Anak Anjing    : %s\n", K[i].anjing[j].anak_anjing[k].nama);
                printf("\t\tGender Anak Anjing  : %s\n", K[i].anjing[j].anak_anjing[k].gender);
                printf("\n");
            }

            printf("\n");
        }
    }
}

void tampilKandang(Kandang K[], int id) {
    int i, j, k;
    i = id;

    printf("[ Kandang %d ]\n", i + 1);

    for (j = 0; j < 2; j++) {
        printf("\t[ Anjing %d ]\n", j + 1);
        printf("\tNama Anjing   : %s\n", K[i].anjing[j].nama);
        printf("\tJenis Anjing  : %s\n", K[i].anjing[j].jenis);
        printf("\tGender Anjing : %s\n", K[i].anjing[j].gender);

        if (K[i].anjing[j].umur == 0)
            printf("\tUmur Anjing   : -\n");
        else
            printf("\tUmur Anjing   : %d\n", K[i].anjing[j].umur);

        for (k = 0; k < 2; k++) {
            printf("\t\t[ Anak Anjing %d ]\n", k + 1);
            printf("\t\tNama Anak Anjing    : %s\n", K[i].anjing[j].anak_anjing[k].nama);
            printf("\t\tGender Anak Anjing  : %s\n", K[i].anjing[j].anak_anjing[k].gender);
            printf("\n");
        }

        printf("\n");
    }
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