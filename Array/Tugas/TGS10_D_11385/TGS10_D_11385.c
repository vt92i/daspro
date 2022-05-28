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
#define STRING_LENGTH 64
typedef char string[STRING_LENGTH];

void showData(string arr[]);
int findData(string arr[], string data);
void updateData(string arr[], int index, string new_data);
void sortData(string arr0[], string arr1[]);
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
    string user_input;
    string hyphen = "-";

    int index;
    int menu;

    while (true) {
        clear_screen_f();

        strcpy(username, "");
        strcpy(password, "");
        strcpy(status_user, "");
        strcpy(user_input, "");
        menu = -1;

        printf("\n---= LOGIN FORM =---\n");
        printf("\n");

        printf("Username    : ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%s", username);

        printf("Password    : ");
        fgets(user_input, STRING_LENGTH, stdin);
        sscanf(user_input, "%s", password);

        if (strcmp(username, "Zooey") == 0 && strcmp(password, "zooeyjaya") == 0) {
            strcpy(status_user, "Pengelola");
            printf("\nBerhasil login sebagai %s [!]\n", status_user);
            pause_f();

            while (menu != 0) {
                clear_screen_f();

                strcpy(cari_hewan, "");
                strcpy(hewan_baru, "");
                strcpy(kelas_baru, "");
                strcpy(user_input, "");
                menu = -1;

                printf("\n---= MENU =---\n");
                printf("1. Input Hewan\n");
                printf("2. Edit Hewan\n");
                printf("3. Delete Hewan\n");
                printf("4. Sort Hewan [ BONUS ]\n");
                printf("5. Reverse Hewan [ TUGAS ] \n");
                printf("6. Tampil Hewan [ OPTIONAL ] \n");
                printf("0. Exit\n");

                printf("\nMenu >> ");
                fgets(user_input, STRING_LENGTH, stdin);
                sscanf(user_input, "%d", &menu);

                if (menu >= 1 && menu <= 6)
                    clear_screen_f();

                switch (menu) {
                    case 1:
                        printf("\n---= INPUT HEWAN =---\n");

                        index = findData(dataHewan, hyphen);
                        if (index != -1) {
                            while (true) {
                                printf("Masukan nama hewan : ");
                                fgets(user_input, STRING_LENGTH, stdin);
                                sscanf(user_input, "%[^\n]", hewan_baru);

                                if (strlen(hewan_baru) != 0)
                                    break;
                                else
                                    printf("\nNama hewan tidak boleh kosong [!]\n");
                            }

                            while (true) {
                                printf("Masukan nama kelas : ");
                                fgets(user_input, STRING_LENGTH, stdin);
                                sscanf(user_input, "%[^\n]", kelas_baru);

                                if (strlen(kelas_baru) != 0)
                                    break;
                                else
                                    printf("\nNama kelas tidak boleh kosong [!]\n");
                            }

                            updateData(dataHewan, index, hewan_baru);
                            updateData(dataKelas, index, kelas_baru);

                            printf("\nBerhasil input [!]\n");

                        } else {
                            printf("\nData hewan sudah terisi penuh [!]\n");
                        }

                        break;

                    case 2:
                        printf("\n---= EDIT HEWAN =---\n");

                        while (true) {
                            printf("Masukan nama hewan yang ingin diubah : ");
                            fgets(user_input, STRING_LENGTH, stdin);
                            sscanf(user_input, "%[^\n]", cari_hewan);

                            if (strlen(cari_hewan) == 0) {
                                printf("\nNama hewan tidak boleh kosong [!]\n");
                                continue;
                            }

                            index = findData(dataHewan, cari_hewan);
                            if (index != -1)
                                break;
                            else
                                printf("\nHewan [ %s ] tidak ditemukan [!]\n", cari_hewan);
                        }

                        while (true) {
                            printf("Masukan nama hewan yang baru         : ");
                            fgets(user_input, STRING_LENGTH, stdin);
                            sscanf(user_input, "%[^\n]", hewan_baru);

                            if (strlen(hewan_baru) == 0) {
                                printf("\nNama hewan baru tidak boleh kosong [!]\n");
                                continue;
                            }

                            if (strcmp(hewan_baru, cari_hewan) != 0)
                                break;
                            else
                                printf("\nNama hewan tidak boleh sama dengan nama hewan sebelumnya [!]\n");
                        }

                        while (true) {
                            printf("Masukan nama kelas yang baru         : ");
                            fgets(user_input, STRING_LENGTH, stdin);
                            sscanf(user_input, "%[^\n]", kelas_baru);

                            if (strlen(kelas_baru) == 0) {
                                printf("\nNama kelas baru tidak boleh kosong [!]\n");
                                continue;
                            } else {
                                break;
                            }
                        }

                        updateData(dataHewan, index, hewan_baru);
                        updateData(dataKelas, index, kelas_baru);

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
                            fgets(user_input, STRING_LENGTH, stdin);
                            sscanf(user_input, "%[^\n]", cari_hewan);

                            if (strlen(cari_hewan) == 0) {
                                printf("\nNama hewan tidak boleh kosong [!]\n");
                                continue;
                            }

                            index = findData(dataHewan, cari_hewan);
                            if (index != -1)
                                break;
                            else
                                printf("\nHewan [ %s ] tidak ditemukan [!]\n", cari_hewan);
                        }

                        updateData(dataHewan, index, hyphen);
                        updateData(dataKelas, index, hyphen);

                        printf("\n [ Data Hewan ]\n");
                        showData(dataHewan);

                        printf("\n [ Data Kelas ]\n");
                        showData(dataKelas);

                        printf("\nBerhasil delete [!]\n");

                        break;

                    case 4:
                        printf("\n---= SORT HEWAN =---\n");

                        index = findData(dataHewan, hyphen);
                        if (index != -1) {
                            printf("\nData hewan harus sudah terisi penuh [!]\n");
                            break;
                        }

                        if (is_data_sorted) {
                            is_data_sorted = false;
                            sortData(dataHewan, dataKelas);
                        }

                        printf("\n [ SEBELUM SORT ]");
                        printf("\n [ Data Hewan ]");
                        showData(dataHewan);

                        printf("\n [ Data Kelas ]");
                        showData(dataKelas);

                        if (!is_data_sorted) {
                            is_data_sorted = true;
                            sortData(dataHewan, dataKelas);
                        }

                        printf("\n [ SESUDAH SORT ]");
                        printf("\n [ Data Hewan ]");
                        showData(dataHewan);

                        printf("\n [ Data Kelas ]");
                        showData(dataKelas);

                        printf("\nBerhasil sort [!]\n");

                        break;

                    case 5:
                        printf("\n---= REVERSE HEWAN =---\n");

                        if (is_data_reversed) {
                            is_data_reversed = false;
                            reverseData(dataHewan);
                            reverseData(dataKelas);
                        }

                        printf("\n [ SEBELUM REVERSE ]");
                        printf("\n [ Data Hewan ]");
                        showData(dataHewan);

                        printf("\n [ Data Kelas ]");
                        showData(dataKelas);

                        if (!is_data_reversed) {
                            is_data_reversed = true;
                            reverseData(dataHewan);
                            reverseData(dataKelas);
                        }

                        printf("\n [ SESUDAH REVERSE ]");
                        printf("\n [ Data Hewan ]");
                        showData(dataHewan);

                        printf("\n [ Data Kelas ]");
                        showData(dataKelas);

                        printf("\nBerhasil reverse [!]\n");

                        break;

                    case 6:
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
            pause_f();

            while (menu != 0) {
                clear_screen_f();

                strcpy(cari_hewan, "");
                strcpy(user_input, "");
                menu = -1;

                printf("\n---= MENU =---\n");
                printf("1. Cari Hewan\n");
                printf("0. Exit\n");

                printf("\nMenu >> ");
                fgets(user_input, STRING_LENGTH, stdin);
                sscanf(user_input, "%d", &menu);

                if (menu == 1)
                    clear_screen_f();

                switch (menu) {
                    case 1:
                        printf("\n---= CARI HEWAN =---\n");
                        printf("Masukan nama hewan : ");
                        fgets(user_input, STRING_LENGTH, stdin);
                        sscanf(user_input, "%[^\n]", cari_hewan);

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
        if (i % 4 == 0)
            printf("\n| ");
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

void updateData(string arr[], int index, string new_data) {
    strcpy(arr[index], new_data);
}

void sortData(string arr0[], string arr1[]) {
    int i, j;
    string string_tmp;

    for (i = 0; i < ARRAY_LENGTH; i++) {
        for (j = 0; j < (ARRAY_LENGTH - 1) - i; j++) {
            if (strcmp(arr0[j], arr0[j + 1]) > 0) {
                strcpy(string_tmp, arr0[j]);
                strcpy(arr0[j], arr0[j + 1]);
                strcpy(arr0[j + 1], string_tmp);

                strcpy(string_tmp, arr1[j]);
                strcpy(arr1[j], arr1[j + 1]);
                strcpy(arr1[j + 1], string_tmp);
            }
        }
    }
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