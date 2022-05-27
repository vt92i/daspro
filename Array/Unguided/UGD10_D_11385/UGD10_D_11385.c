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

typedef char string[64];

void tampilArray(string arr[]);
int cariData(string arr[], string cariNilai);
void editArray(string arr[], string data, string data_baru);

void clear_screen_f();
void pause_f();

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

int main(int argc, char const *argv[]) {
    if (strcmp(PLATFORM_NAME, "linux") == 0)
        pause_f();
    clear_screen_f();

    string dataHewan[17] = {"Beruang Kutub", "Katak", "Burung Merak", "Singa", "Macan", "Burung Unta", "Salmon", "Buaya", "Serigala", "Ikan Mas", "Ular Piton", "Ikan Cupang", "Burung Elang", "Kura Kura", "Kelinci", "Alligator", "Paus"};
    string dataKelas[17] = {"Mamalia", "Amfibi", "Burung", "Mamalia", "Mamalia", "Burung", "Ikan", "Reptil", "Mamalia", "Ikan", "Reptil", "Ikan", "Burung", "Reptil", "Mamalia", "Reptil", "Mamalia"};

    string username, password, status_user;
    int menu;

    string cari_hewan, hewan_baru, kelas_baru;
    int index;

    while (true) {
        clear_screen_f();

        strcpy(username, "");
        strcpy(password, "");
        strcpy(status_user, "");
        menu = -1;

        printf("\n---= LOGIN FORM =---\n");
        printf("\n");
        printf("Username    : ");
        scanf("%s", username);

        printf("Password    : ");
        scanf("%s", password);

        if (strcmp(username, "Zooey") == 0 && strcmp(password, "zooeyjaya") == 0) {
            strcpy(status_user, "Pengelola");
            printf("\nBerhasil login sebagai %s [!]\n", status_user);

            if (strcmp(status_user, "Pengelola") == 0) {
                while (menu != 0) {
                    clear_screen_f();

                    printf("\n---= MENU =---\n");
                    printf("1. Input Hewan\n");
                    printf("2. Edit Hewan\n");
                    printf("3. Delete Hewan\n");
                    printf("4. Sort Hewan [ BONUS ]\n");
                    printf("5. Reverse Hewan [ TUGAS ] \n");
                    printf("0. Exit\n");

                    printf("\nMenu >> ");
                    scanf("%d", &menu);

                    switch (menu) {
                        case 1:
                            index = cariData(dataHewan, "-");

                            if (index != -1) {
                                printf("\n---= INPUT HEWAN =---\n");
                                printf("Masukan nama hewan : ");
                                scanf("%s", hewan_baru);

                                printf("Masukan nama kelas : ");
                                scanf("%s", kelas_baru);

                                strcpy(dataHewan[index], hewan_baru);
                                strcpy(dataKelas[index], kelas_baru);

                                printf("\nBerhasil input [!]\n");

                            } else {
                                printf("\nData hewan sudah terisi penuh [!]\n");
                            }

                            break;

                        case 2:
                            printf("\n---= EDIT HEWAN =---\n");

                            while (true) {
                                printf("Masukan nama hewan yang ingin diubah : ");
                                scanf("%s", cari_hewan);

                                index = cariData(dataHewan, cari_hewan);
                                if (index != -1)
                                    break;
                                else
                                    printf("\nHewan %s tidak ditemukan\n", cari_hewan);
                            }

                            while (true) {
                                printf("Masukan nama hewan yang baru         : ");
                                scanf("%s", hewan_baru);

                                if (strcmp(hewan_baru, cari_hewan) != 0)
                                    break;
                                else
                                    printf("\nNama hewan tidak boleh sama dengan nama hewan sebelumnya [!]\n");
                            }

                            printf("Masukan nama kelas yang baru         : ");
                            scanf("%s", kelas_baru);

                            strcpy(dataHewan[index], hewan_baru);
                            strcpy(dataKelas[index], kelas_baru);

                            printf("\n [ Data Hewan ]\n");
                            tampilArray(dataHewan);

                            printf("\n [ Data Kelas ]\n");
                            tampilArray(dataKelas);

                            printf("\nBerhasil edit [!]\n");

                            break;

                        case 3:
                            printf("\n---= DELETE HEWAN =---\n");

                            while (true) {
                                printf("Masukan nama hewan yang ingin dihapus : ");
                                scanf("%s", cari_hewan);

                                index = cariData(dataHewan, cari_hewan);
                                if (index != -1)
                                    break;
                                else
                                    printf("\nHewan %s tidak ditemukan\n", cari_hewan);
                            }

                            strcpy(dataHewan[index], "-");
                            strcpy(dataKelas[index], "-");

                            printf("\n [ Data Hewan ]\n");
                            tampilArray(dataHewan);

                            printf("\n [ Data Kelas ]\n");
                            tampilArray(dataKelas);

                            printf("\nBerhasil delete [!]\n");

                            break;

                        case 0:
                            printf("\nExit [!]\n");
                            break;

                        default:
                            printf("\nMenu tidak tersedia [!]\n");
                            break;
                    }
                    pause_f();
                }
            }
        } else if (strcmp(username, "guest") == 0 && strcmp(password, "guest") == 0) {
            strcpy(status_user, "Guest");
            printf("\nBerhasil login sebagai %s [!]\n", status_user);

            if (strcmp(status_user, "Guest") == 0) {
                while (menu != 0) {
                    clear_screen_f();

                    printf("\n---= MENU =---\n");
                    printf("1. Cari Hewan\n");
                    printf("0. Exit\n");

                    printf("\nMenu >> ");
                    scanf("%d", &menu);

                    switch (menu) {
                        case 1:
                            printf("\n---= CARI HEWAN =---\n");
                            printf("Masukan nama hewan : ");
                            scanf("%s", cari_hewan);

                            index = cariData(dataHewan, cari_hewan);
                            if (index != -1) {
                                printf("\nHewan %s merupakan hewan [ %s ]\n", cari_hewan, dataKelas[index]);
                            } else {
                                printf("\nHewan %s tidak ditemukan\n", cari_hewan);
                            }

                            break;

                        case 0:
                            printf("\nExit [!]\n");
                            break;

                        default:
                            printf("\nMenu tidak tersedia [!]\n");
                            break;
                    }
                    pause_f();
                }
            }
        } else if (strcmp(username, "0") == 0 && strcmp(password, "0") == 0) {
            printf("\n");
            printf("[!] Program keluar [!] \n");
            printf("[!] Benidiktus Violaz Morello Anjolie - 210711385 - D [!] \n");
            break;
        } else {
            printf("\nUsername atau Password salah[!]\n");
            pause_f();
        }
    }

    return 0;
}

void tampilArray(string arr[]) {
    int i;
    for (i = 0; i < 17; i++) {
        printf("%s | ", arr[i]);
    }
    printf("\n");
}

int cariData(string arr[], string data) {
    int i;
    for (i = 0; i < 17; i++) {
        if (strcmp(arr[i], data) == 0)
            return i;
    }
    return -1;
}

void editArray(string arr[], string data, string data_baru) {
    int i;
    int index = cariData(arr, data);
    if (index != -1)
        strcpy(arr[index], data_baru);
    else
        printf("Data tidak ditemukan [!]\n");
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