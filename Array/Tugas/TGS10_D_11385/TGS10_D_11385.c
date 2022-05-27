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

#define ARRAY_LENGTH 17
typedef char string[64];

void showData(string arr[]);
int findData(string arr[], string data);
void editData(string arr[], int index, string new_data);
void reverseData(string arr[]);

void clear_screen_f();
void pause_f();

// Benidiktus Violaz Morello Anjolie6
// 210711385
// D

int main(int argc, char const *argv[]) {
    if (strcmp(PLATFORM_NAME, "linux") == 0)
        pause_f();
    clear_screen_f();

    string dataHewan[ARRAY_LENGTH] = {"Beruang Kutub", "Katak", "Burung Merak", "Singa", "Macan", "Burung Unta", "Salmon", "Buaya", "Serigala", "Ikan Mas", "Ular Piton", "Ikan Cupang", "Burung Elang", "Kura Kura", "Kelinci", "Alligator", "Paus"};
    string dataKelas[ARRAY_LENGTH] = {"Mamalia", "Amfibi", "Burung", "Mamalia", "Mamalia", "Burung", "Ikan", "Reptil", "Mamalia", "Ikan", "Reptil", "Ikan", "Burung", "Reptil", "Mamalia", "Reptil", "Mamalia"};
    bool is_data_sorted;
    bool is_data_reversed;

    string username, password, status_user;
    string cari_hewan, hewan_baru, kelas_baru;
    int index;
    int menu;

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

            while (menu != 0) {
                clear_screen_f();

                printf("\n---= MENU =---\n");
                printf("1. Input Hewan\n");
                printf("2. Edit Hewan\n");
                printf("3. Delete Hewan\n");
                printf("4. Sort Hewan [ BONUS ]\n");
                printf("5. Reverse Hewan [ TUGAS ] \n");
                printf("8. Tampil Hewan [ OPTIONAL ] \n");
                printf("0. Exit\n");

                printf("\nMenu >> ");
                scanf("%d", &menu);

                switch (menu) {
                    case 1:
                        index = findData(dataHewan, "-");

                        if (index != -1) {
                            printf("\n---= INPUT HEWAN =---\n");
                            printf("Masukan nama hewan : ");
                            scanf("%s", hewan_baru);

                            printf("Masukan nama kelas : ");
                            scanf("%s", kelas_baru);

                            editData(dataHewan, index, hewan_baru);
                            editData(dataKelas, index, kelas_baru);

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

                            index = findData(dataHewan, cari_hewan);
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

                        editData(dataHewan, index, hewan_baru);
                        editData(dataKelas, index, kelas_baru);

                        printf("\n [ Data Hewan ]\n");
                        showData(dataHewan);

                        printf("\n [ Data Kelas ]\n");
                        showData(dataKelas);

                        printf("\nBerhasil edit [!]\n");

                        break;

                    case 3:
                        printf("\n---= DELETE HEWAN =---\n");

                        while (true) {
                            printf("Masukan nama hewan yang ingin dihapus : ");
                            scanf("%s", cari_hewan);

                            index = findData(dataHewan, cari_hewan);
                            if (index != -1)
                                break;
                            else
                                printf("\nHewan %s tidak ditemukan\n", cari_hewan);
                        }

                        editData(dataHewan, index, "-");
                        editData(dataKelas, index, "-");

                        printf("\n [ Data Hewan ]\n");
                        showData(dataHewan);

                        printf("\n [ Data Kelas ]\n");
                        showData(dataKelas);

                        printf("\nBerhasil delete [!]\n");

                        break;

                    case 5:
                        if (!is_data_reversed) {
                            reverseData(dataHewan);
                            reverseData(dataKelas);
                            is_data_reversed = true;
                        }

                        printf("\n---= REVERSE HEWAN =---\n");

                        printf("\n [ SEBELUM REVERSE ]");
                        printf("\n [ Data Hewan ]\n");
                        showData(dataHewan);

                        printf("\n [ Data Kelas ]\n");
                        showData(dataKelas);

                        printf("\n [ SESUDAH REVERSE ]");
                        printf("\n [ Data Hewan ]\n");
                        showData(dataHewan);

                        printf("\n [ Data Kelas ]\n");
                        showData(dataKelas);

                        printf("\nBerhasil reverse [!]\n");

                        break;

                    case 8:
                        printf("\n---= TAMPIL HEWAN =---\n");

                        printf("\n [ Data Hewan ]\n");
                        showData(dataHewan);

                        printf("\n [ Data Kelas ]\n");
                        showData(dataKelas);

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

        if (strcmp(username, "guest") == 0 && strcmp(password, "guest") == 0) {
            strcpy(status_user, "Guest");
            printf("\nBerhasil login sebagai %s [!]\n", status_user);

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

                        index = findData(dataHewan, cari_hewan);
                        if (index != -1)
                            printf("\nHewan [ %s ] merupakan hewan [ %s ]\n", cari_hewan, dataKelas[index]);
                        else
                            printf("\nHewan [ %s ] tidak ditemukan\n", cari_hewan);

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

        if (strcmp(username, "0") == 0 && strcmp(password, "0") == 0) {
            printf("\n");
            printf("[!] Program keluar [!] \n");
            printf("[!] Benidiktus Violaz Morello Anjolie - 210711385 - D [!] \n");
            break;
        }

        if (strcmp(status_user, "Pengelola") != 0 && strcmp(status_user, "Guest") != 0) {
            printf("\nUsername atau Password salah[!]\n");
            pause_f();
        }
    }

    return 0;
}

void showData(string arr[]) {
    int i;
    for (i = 0; i < ARRAY_LENGTH; i++) {
        printf("%s | ", arr[i]);
    }
    printf("\n");
}

int findData(string arr[], string data) {
    int i;
    for (i = 0; i < ARRAY_LENGTH; i++) {
        if (strcmp(arr[i], data) == 0)
            return i;
    }
    return -1;
}

void editData(string arr[], int index, string new_data) {
    strcpy(arr[index], new_data);
}

void reverseData(string arr[]) {
    int i, j;
    string temp_arr[ARRAY_LENGTH];

    for (i = 0; i < ARRAY_LENGTH; i++) {
        strcpy(temp_arr[i], arr[(ARRAY_LENGTH - 1) - i]);
    }

    for (j = 0; j < ARRAY_LENGTH; j++) {
        strcpy(arr[j], temp_arr[j]);
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