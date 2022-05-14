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
#include <time.h>

#define taliA 3000
#define taliB 5000
#define taliC 7000
#define taliX 19000
#define taliY 23000

typedef char string[64];

void doLogin(int *is_login, string username, int password);
void doLogout(int *is_login);
void printRincian(string nama, string tanggal_datang, string jam_datang, int tali_a, int tali_b, int tali_c, int tali_x, int tali_y, int jumlah_a, int jumlah_b, int jumlah_c, int jumlah_x, int jumlah_y);

void tampilMenu();

void clear_screen_f();
void pause_f();

// Benidiktus Violaz Morello Anjolie2
// 210711385
// D

int main(int argc, char const *argv[]) {
    if (PLATFORM_NAME == "linux")
        pause_f();

    int menu;

    string username;
    int password;
    int is_login;
    int toleransi = 3;

    int tali_a, tali_b, tali_c, tali_x, tali_y;
    tali_a = 50;
    tali_b = 50;
    tali_c = 50;

    tali_x = 100;
    tali_y = 100;

    int pembeli, pembelian;
    string nama_pembeli, no_telp, tanggal_datang, jam_datang;
    string nik, pekerjaan, alamat;

    pembeli = 0;
    pembelian = 0;

    int jumlah_a, jumlah_b, jumlah_c, jumlah_x, jumlah_y;
    jumlah_a = 0;
    jumlah_b = 0;
    jumlah_c = 0;
    jumlah_x = 0;
    jumlah_y = 0;

    string tipe;
    int panjang_tali;

    do {
        printf("\n---= LOGIN FORM =---\n");
        printf("[ Toleransi : %d ]\n", toleransi);

        printf("\n");
        printf("Username (Atma)  : ");
        scanf("%s", &username);

        printf("Password (11385) : ");
        scanf("%d", &password);

        doLogin(&is_login, username, password);

        if (is_login) {
            do {
                clear_screen_f();

                tampilMenu(tali_a, tali_b, tali_c, tali_x, tali_y);
                printf("\nMenu >> ");
                scanf("%d", &menu);

                switch (menu) {
                    case 1:
                        if (pembeli == 1) {
                            printf("\nData pembeli sudah terinput[!]\n");
                        } else {
                            printf("\n === Input Data Pembeli === \n");

                            printf("Nama pembeli \t\t : ");
                            scanf("%s", &nama_pembeli);
                            while (strlen(nama_pembeli) == 0 || strcmp(nama_pembeli, "-") == 0) {
                                printf("\nNama pembeli tidak boleh kosong[!]");
                                printf("\nNama pembeli \t\t : ");
                                scanf("%s", &nama_pembeli);
                            }

                            printf("No telpon \t\t : ");
                            scanf("%s", &no_telp);

                            printf("Tanggal kedatangan \t : ");
                            scanf("%s", &tanggal_datang);
                            while (strlen(tanggal_datang) != 10) {
                                printf("\nFormat tanggal salah[!]\n");
                                printf("Tanggal kedatangan \t : ");
                                scanf("%s", &tanggal_datang);
                            }

                            printf("Jam kedatangan \t\t : ");
                            scanf("%s", &jam_datang);
                            while (strlen(jam_datang) != 8) {
                                printf("\nFormat jam salah[!]\n");
                                printf("Jam kedatangan \t\t : ");
                                scanf("%s", &jam_datang);
                            }

                            printf("\nBerhasil input data pembeli[!]\n");
                            pembeli = 1;
                        }
                        break;

                    case 2:
                        if (pembeli == 0) {
                            printf("\nData pembeli belum terinput[!]\n");
                        } else {
                            printf("\n === Input Pembelian === \n");

                            printf("Jenis tali (A/B/C/X/Y) : ");
                            scanf("%s", &tipe);
                            while (strcmp(tipe, "A") != 0 && strcmp(tipe, "B") != 0 && strcmp(tipe, "C") != 0 && strcmp(tipe, "X") != 0 && strcmp(tipe, "Y") != 0) {
                                printf("\nJenis tidak diketahui[!]\n");
                                printf("Jenis tali (A/B/C/X/Y) : ");
                                scanf("%s", &tipe);
                            }

                            if (strcmp(tipe, "X") == 0 || strcmp(tipe, "Y") == 0) {
                                printf("NIK : ");
                                scanf("%s", &nik);
                                while (strlen(nik) != 16) {
                                    printf("\nNIK harus 16 digit[!]");
                                    printf("NIK : ");
                                    scanf("%s", &nik);
                                }

                                printf("Pekerjaan : ");
                                scanf("%s", &pekerjaan);

                                printf("Alamat : ");
                                scanf("%s", &alamat);
                            }

                            printf("Panjang tali (m) : ");
                            scanf("%d", &panjang_tali);

                            if (strcmp(tipe, "A") == 0) {
                                jumlah_a = taliA * panjang_tali;
                                tali_a -= panjang_tali;
                            } else if (strcmp(tipe, "B") == 0) {
                                jumlah_b = taliB * panjang_tali;
                                tali_b -= panjang_tali;
                            } else if (strcmp(tipe, "C") == 0) {
                                jumlah_c = taliC * panjang_tali;
                                tali_c -= panjang_tali;
                            } else if (strcmp(tipe, "X") == 0) {
                                jumlah_x = taliX * panjang_tali;
                                tali_x -= panjang_tali;
                            } else {
                                jumlah_y = taliY * panjang_tali;
                                tali_y -= panjang_tali;
                            }

                            printf("\nBerhasil input data pembelian[!]\n");
                            pembelian = 1;
                        }
                        break;

                    case 3:
                        if (pembelian == 0) {
                            printf("\nData pembelian belum terinput[!]\n");
                        } else {
                            printRincian(nama_pembeli, tanggal_datang, jam_datang, tali_a, tali_b, tali_c, tali_x, tali_y, jumlah_a, jumlah_b, jumlah_c, jumlah_x, jumlah_y);
                        }
                        break;

                    case 4:
                        break;

                    case 0:
                        doLogout(&is_login);
                        if (is_login == 0) {
                            printf("Terima kasih [!]\n");
                            // initData()
                            toleransi = 3;
                            clear_screen_f();
                        }
                        break;

                    default:
                        printf("\nMenu tidak tersedia[!]\n");
                        break;
                }

                pause_f();

            } while (is_login != 0);
        } else {
            printf("\n[Error] Username atau Password salah[!]\n");
            toleransi -= 1;
        }
    } while (toleransi != 0);

    printf("\n");
    printf("[!] Program keluar [!] \n");
    printf("[!] Benidiktus Violaz Morello Anjolie - 210711385 - D[!] \n");

    return 0;
}

void doLogin(int *is_login, string username, int password) {
    if (strcmp(username, "Atma") == 0 && password == 11385) {
        *is_login = 1;
        printf("\n[OK] Login berhasil[!]\n");
        pause_f();
    } else {
        *is_login = 0;
    }
}

void doLogout(int *is_login) {
    *is_login = 0;
}

void printRincian(string nama, string tanggal_datang, string jam_datang, int tali_a, int tali_b, int tali_c, int tali_x, int tali_y, int jumlah_a, int jumlah_b, int jumlah_c, int jumlah_x, int jumlah_y) {
    int total;
    total = jumlah_a + jumlah_b + jumlah_c + jumlah_x + jumlah_y;

    printf("Nama    : %s", nama);
    printf("\nWaktu kedatangan  : %s - %s\n", tanggal_datang, jam_datang);

    printf("\n[Tali A]  | %d \t| %d IDR |\t---> Total : %d IDR", tali_a, taliA, jumlah_a);
    printf("\n[Tali B]  | %d \t| %d IDR |\t---> Total : %d IDR", tali_b, taliB, jumlah_b);
    printf("\n[Tali C]  | %d \t| %d IDR |\t---> Total : %d IDR", tali_c, taliC, jumlah_c);
    printf("\n[Tali X]  | %d \t| %d IDR |\t---> Total : %d IDR", tali_x, taliX, jumlah_x);
    printf("\n[Tali Y]  | %d \t| %d IDR |\t---> Total : %d IDR", tali_y, taliY, jumlah_y);

    printf("\n");
    printf("\nTotal yang harus dibayar : %d IDR\n", total);
}

void tampilMenu(int tali_a, int tali_b, int tali_c, int tali_x, int tali_y) {
    clear_screen_f();

    printf("\n ---= Daftar Barang =--- \n");
    printf("Barang (Stok) \t = Harga\n");
    printf("TaliA (%d) \t = %d IDR \n", tali_a, taliA);
    printf("TaliB (%d) \t = %d IDR \n", tali_b, taliB);
    printf("TaliC (%d) \t = %d IDR \n", tali_c, taliC);
    printf("TaliX (%d) \t = %d IDR \n", tali_x, taliX);
    printf("TaliY (%d) \t = %d IDR \n", tali_y, taliY);

    printf("\n ---= Menu utama =--- ");
    printf("\n[1] Input pembeli");
    printf("\n[2] Input pembelian");
    printf("\n[3] Rincian");
    printf("\n[4] Reset data");
    printf("\n[0] Logout");

    printf("\n---------------------");
    printf("\n[5] Hitung keuntungan [TUGAS]\n");
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