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

void initDataLogin();
void initDataObat();
void initDataPembelian();

void tampilMenu();
void tampilListObat();

bool checkLogin(string username, string password);
bool isOddNumber(int n);
bool isNumberBetween(int n, int min, int max);
bool isValidOrderNumber(int order_number);

int hitungTotalHarga(int jumlah_pembelian_hydrocodone, int jumlah_pembelian_lisinopril, int jumlah_pembelian_antibiotika_moxicillin, int jumlah_pembelian_epogen);
int hitungPajak(int total_harga);
int hitungDiskon(int total_harga_pajak);

void clear_screen_f();
void pause_f();

// Data Login
string username, password;
bool is_authenticated;

// Data Obat
int harga_hydrocodone, harga_lisinopril, harga_antibiotika_moxicillin, harga_epogen;

// Data Pembelian
bool status_pesanan;

string nama_pembeli;
int no_pesanan;

int jumlah_pembelian_hydrocodone, jumlah_pembelian_lisinopril, jumlah_pembelian_antibiotika_moxicillin, jumlah_pembelian_epogen;
int total_harga_tanpa_pajak, total_pajak, total_harga_pajak, total_diskon, total_uang_pembeli;

// Benidiktus Violaz Morello Anjolie4
// 210711385
// D

int main(int argc, char const *argv[]) {
    if (strcmp(PLATFORM_NAME, "linux") == 0)
        pause_f();

    initDataLogin();
    initDataObat();
    initDataPembelian();

    int menu_main;
    int menu_apotek;
    int jumlah_pembelian_tmp;
    string answer;

    do {
        clear_screen_f();

        tampilMenu();
        printf("\nMenu >> ");
        scanf("%d", &menu_main);

        switch (menu_main) {
            case 1:
                if (!is_authenticated) {
                    printf("\n---= LOGIN FORM =---\n");

                    printf("\n");
                    printf("Username (Apotek24OK)   : ");
                    scanf("%s", username);

                    printf("Password (11385)        : ");
                    scanf("%s", password);

                    if (strcmp(username, "0") != 0 && strcmp(password, "0") != 0)
                        is_authenticated = checkLogin(username, password);
                    else
                        break;
                } else {
                    printf("\nAnda sudah login[!]\n");
                }
                break;

            case 2:
                if (!is_authenticated || status_pesanan) {
                    printf("\nTidak bisa akses[!]\n");
                } else {
                    do {
                        clear_screen_f();

                        tampilListObat();

                        printf("\nMenu >> ");
                        scanf("%d", &menu_apotek);

                        switch (menu_apotek) {
                            case 1:
                                printf("\nMasukan jumlah pembelian : ");
                                scanf("%d", &jumlah_pembelian_tmp);
                                if (jumlah_pembelian_tmp >= 1) {
                                    printf("\nBerhasil memesan dengan jumlah %d \n", jumlah_pembelian_tmp);
                                    jumlah_pembelian_hydrocodone += jumlah_pembelian_tmp;
                                } else {
                                    printf("\nERROR[!]\n");
                                }
                                break;

                            case 2:
                                printf("\nMasukan jumlah pembelian : ");
                                scanf("%d", &jumlah_pembelian_tmp);
                                if (jumlah_pembelian_tmp >= 1) {
                                    printf("\nBerhasil memesan dengan jumlah %d \n", jumlah_pembelian_tmp);
                                    jumlah_pembelian_lisinopril += jumlah_pembelian_tmp;
                                } else {
                                    printf("\nERROR[!]\n");
                                }
                                break;

                            case 3:
                                printf("\nMasukan jumlah pembelian : ");
                                scanf("%d", &jumlah_pembelian_tmp);
                                if (jumlah_pembelian_tmp >= 1) {
                                    printf("\nBerhasil memesan dengan jumlah %d \n", jumlah_pembelian_tmp);
                                    jumlah_pembelian_antibiotika_moxicillin += jumlah_pembelian_tmp;
                                } else {
                                    printf("\nERROR[!]\n");
                                }
                                break;

                            case 4:
                                printf("\nMasukan jumlah pembelian : ");
                                scanf("%d", &jumlah_pembelian_tmp);
                                if (jumlah_pembelian_tmp >= 1) {
                                    printf("\nBerhasil memesan dengan jumlah %d \n", jumlah_pembelian_tmp);
                                    jumlah_pembelian_epogen += jumlah_pembelian_tmp;
                                } else {
                                    printf("\nERROR[!]\n");
                                }
                                break;

                            case 0:
                                printf("\nMasukan nama                            : ");
                                scanf("%s", nama_pembeli);

                                while (true) {
                                    printf("\nMasukan nomor pesanan [1 - 30 Ganjil]   : ");
                                    scanf("%d", &no_pesanan);
                                    if (isValidOrderNumber(no_pesanan)) {
                                        break;
                                    } else {
                                        printf("\nHarus antara 1 - 30 dan Ganjil[!]\n");
                                    }
                                }

                                printf("\n ---= RINCIAN PESANAN =--- ");
                                printf("\n[1] Hydrocodone               %d", jumlah_pembelian_hydrocodone);
                                printf("\n[2] Lisinopril                %d", jumlah_pembelian_lisinopril);
                                printf("\n[3] Antibiotik Amoxicillin    %d", jumlah_pembelian_antibiotika_moxicillin);
                                printf("\n[4] Epogen                    %d", jumlah_pembelian_epogen);
                                printf("\n---------------------");
                                printf("\n [ SILAHKAN LANJUT KE MENU PEMBAYARAN ): ] \n");

                                status_pesanan = true;
                                break;

                            default:
                                printf("\nMenu tidak tersedia[!]\n");
                                break;
                        }
                        pause_f();
                    } while (menu_apotek != 0);
                }
                break;

            case 3:
                if (!is_authenticated || !status_pesanan) {
                    printf("\nTidak bisa akses[!]\n");
                } else {
                    printf("\n ---= RINCIAN PEMBAYARAN =--- ");
                    printf("\nNama pembelian    : %s", nama_pembeli);
                    printf("\nNomor pesanan     : %d", no_pesanan);

                    printf("\n\n ---= RINCIAN PESANAN =--- ");
                    printf("\n[1] Hydrocodone               %d", jumlah_pembelian_hydrocodone);
                    printf("\n[2] Lisinopril                %d", jumlah_pembelian_lisinopril);
                    printf("\n[3] Antibiotik Amoxicillin    %d", jumlah_pembelian_antibiotika_moxicillin);
                    printf("\n[4] Epogen                    %d", jumlah_pembelian_epogen);

                    total_harga_tanpa_pajak = hitungTotalHarga(jumlah_pembelian_hydrocodone, jumlah_pembelian_lisinopril, jumlah_pembelian_antibiotika_moxicillin, jumlah_pembelian_epogen);
                    total_pajak = hitungPajak(total_harga_tanpa_pajak);
                    total_harga_pajak = total_harga_tanpa_pajak + total_pajak;
                    if (jumlah_pembelian_antibiotika_moxicillin >= 5 && jumlah_pembelian_epogen >= 2)
                        total_diskon = hitungDiskon(total_harga_pajak);

                    printf("\n\n ---= TOTAL =--- ");
                    printf("\nTotal harga (tanpa pajak)   : %d", total_harga_tanpa_pajak);
                    printf("\nTotal pajak                 : %d", total_pajak);
                    printf("\nTotal harga + pajak         : %d", total_harga_pajak);
                    printf("\nTotal diskon                : %d", total_diskon);

                    printf("\n\nLanjut ke pembayaran? (Y/n)");
                    scanf("%s", answer);

                    if (strcmp(answer, "Y") == 0) {
                        printf("\n\n ---= PEMBAYARAN =--- ");

                        while (true) {
                            printf("\nMasukan uang                : ");
                            scanf("%d", &total_uang_pembeli);

                            if (total_uang_pembeli >= total_harga_pajak) {
                                printf("Total harga + pajak         : %d", total_harga_pajak);
                                printf("\nTotal diskon                : %d", total_diskon);
                                printf("\nKembalian                   : %d", total_uang_pembeli - total_harga_pajak - total_diskon);
                                printf("\n\nPembayaran berhasil[!]\n");
                                initDataPembelian();
                                break;
                            } else {
                                printf("\nUang tidak cukup[!]\n");
                            }
                        }
                    }
                }
                break;

            case 4:
                if (!is_authenticated || !status_pesanan) {
                    printf("\nTidak bisa akses[!]\n");
                } else {
                    printf("\n ---= Reset Data Pembelian =--- ");
                    printf("\nApakah anda yakin ingin menghapus data? (Y/n)");
                    scanf("%s", answer);
                    if (strcmp(answer, "Y") == 0) {
                        printf("\nData berhasil dihapus[!]\n");
                        initDataPembelian();
                    }
                }
                break;

            case 0:
                printf("\n");
                printf("[!] Program keluar [!] \n");
                printf("[!] Benidiktus Violaz Morello Anjolie - 210711385 - D [!] \n");
                break;

            default:
                printf("\nMenu tidak tersedia[!]\n");
                break;
        }
        pause_f();
    } while (menu_main != 0);

    return 0;
}

void initDataLogin() {
    strcpy(username, "");
    strcpy(password, "");
    is_authenticated = false;
}

void initDataObat() {
    harga_hydrocodone = 70000;
    harga_lisinopril = 30000;
    harga_antibiotika_moxicillin = 60000;
    harga_epogen = 150000;
}

void initDataPembelian() {
    status_pesanan = false;

    strcpy(nama_pembeli, "");
    no_pesanan = 1;

    jumlah_pembelian_hydrocodone = 0;
    jumlah_pembelian_lisinopril = 0;
    jumlah_pembelian_antibiotika_moxicillin = 0;
    jumlah_pembelian_epogen = 0;

    total_harga_tanpa_pajak = 0;
    total_pajak = 0;
    total_harga_pajak = 0;
    total_diskon = 0;
    total_uang_pembeli = 0;
}

void tampilMenu() {
    printf("\n ---= APOTEK 24 OK =--- ");
    printf("\n[1] Login");
    printf("\n[2] Input pesanan");
    printf("\n[3] Pembayaran");
    printf("\n[4] Batalkan pesanan");
    printf("\n[5] Edit pesanan [TUGAS]");
    printf("\n[0] Keluar");
    printf("\n---------------------");
}

void tampilListObat() {
    printf("\n ---= DAFTAR OBAT =--- ");
    printf("\n[1] Hydrocodone               %d IDR", harga_hydrocodone);
    printf("\n[2] Lisinopril                %d IDR", harga_lisinopril);
    printf("\n[3] Antibiotik Amoxicillin    %d IDR", harga_antibiotika_moxicillin);
    printf("\n[4] Epogen                    %d IDR", harga_epogen);
    printf("\n[0] Keluar");
    printf("\n---------------------");
}

bool checkLogin(string username, string password) {
    if (strcmp(username, "Apotek24OK") == 0 && strcmp(password, "11385") == 0) {
        printf("\n[OK] Login berhasil[!]\n");
        return true;
    } else {
        printf("\n[ERROR] Username atau Password salah[!]\n");
        return false;
    }
}

bool isOddNumber(int n) {
    if (n % 2 != 0)
        return true;
    return false;
}

bool isNumberBetween(int n, int min, int max) {
    if (n >= min && n <= max)
        return true;
    return false;
}

bool isValidOrderNumber(int order_number) {
    if (isNumberBetween(order_number, 1, 30) && isOddNumber(order_number))
        return true;
    return false;
}

int hitungTotalHarga(int jumlah_pembelian_hydrocodone, int jumlah_pembelian_lisinopril, int jumlah_pembelian_antibiotika_moxicillin, int jumlah_pembelian_epogen) {
    return (jumlah_pembelian_hydrocodone * harga_hydrocodone) + (jumlah_pembelian_lisinopril * harga_lisinopril) + (jumlah_pembelian_antibiotika_moxicillin * harga_antibiotika_moxicillin) + (jumlah_pembelian_epogen * harga_epogen);
}

int hitungPajak(int total_harga) {
    return total_harga * 0.12;
}

int hitungDiskon(int total_harga_pajak) {
    return total_harga_pajak * 0.0022;
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