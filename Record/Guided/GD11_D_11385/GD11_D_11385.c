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
    string nidn;
} DosenPembimbing;

typedef struct {
    string nama;
    float ipk;
    int umur;
    DosenPembimbing dosBim;
} Mahasiswa;

void initMahasiswa(Mahasiswa *M);
void inputMahasiswa(Mahasiswa *M);
void inputDosenPembimbing(DosenPembimbing *DP);
void tampilMahasiswa(Mahasiswa M);

int tahunLahirMahasiswa(int umur);
int isMahasiswaEmpty(Mahasiswa M);
int isDosBimEmpty(DosenPembimbing);

void clear_screen_f();
void pause_f();

int menu, submenu;
string confirm, user_input;

// Benidiktus Violaz Morello Anjolie4
// 210711385
// D

int main(int argc, char const *argv[]) {
    if (strcmp(PLATFORM_NAME, "linux") == 0)
        pause_f();
    clear_screen_f();

    Mahasiswa M;
    initMahasiswa(&M);

    do {
        clear_screen_f();

        printf("\n ---= Guided Record: Mahasiswa x Dosen Pembimbing =---");
        printf("\n[1] Input Data");
        printf("\n[2] Tampilkan Data");
        printf("\n[3] Edit Data");
        printf("\n[4] Hapus Data");
        printf("\n[0] Exit");

        printf("\nMenu >> ");

        strcpy(confirm, "");
        strcpy(user_input, "");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%d", &menu);

        switch (menu) {
            case 1:
                if (isMahasiswaEmpty(M)) {
                    printf("\n--- Input Data ---\n");
                    inputMahasiswa(&M);

                    while (true) {
                        printf("\nApakah sudah ada dosen pembimbing? (Y/n)");

                        fgets(user_input, STRING_LENGTH, stdin);
                        sscanf(user_input, "%s", confirm);

                        if (strlen(confirm) != 0)
                            break;
                    }

                    if (strcmp(confirm, "Y") == 0) {
                        inputDosenPembimbing(&M.dosBim);
                        printf("\n[+] Berhasil menginput data mahasiswa dan dosen pembimbing [!]\n");
                    } else {
                        printf("\n[+] Berhasil menginput data mahasiswa tanpa dosen pembimbing [!]\n");
                    }
                } else {
                    printf("\n[-] Data mahasiswa sudah diisi [!]\n");
                }
                break;

            case 2:
                printf("\n--- Tampil Data ---\n");
                if (!isMahasiswaEmpty(M))
                    tampilMahasiswa(M);
                else
                    printf("\n[-] Data mahasiswa belum diisi [!]\n");

                break;

            case 3:
                printf("\n--- Ubah Data ---\n");
                if (!isMahasiswaEmpty(M)) {
                    printf("\n[1] Ubah Data");
                    printf("\n[2] Ubah Data Dosen Pembimbing");

                    printf("\nMenu >> ");
                    fgets(user_input, STRING_LENGTH, stdin);
                    sscanf(user_input, "%d", &submenu);

                    switch (submenu) {
                        case 1:
                            printf("\n--- Ubah Data Mahasiswa ---\n");
                            inputMahasiswa(&M);
                            printf("\n[+] Berhasil menginput data mahasiswa [!]\n");
                            break;

                        case 2:
                            printf("\n--- Ubah Data Dosen Pembimbing ---\n");
                            inputDosenPembimbing(&M.dosBim);
                            printf("\n[+] Berhasil menginput data dosen pembimbing [!]\n");
                            break;

                        default:
                            printf("\nMenu tidak tersedia [!]\n");
                            break;
                    }
                } else {
                    printf("\n[-] Data mahasiswa belum diisi [!]\n");
                }
                break;

            case 4:
                printf("\n--- Hapus Data ---\n");
                if (!isMahasiswaEmpty(M)) {
                    while (true) {
                        printf("\nApakah anda yakin benar benar ingin menghapus data? (Y/n)");

                        fgets(user_input, STRING_LENGTH, stdin);
                        sscanf(user_input, "%s", confirm);

                        if (strlen(confirm) != 0)
                            break;
                    }

                    if (strcmp(confirm, "Y") == 0) {
                        initMahasiswa(&M);
                        printf("\n[+] Berhasil menghapus data mahasiswa dan dosen pembimbing [!]\n");
                    } else {
                        printf("\n[-] Batal menghapus data mahasiswa dan dosen pembimbing [!]\n");
                    }
                } else {
                    printf("\n[-] Data mahasiswa belum diisi [!]\n");
                }
                break;

            case 0:
                printf("\n[!] Terima kasih [!]");
                printf("\n[ Benidiktus Violaz Morello Anjolie - 210711385 - Praktikum Dasar Pemprograman D ]\n");
                break;

            default:
                printf("\n[!] Menu tidak tersedia [!]\n");
                break;
        }
        pause_f();
    } while (menu != 0);
}

void initMahasiswa(Mahasiswa *M) {
    strcpy(M->nama, "");
    M->ipk = 0;
    M->umur = 0;

    strcpy(M->dosBim.nama, "");
    strcpy(M->dosBim.nidn, "");
}

void inputMahasiswa(Mahasiswa *M) {
    Mahasiswa input = *M;

    while (true) {
        printf("Nama Mahasiswa          : ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%s", input.nama);

        if (strlen(input.nama) != 0)
            break;
        else
            printf("\n[-] Nama Mahasiswa Tidak Boleh Kosong [!]\n");
    }

    while (true) {
        printf("IPK Mahasiswa           : ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%f", &input.ipk);

        if (input.ipk >= 0.0 && input.ipk <= 4.0)
            break;
        else
            printf("\n[-] IPK Mahasiswa Harus >= 0.0 Dan <= 4.0 [!]\n");
    }

    while (true) {
        printf("Umur Mahasiswa          : ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%d", &input.umur);

        if (input.umur >= 1)
            break;
        else
            printf("\n[-] Umur Mahasiswa Harus >= 1 [!]\n");
    }

    *M = input;
}

void inputDosenPembimbing(DosenPembimbing *DP) {
    DosenPembimbing input = *DP;

    while (true) {
        printf("Nama Dosen Pembimbing   : ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%s", input.nama);

        if (strlen(input.nama) != 0)
            break;
        else
            printf("\n\t[-] Nama Dosen Pembimbing Tidak Boleh Kosong [!]\n");
    }

    while (true) {
        printf("NIDN Dosen Pembimbing   : ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%s", input.nidn);

        if (strlen(input.nidn) != 0)
            break;
        else
            printf("\n\t[-] NIDN Dosen Pembimbing Tidak Boleh Kosong [!]\n");
    }

    *DP = input;
}

void tampilMahasiswa(Mahasiswa M) {
    printf("[*] Data Mahasiswa \n");
    printf("Nama Mahasiswa          : %s \n", M.nama);
    printf("IPK Mahasiswa           : %.2f \n", M.ipk);
    printf("Umur Mahasiswa          : %d \n", M.umur);
    printf("Tahun Lahir             : %d \n", tahunLahirMahasiswa(M.umur));

    if (!isDosBimEmpty(M.dosBim)) {
        printf("\n[*] Dosen Pembimbing \n");
        printf("Nama Dosen Pembimbing   : %s \n", M.dosBim.nama);
        printf("NIDN Dosen Pembimbing   : %s \n", M.dosBim.nidn);
    }
}

int tahunLahirMahasiswa(int umur) {
    return 2022 - umur;
}

int isMahasiswaEmpty(Mahasiswa M) {
    return (strcmp(M.nama, "") == 0);
}

int isDosBimEmpty(DosenPembimbing DP) {
    return (strcmp(DP.nama, "") == 0);
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