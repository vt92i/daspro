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

void tampilMenu();
void tampilListApotek();

bool checkLogin(string username, string password);
bool isOddNumber(int n);

int hitungTotalHarga(int jumlah_pembelian_hydrocodone, int jumlah_pembelian_lisinopril, int jumlah_pembelian_antibiotika_moxicillin, int jumlah_pembelian_epogen);
int hitungPajak(int total_harga);

void clear_screen_f();
void pause_f();

// Benidiktus Violaz Morello Anjolie4
// 210711385
// D

int harga_hydrocodone = 70000;
int harga_lisinopril = 30000;
int harga_antibiotika_moxicillin = 60000;
int harga_epogen = 150000;

int jumlah_pembelian_hydrocodone = 0;
int jumlah_pembelian_lisinopril = 0;
int jumlah_pembelian_antibiotika_moxicillin = 0;
int jumlah_pembelian_epogen = 0;

int main(int argc, char const *argv[]) {
    if (strcmp(PLATFORM_NAME, "linux") == 0)
        pause_f();

    int menu_main;
    int menu_apotek;

    string username, password;
    bool is_authenticated;

    is_authenticated = false;

    int jumlah_pembelian_tmp;

    string nama_pembeli;
    int no_pesanan;

    // bool input_pesanan;
    // bool status_pembayaran;

    int total_harga_tanpa_pajak;
    int total_pajak;
    int total_harga_pajak;
    int total_uang_pembeli;

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
                if (!is_authenticated) {
                    printf("\nTidak bisa akses[!]\n");
                } else {
                    do {
                        clear_screen_f();

                        tampilListApotek();

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
                                    if ((no_pesanan >= 1 && no_pesanan <= 30) && isOddNumber(no_pesanan)) {
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
                                printf("\n SILAHKAN LANJUT KE MENU PEMBAYARAN ):\n");
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
                if (!is_authenticated) {
                    printf("\nTidak bisa akses[!]\n");
                } else {
                    printf("\n ---= RINCIAN PEMBAYARAN =--- ");
                    printf("\nNama              : %s", nama_pembeli);
                    printf("\nNomor pesanan     : %d", no_pesanan);

                    printf("\n\n ---= RINCIAN PESANAN =--- ");
                    printf("\n[1] Hydrocodone               %d", jumlah_pembelian_hydrocodone);
                    printf("\n[2] Lisinopril                %d", jumlah_pembelian_lisinopril);
                    printf("\n[3] Antibiotik Amoxicillin    %d", jumlah_pembelian_antibiotika_moxicillin);
                    printf("\n[4] Epogen                    %d", jumlah_pembelian_epogen);

                    total_harga_tanpa_pajak = hitungTotalHarga(jumlah_pembelian_hydrocodone, jumlah_pembelian_lisinopril, jumlah_pembelian_antibiotika_moxicillin, jumlah_pembelian_epogen);
                    total_pajak = hitungPajak(total_harga_tanpa_pajak);
                    total_harga_pajak = total_harga_tanpa_pajak + total_pajak;

                    printf("\n\n ---= TOTAL =--- ");
                    printf("\nTotal harga (tanpa pajak)   : %d", total_harga_tanpa_pajak);
                    printf("\nTotal pajak                 : %d", total_pajak);
                    printf("\nTotal harga + pajak         : %d", total_harga_pajak);

                    printf("\n\nLanjut ke pembayaran? (Y/n)");
                    scanf("%s", answer);

                    if (strcmp(answer, "Y") == 0) {
                        printf("Masukan uang    : ");
                        scanf("%d", &total_uang_pembeli);

                        if (total_uang_pembeli >= total_harga_pajak) {
                            printf("\nPembayaran berhasil[!]\n");
                            printf("Kembalian : %d\n", total_uang_pembeli - total_harga_pajak);
                        } else {
                            printf("\nPembayaran gagal[!]\n");
                        }
                    }
                }
                break;

            default:
                printf("\nMenu tidak tersedia[!]\n");
                break;
        }
        pause_f();
    } while (menu_main != 0);

    return 0;
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

void tampilListApotek() {
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

int hitungTotalHarga(int jumlah_pembelian_hydrocodone, int jumlah_pembelian_lisinopril, int jumlah_pembelian_antibiotika_moxicillin, int jumlah_pembelian_epogen) {
    int total_harga = (jumlah_pembelian_hydrocodone * harga_hydrocodone) + (jumlah_pembelian_lisinopril * harga_lisinopril) + (jumlah_pembelian_antibiotika_moxicillin * harga_antibiotika_moxicillin) + (jumlah_pembelian_epogen * harga_epogen);
    return total_harga;
}

int hitungPajak(int total_harga) {
    return total_harga * 0.12;
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