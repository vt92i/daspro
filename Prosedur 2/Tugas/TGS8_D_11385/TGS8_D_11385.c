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

typedef char string[64];

// Data Login
string username;
string password;
bool is_authenticated;
int toleransi;

// Data Tali
int harga_pabrik_tali_a, harga_pabrik_tali_b, harga_pabrik_tali_c, harga_pabrik_tali_x, harga_pabrik_tali_y;
int harga_jual_tali_a, harga_jual_tali_b, harga_jual_tali_c, harga_jual_tali_x, harga_jual_tali_y;
int keuntungan_per_jual_a, keuntungan_per_jual_b, keuntungan_per_jual_c, keuntungan_per_jual_x, keuntungan_per_jual_x, keuntungan_per_jual_y;
int jumlah_tali_a, jumlah_tali_b, jumlah_tali_c, jumlah_tali_x, jumlah_tali_y;

// Data Pembeli
bool data_pembeli;
string nama_pembeli, no_telpon, tanggal_datang, jam_datang;
string nik, pekerjaan, alamat;

// Data Pembelian
bool data_pembelian;
string tipe_tali;
int panjang_tali;
int jumlah_pembelian_a, jumlah_pembelian_b, jumlah_pembelian_c, jumlah_pembelian_x, jumlah_pembelian_y;
int total_keuntungan_a, total_keuntungan_b, total_keuntungan_c, total_keuntungan_x, total_keuntungan_y;
int total_keuntungan_abcxy;
int total_pembelian_a, total_pembelian_b, total_pembelian_c, total_pembelian_x, total_pembelian_y;
int total_pembelian_abcxy;

void addNumbers(int *output, int N1, int N2);
void subtractNumbers(int *output, int N1, int N2);
void multiplyNumbers(int *output, int N1, int N2);

void hitungPembelian(int *output, int harga_jual_tali, int jumlah_pembelian);
void hitungKeuntungan(int *output, int jumlah_pembelian, int keuntungan_per_jual);

void initDataLogin();
void initDataTali();
void initDataPembeli();
void initDataPembelian();
void resetData();

void doLogin(bool *is_authenticated, string username, string password);
void doLogout();

void tampilMenu();
void printRincian();
void printKeuntungan();

void clear_screen_f();
void pause_f();

// Benidiktus Violaz Morello Anjolie2
// 210711385
// D

int main(int argc, char const *argv[]) {
    if (strcmp(PLATFORM_NAME, "linux") == 0)
        pause_f();

    clear_screen_f();

    initDataLogin();
    initDataTali();
    initDataPembeli();
    initDataPembelian();

    int menu;
    int jumlah_pembelian_tmp, total_pembelian_tmp, total_keuntungan_tmp;
    string answer;

    do {
        printf("\n---= LOGIN FORM =---\n");
        printf("[ Toleransi : %d ]\n", toleransi);

        printf("\n");
        printf("Username (Atma)  : ");
        scanf("%s", username);

        printf("Password (11385) : ");
        scanf("%s", password);

        if (strcmp(username, "0") != 0 && strcmp(password, "0") != 0)
            doLogin(&is_authenticated, username, password);
        else
            break;

        if (is_authenticated) {
            do {
                clear_screen_f();

                tampilMenu();
                printf("\nMenu >> ");
                scanf("%d", &menu);

                switch (menu) {
                    case 1:
                        if (data_pembeli) {
                            printf("\nData pembeli sudah terinput[!]\n");
                        } else {
                            printf("\n === Input Data Pembeli === \n");

                            printf("Nama pembeli \t\t : ");
                            scanf("%s", nama_pembeli);

                            printf("No telpon \t\t : ");
                            scanf("%s", no_telpon);

                            printf("Tanggal kedatangan \t : ");
                            scanf("%s", tanggal_datang);
                            while (strlen(tanggal_datang) != 10) {
                                printf("\nFormat tanggal salah[!]\n");
                                printf("Tanggal kedatangan \t : ");
                                scanf("%s", tanggal_datang);
                            }

                            printf("Jam kedatangan \t\t : ");
                            scanf("%s", jam_datang);
                            while (strlen(jam_datang) != 8) {
                                printf("\nFormat jam salah[!]\n");
                                printf("Jam kedatangan \t\t : ");
                                scanf("%s", jam_datang);
                            }

                            printf("\nBerhasil input data pembeli[!]\n");
                            data_pembeli = true;
                        }
                        break;

                    case 2:
                        if (!data_pembeli) {
                            printf("\nData pembeli belum terinput[!]\n");
                        } else {
                            printf("\n === Input Pembelian === \n");

                            if (jumlah_tali_a == 0 && jumlah_tali_b == 0 && jumlah_tali_c == 0 && jumlah_tali_x == 0 && jumlah_tali_y == 0) {
                                printf("\nStok semua tali habis[!]\n");
                                break;
                            }

                            while (true) {
                                printf("Jenis tali (A/B/C/X/Y)  : ");
                                scanf("%s", tipe_tali);

                                if (strcmp(tipe_tali, "A") == 0 || strcmp(tipe_tali, "B") == 0 || strcmp(tipe_tali, "C") == 0 || strcmp(tipe_tali, "X") == 0 || strcmp(tipe_tali, "Y") == 0) {
                                    printf("Panjang tali (m)        : ");
                                    scanf("%d", &panjang_tali);

                                    if (strcmp(tipe_tali, "A") == 0) {
                                        if (jumlah_tali_a > 0 && jumlah_tali_a >= panjang_tali) {
                                            break;
                                        }
                                    }

                                    if (strcmp(tipe_tali, "B") == 0) {
                                        if (jumlah_tali_b > 0 && jumlah_tali_b >= panjang_tali) {
                                            break;
                                        }
                                    }

                                    if (strcmp(tipe_tali, "C") == 0) {
                                        if (jumlah_tali_c > 0 && jumlah_tali_c >= panjang_tali) {
                                            break;
                                        }
                                    }

                                    if (strcmp(tipe_tali, "X") == 0) {
                                        if (jumlah_tali_x > 0 && jumlah_tali_x >= panjang_tali) {
                                            break;
                                        }
                                    }

                                    if (strcmp(tipe_tali, "Y") == 0) {
                                        if (jumlah_tali_y > 0 && jumlah_tali_y >= panjang_tali) {
                                            break;
                                        }
                                    }

                                    printf("\nInput tidak valid[!]\n");
                                } else {
                                    printf("\nJenis tidak diketahui[!]\n");
                                }
                            }

                            if (strcmp(tipe_tali, "X") == 0 || strcmp(tipe_tali, "Y") == 0) {
                                if (strlen(nik) == 0 && strlen(pekerjaan) == 0 && strlen(alamat) == 0) {
                                    while (true) {
                                        printf("NIK                     : ");
                                        scanf("%s", nik);

                                        if (strlen(nik) == 16)
                                            break;
                                        else
                                            printf("\nNIK harus 16 digit[!]\n");
                                    }

                                    printf("Pekerjaan               : ");
                                    scanf("%s", pekerjaan);

                                    printf("Alamat                  : ");
                                    scanf("%s", alamat);
                                }
                            }

                            if (strcmp(tipe_tali, "A") == 0) {
                                jumlah_pembelian_tmp = panjang_tali;
                                addNumbers(&jumlah_pembelian_a, jumlah_pembelian_a, jumlah_pembelian_tmp);

                                hitungPembelian(&total_pembelian_tmp, harga_jual_tali_a, jumlah_pembelian_tmp);
                                addNumbers(&total_pembelian_a, total_pembelian_a, total_pembelian_tmp);
                                addNumbers(&total_pembelian_abcxy, total_pembelian_abcxy, total_pembelian_tmp);

                                hitungKeuntungan(&total_keuntungan_tmp, jumlah_pembelian_tmp, keuntungan_per_jual_a);
                                addNumbers(&total_keuntungan_a, total_keuntungan_a, total_keuntungan_tmp);
                                addNumbers(&total_keuntungan_abcxy, total_keuntungan_abcxy, total_keuntungan_tmp);

                                subtractNumbers(&jumlah_tali_a, jumlah_tali_a, jumlah_pembelian_tmp);
                            }

                            if (strcmp(tipe_tali, "B") == 0) {
                                jumlah_pembelian_tmp = panjang_tali;
                                addNumbers(&jumlah_pembelian_b, jumlah_pembelian_b, jumlah_pembelian_tmp);

                                hitungPembelian(&total_pembelian_tmp, harga_jual_tali_b, jumlah_pembelian_tmp);
                                addNumbers(&total_pembelian_b, total_pembelian_b, total_pembelian_tmp);
                                addNumbers(&total_pembelian_abcxy, total_pembelian_abcxy, total_pembelian_tmp);

                                hitungKeuntungan(&total_keuntungan_tmp, jumlah_pembelian_tmp, keuntungan_per_jual_b);
                                addNumbers(&total_keuntungan_b, total_keuntungan_b, total_keuntungan_tmp);
                                addNumbers(&total_keuntungan_abcxy, total_keuntungan_abcxy, total_keuntungan_tmp);

                                subtractNumbers(&jumlah_tali_b, jumlah_tali_b, jumlah_pembelian_tmp);
                            }

                            if (strcmp(tipe_tali, "C") == 0) {
                                jumlah_pembelian_tmp = panjang_tali;
                                addNumbers(&jumlah_pembelian_c, jumlah_pembelian_c, jumlah_pembelian_tmp);

                                hitungPembelian(&total_pembelian_tmp, harga_jual_tali_c, jumlah_pembelian_tmp);
                                addNumbers(&total_pembelian_c, total_pembelian_c, total_pembelian_tmp);
                                addNumbers(&total_pembelian_abcxy, total_pembelian_abcxy, total_pembelian_tmp);

                                hitungKeuntungan(&total_keuntungan_tmp, jumlah_pembelian_tmp, keuntungan_per_jual_c);
                                addNumbers(&total_keuntungan_c, total_keuntungan_c, total_keuntungan_tmp);
                                addNumbers(&total_keuntungan_abcxy, total_keuntungan_abcxy, total_keuntungan_tmp);

                                subtractNumbers(&jumlah_tali_c, jumlah_tali_c, jumlah_pembelian_tmp);
                            }

                            if (strcmp(tipe_tali, "X") == 0) {
                                jumlah_pembelian_tmp = panjang_tali;
                                addNumbers(&jumlah_pembelian_x, jumlah_pembelian_x, jumlah_pembelian_tmp);

                                hitungPembelian(&total_pembelian_tmp, harga_jual_tali_x, jumlah_pembelian_tmp);
                                addNumbers(&total_pembelian_x, total_pembelian_x, total_pembelian_tmp);
                                addNumbers(&total_pembelian_abcxy, total_pembelian_abcxy, total_pembelian_tmp);

                                hitungKeuntungan(&total_keuntungan_tmp, jumlah_pembelian_tmp, keuntungan_per_jual_x);
                                addNumbers(&total_keuntungan_x, total_keuntungan_x, total_keuntungan_tmp);
                                addNumbers(&total_keuntungan_abcxy, total_keuntungan_abcxy, total_keuntungan_tmp);

                                subtractNumbers(&jumlah_tali_x, jumlah_tali_x, jumlah_pembelian_tmp);
                            }

                            if (strcmp(tipe_tali, "Y") == 0) {
                                jumlah_pembelian_tmp = panjang_tali;
                                addNumbers(&jumlah_pembelian_y, jumlah_pembelian_y, jumlah_pembelian_tmp);

                                hitungPembelian(&total_pembelian_tmp, harga_jual_tali_y, jumlah_pembelian_tmp);
                                addNumbers(&total_pembelian_y, total_pembelian_y, total_pembelian_tmp);
                                addNumbers(&total_pembelian_abcxy, total_pembelian_abcxy, total_pembelian_tmp);

                                hitungKeuntungan(&total_keuntungan_tmp, jumlah_pembelian_tmp, keuntungan_per_jual_y);
                                addNumbers(&total_keuntungan_y, total_keuntungan_y, total_keuntungan_tmp);
                                addNumbers(&total_keuntungan_abcxy, total_keuntungan_abcxy, total_keuntungan_tmp);

                                subtractNumbers(&jumlah_tali_y, jumlah_tali_y, jumlah_pembelian_tmp);
                            }

                            printf("\nBerhasil input data pembelian[!]\n");
                            data_pembelian = true;
                        }
                        break;

                    case 3:
                        if (!data_pembeli) {
                            printf("\nData pembeli belum terinput[!]\n");
                        } else if (!data_pembelian) {
                            printf("\nData pembelian belum terinput[!]\n");
                        } else {
                            printRincian();
                        }
                        break;

                    case 4:
                        printf("\n === Reset Data === \n");
                        printf("Yakin ingin reset data? (Y/n)");
                        scanf("%s", answer);
                        if (strcmp(answer, "Y") == 0) {
                            resetData();
                            printf("\n[OK] Reset data berhasil[!]\n");
                        }
                        break;

                    case 5:
                        if (!data_pembelian) {
                            printf("\nBelum ada pembelian[!]\n");
                        } else {
                            printKeuntungan();
                        }
                        break;

                    case 0:
                        doLogout();

                        printf("Terima kasih [!]\n");

                        pause_f();
                        clear_screen_f();
                        break;

                    default:
                        printf("\nMenu tidak tersedia[!]\n");
                        break;
                }

                pause_f();

            } while (is_authenticated != 0);
        } else {
            printf("\n[Error] Username atau Password salah[!]\n");
            subtractNumbers(&toleransi, toleransi, 1);
        }
    } while (toleransi != 0);

    printf("\n");
    printf("[!] Program keluar [!] \n");
    printf("[!] Benidiktus Violaz Morello Anjolie - 210711385 - D [!] \n");

    return 0;
}

void addNumbers(int *output, int N1, int N2) {
    *output = N1 + N2;
}

void subtractNumbers(int *output, int N1, int N2) {
    *output = N1 - N2;
}

void multiplyNumbers(int *output, int N1, int N2) {
    *output = N1 * N2;
}

void hitungPembelian(int *output, int harga_jual_tali, int jumlah_pembelian) {
    multiplyNumbers(output, harga_jual_tali, jumlah_pembelian);
}

void hitungKeuntungan(int *output, int jumlah_pembelian, int keuntungan_per_jual) {
    multiplyNumbers(output, jumlah_pembelian, keuntungan_per_jual);
}

void initDataLogin() {
    strcpy(username, "");
    strcpy(password, "");
    is_authenticated = false;
    toleransi = 3;
}

void initDataTali() {
    harga_pabrik_tali_a = 3000;
    harga_pabrik_tali_b = 5000;
    harga_pabrik_tali_c = 7000;
    harga_pabrik_tali_x = 19000;
    harga_pabrik_tali_y = 23000;

    harga_jual_tali_a = 5000;
    harga_jual_tali_b = 7500;
    harga_jual_tali_c = 10000;
    harga_jual_tali_x = 25000;
    harga_jual_tali_y = 30000;

    keuntungan_per_jual_a = harga_jual_tali_a - harga_pabrik_tali_a;
    keuntungan_per_jual_b = harga_jual_tali_b - harga_pabrik_tali_b;
    keuntungan_per_jual_c = harga_jual_tali_c - harga_pabrik_tali_c;
    keuntungan_per_jual_x = harga_jual_tali_x - harga_pabrik_tali_x;
    keuntungan_per_jual_y = harga_jual_tali_y - harga_pabrik_tali_y;

    jumlah_tali_a = 50;
    jumlah_tali_b = 50;
    jumlah_tali_c = 50;

    jumlah_tali_x = 100;
    jumlah_tali_y = 100;
}

void initDataPembeli() {
    data_pembeli = false;

    strcpy(nama_pembeli, "");
    strcpy(no_telpon, "");
    strcpy(tanggal_datang, "");
    strcpy(jam_datang, "");

    strcpy(nik, "");
    strcpy(pekerjaan, "");
    strcpy(alamat, "");
}

void initDataPembelian() {
    data_pembelian = false;

    strcpy(tipe_tali, "");
    panjang_tali = 0;
    jumlah_pembelian_a = 0;
    jumlah_pembelian_b = 0;
    jumlah_pembelian_c = 0;
    jumlah_pembelian_x = 0;
    jumlah_pembelian_y = 0;

    total_keuntungan_a = 0;
    total_keuntungan_b = 0;
    total_keuntungan_c = 0;
    total_keuntungan_x = 0;
    total_keuntungan_y = 0;
    total_keuntungan_abcxy = 0;

    total_pembelian_a = 0;
    total_pembelian_b = 0;
    total_pembelian_c = 0;
    total_pembelian_x = 0;
    total_pembelian_y = 0;
    total_pembelian_abcxy = 0;
}

void resetData() {
    initDataTali();
    initDataPembeli();
    initDataPembelian();
}

void doLogin(bool *is_authenticated, string username, string password) {
    if (strcmp(username, "Atma") == 0 && strcmp(password, "11385") == 0) {
        *is_authenticated = true;
        printf("\n[OK] Login berhasil[!]\n");
        pause_f();
    } else {
        *is_authenticated = false;
    }
}

void doLogout() {
    initDataLogin();
    printf("\n[OK] Logout berhasil[!]\n");
}

void tampilMenu() {
    clear_screen_f();

    printf("\n ---= Daftar Barang =--- \n");
    printf("Barang (Stok) \t = Harga\n");
    printf("TaliA (%d) \t = %d IDR \n", jumlah_tali_a, harga_jual_tali_a);
    printf("TaliB (%d) \t = %d IDR \n", jumlah_tali_b, harga_jual_tali_b);
    printf("TaliC (%d) \t = %d IDR \n", jumlah_tali_c, harga_jual_tali_c);
    printf("TaliX (%d) \t = %d IDR \n", jumlah_tali_x, harga_jual_tali_x);
    printf("TaliY (%d) \t = %d IDR \n", jumlah_tali_y, harga_jual_tali_y);

    printf("\n ---= Menu Utama =--- ");
    printf("\n[1] Input pembeli");
    printf("\n[2] Input pembelian");
    printf("\n[3] Rincian");
    printf("\n[4] Reset data");
    printf("\n[0] Logout");

    printf("\n---------------------");
    printf("\n[5] Hitung keuntungan [TUGAS]\n");
}

void printRincian() {
    printf("\n === Rincian === \n");
    printf("Nama                : %s\n", nama_pembeli);
    printf("Waktu kedatangan    : %s - %s\n", tanggal_datang, jam_datang);
    if (strlen(nik) != 0 && strlen(pekerjaan) != 0 && strlen(alamat) != 0) {
        printf("NIK                 : %s\n", nik);
        printf("Pekerjaan           : %s\n", pekerjaan);
        printf("Alamat              : %s\n", alamat);
    }

    printf("\n[ Tali A ] | %d \t| %d IDR \t|---> Total : %d IDR", jumlah_pembelian_a, harga_jual_tali_a, total_pembelian_a);
    printf("\n[ Tali B ] | %d \t| %d IDR \t|---> Total : %d IDR", jumlah_pembelian_b, harga_jual_tali_b, total_pembelian_b);
    printf("\n[ Tali C ] | %d \t| %d IDR \t|---> Total : %d IDR", jumlah_pembelian_c, harga_jual_tali_c, total_pembelian_c);
    printf("\n[ Tali X ] | %d \t| %d IDR \t|---> Total : %d IDR", jumlah_pembelian_x, harga_jual_tali_x, total_pembelian_x);
    printf("\n[ Tali Y ] | %d \t| %d IDR \t|---> Total : %d IDR", jumlah_pembelian_y, harga_jual_tali_y, total_pembelian_y);

    printf("\n");
    printf("\nTotal yang harus dibayar : %d IDR\n", total_pembelian_abcxy);
}

void printKeuntungan() {
    printf("\n === Keuntungan === \n");
    printf("\n[ Keuntungan Tali A ] = %d IDR", total_keuntungan_a);
    printf("\n[ Keuntungan Tali B ] = %d IDR", total_keuntungan_b);
    printf("\n[ Keuntungan Tali C ] = %d IDR", total_keuntungan_c);
    printf("\n[ Keuntungan Tali X ] = %d IDR", total_keuntungan_x);
    printf("\n[ Keuntungan Tali Y ] = %d IDR", total_keuntungan_y);

    printf("\n");
    printf("\nTotal keuntungan      = %d IDR\n", total_keuntungan_abcxy);
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