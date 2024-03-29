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
    string kelas;
} Kamar_11385;

typedef struct {
    string nama;
    string no_induk;
} Dokter_11385;

typedef struct {
    string nama;
    string penyakit;
    int jumlah_obat;
    string daftar_obat[10];
    Kamar_11385 kamar;
    Dokter_11385 dokter;
} Pasien_11385;

void initPasien(Pasien_11385 *pasien);
void inputPasien(Pasien_11385 *pasien);
void inputDokter(Pasien_11385 *pasien);
void inputKamar(Pasien_11385 *pasien);
void tampilData(Pasien_11385 pasien);

void clear_screen_f();
void pause_f();

string user_input, confirm;
int menu, submenu;

// Benidiktus Violaz Morello Anjolie4
// 210711385
// D

int main(int argc, char const *argv[]) {
    if (strcmp(PLATFORM_NAME, "linux") == 0)
        pause_f();

    Pasien_11385 pasien;
    initPasien(&pasien);

    do {
        clear_screen_f();

        printf("\n---= ATMA HOSPITALS =---\n");
        printf("[ Menu Utama ]\n");
        printf("1. Input Data\n");
        printf("2. Tampil Data\n");
        printf("3. Ubah Data\n");
        printf("4. Hapus Data\n");

        printf("\n[ Menu Tugas ]\n");
        printf("5. Input Data\n");
        printf("6. Edit Data\n");
        printf("7. Ubah Data\n");
        printf("8. Hapus Data\n");

        printf("0. Exit\n");

        printf("\nMenu >> ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%d", &menu);

        switch (menu) {
            case 1:
                printf("\n--- Input Pasien ---\n");
                inputPasien(&pasien);
                printf("\n--- Input Dokter ---\n");
                inputDokter(&pasien);

                printf("\nIngin lanjut menginput data Kamar? (Y/n)");
                fgets(user_input, STRING_LENGTH, stdin);
                sscanf(user_input, "%s", confirm);

                if (strcmp(confirm, "Y") == 0) {
                    printf("\n--- Input Kamar ---\n");
                    inputKamar(&pasien);
                }

                printf("\n[+] Data berhasil disimpan [!]\n");
                break;

            case 2:
                if (strlen(pasien.nama) != 0) {
                    printf("\n--- Tampil Data ---\n");
                    tampilData(pasien);
                } else
                    printf("\n[-] Data Pasien kosong [!]\n");
                break;

            case 3:
                if (strlen(pasien.nama) != 0) {
                    printf("\n--- Ubah Data ---\n");
                    printf("1. Ubah Data Pasien\n");
                    printf("2. Ubah Data Dokter\n");
                    printf("3. Ubah Data Kamar\n");

                    printf("\nMenu >> ");
                    fgets(user_input, STRING_LENGTH, stdin);
                    sscanf(user_input, "%d", &submenu);

                    switch (submenu) {
                        case 1:
                            printf("\n--- Ubah Data Pasien ---\n");
                            inputPasien(&pasien);
                            break;

                        case 2:
                            printf("\n--- Ubah Data Dokter ---\n");
                            inputDokter(&pasien);
                            break;

                        case 3:
                            printf("\n--- Ubah Data Kamar ---\n");
                            inputKamar(&pasien);
                            break;

                        default:
                            printf("\nMenu tidak tersedia [!]\n");
                            break;
                    }
                } else
                    printf("\n[-] Data Pasien kosong [!]\n");
                break;

            case 4:
                if (strlen(pasien.nama) != 0) {
                    printf("\n--- Hapus Data ---\n");
                    printf("\nApakah anda yakin ingin semua menghapus data? (Y/n)");
                    fgets(user_input, STRING_LENGTH, stdin);
                    sscanf(user_input, "%s", confirm);

                    if (strcmp(confirm, "Y") == 0) {
                        printf("\n[+] Berhasil menghapus semua data [!]\n");
                        initPasien(&pasien);
                    } else {
                        printf("\n[-] Batal menghapus semua data [!]\n");
                    }
                } else
                    printf("\n[-] Data Pasien kosong [!]\n");
                break;

            case 0:
                printf("\n[!] Terima kasih [!]");
                printf("\n[ Benidiktus Violaz Morello Anjolie - 210711385 - Praktikum Dasar Pemprograman D ]\n");
                break;

            default:
                printf("\nMenu tidak tersedia [!]\n");
                break;
        }
        pause_f();
    } while (menu != 0);
}

void initPasien(Pasien_11385 *pasien) {
    int i;

    strcpy(pasien->nama, "");
    strcpy(pasien->penyakit, "");

    pasien->jumlah_obat = 0;

    for (i = 0; i < 10; i++) {
        strcpy(pasien->daftar_obat[i], "");
    }

    strcpy(pasien->kamar.nama, "");
    strcpy(pasien->kamar.kelas, "");

    strcpy(pasien->dokter.nama, "");
    strcpy(pasien->dokter.no_induk, "");
}

void inputPasien(Pasien_11385 *pasien) {
    int i, j;

    while (true) {
        printf("Nama Pasien         : ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%s", pasien->nama);

        if (strlen(pasien->nama) == 0) {
            printf("\n[-] Nama tidak boleh kosong [!]\n");
            continue;
        } else
            break;
    }

    while (true) {
        printf("Penyakit            : ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%s", pasien->penyakit);

        if (strlen(pasien->penyakit) == 0) {
            printf("\n[-] Penyakit tidak boleh kosong [!]\n");
            continue;
        } else
            break;
    }

    while (true) {
        printf("Jumlah obat         : ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%d", &pasien->jumlah_obat);

        if (pasien->jumlah_obat <= 0 || pasien->jumlah_obat >= 10) {
            printf("\n[-] Jumlah obat harus antara 1 - 10 [!]\n");
            continue;
        } else
            break;
    }

    for (i = 0; i < pasien->jumlah_obat; i++) {
        while (true) {
            printf("Obat ke-%d : ", i + 1);
            fgets(user_input, STRING_LENGTH, stdin);
            sscanf(user_input, "%s", pasien->daftar_obat[i]);

            if (strlen(pasien->daftar_obat[i]) == 0) {
                printf("\n[-] Obat tidak boleh kosong [!]\n");
                continue;
            } else
                break;
        }
    }

    printf("\nBerhasil input data Pasien [!]\n");
}

void inputDokter(Pasien_11385 *pasien) {
    while (true) {
        printf("Nama Dokter         : ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%s", pasien->dokter.nama);

        if (strlen(pasien->dokter.nama) == 0) {
            printf("\n[-] Nama tidak boleh kosong [!]\n");
            continue;
        } else
            break;
    }

    while (true) {
        printf("No Induk Dokter     : ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%s", pasien->dokter.no_induk);

        if (strlen(pasien->dokter.no_induk) != 9) {
            printf("\n[-] No Induk harus berjumlah 9 digit [!]\n");
            continue;
        } else
            break;
    }

    printf("\nBerhasil input data Dokter [!]\n");
}

void inputKamar(Pasien_11385 *pasien) {
    while (true) {
        printf("Nama Kamar          : ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%s", pasien->kamar.nama);

        if (strlen(pasien->kamar.nama) == 0) {
            printf("\n[-] Nama tidak boleh kosong [!]\n");
            continue;
        } else
            break;
    }

    printf("[ Kelas kamar antara Kelas I, Kelas II, Kelas III, VIP, atau VVIP ]\n");
    while (true) {
        printf("Kelas Kamar         : ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%s", pasien->kamar.kelas);

        if (strcmp(pasien->kamar.kelas, "Kelas I") == 0 || strcmp(pasien->kamar.kelas, "Kelas II") == 0 || strcmp(pasien->kamar.kelas, "Kelas III") == 0 || strcmp(pasien->kamar.kelas, "VIP") == 0 || strcmp(pasien->kamar.kelas, "VVIP") == 0) {
            break;
        } else {
            printf("\n[-] Kelas tidak tersedia [!]\n");
            continue;
        }
    }

    printf("\nBerhasil input data Kamar [!]\n");
}

void tampilData(Pasien_11385 pasien) {
    int i;

    printf("[ Pasien ]\n");
    printf("Nama Pasien         : %s\n", pasien.nama);
    printf("Penyakit            : %s\n", pasien.penyakit);

    printf("\n[ Jumlah Obat : %d ]\n", pasien.jumlah_obat);
    for (i = 0; i < pasien.jumlah_obat; i++) {
        printf("%d. %s\n", i + 1, pasien.daftar_obat[i]);
    }

    printf("\n[ Dokter ]\n");
    printf("Nama Dokter         : %s\n", pasien.dokter.nama);
    printf("No Induk Dokter     : %s\n", pasien.dokter.no_induk);

    if (strlen(pasien.kamar.nama) != 0) {
        printf("\n[ Kamar ]\n");
        printf("Nama Kamar          : %s\n", pasien.kamar.nama);
        printf("Kelas Kamar         : %s\n", pasien.kamar.kelas);
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