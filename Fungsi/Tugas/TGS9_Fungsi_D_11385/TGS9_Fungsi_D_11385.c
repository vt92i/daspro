#if defined(_WIN32) || defined(_WIN64)
    #define PLATFORM_NAME "windows"
    #include <conio.h>
#endif

#if defined(__linux__)
    #define PLATFORM_NAME "linux"
    #include <ncurses.h>
#endif

#include <locale.h>
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
void tampilRincianPesanan();

bool checkLogin(string username, string password);
bool isOddNumber(int n);
bool isNumberBetween(int n, int min, int max);
bool isValidOrderNumber(int order_number);

int hitungTotalHarga(int jumlah_pembelian_hydrocodone, int jumlah_pembelian_lisinopril, int jumlah_pembelian_antibiotika_moxicillin, int jumlah_pembelian_epogen);
int hitungPajak(int total_harga);
int hitungDiskon(int total_harga_pajak);
int hitungDiskonMember(int total_harga_pajak);

int orderObat(int jumlah_pembelian_obat, int n);
int tambahJumlahPembelianObat(int jumlah_pembelian_obat, int n);
int kurangJumlahPembelianObat(int jumlah_pembelian_obat, int n);

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
bool apakah_member;
int no_pesanan;

int jumlah_pembelian_hydrocodone, jumlah_pembelian_lisinopril, jumlah_pembelian_antibiotika_moxicillin, jumlah_pembelian_epogen;
int total_harga_tanpa_pajak, total_pajak, total_harga_pajak, total_diskon, total_diskon_member, total_uang_pembeli;

// Benidiktus Violaz Morello Anjolie4
// 210711385
// D

int main(int argc, char const *argv[]) {
    if (strcmp(PLATFORM_NAME, "linux") == 0) {
        pause_f();
        setlocale(LC_NUMERIC, "en_US");
    }

    initDataLogin();
    initDataObat();
    initDataPembelian();

    int menu_main;
    int menu_apotek;
    int menu_edit_pesanan;
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
                                jumlah_pembelian_hydrocodone = orderObat(jumlah_pembelian_hydrocodone, jumlah_pembelian_tmp);
                                break;

                            case 2:
                                printf("\nMasukan jumlah pembelian : ");
                                scanf("%d", &jumlah_pembelian_tmp);
                                jumlah_pembelian_lisinopril = orderObat(jumlah_pembelian_lisinopril, jumlah_pembelian_tmp);
                                break;

                            case 3:
                                printf("\nMasukan jumlah pembelian : ");
                                scanf("%d", &jumlah_pembelian_tmp);
                                jumlah_pembelian_antibiotika_moxicillin = orderObat(jumlah_pembelian_antibiotika_moxicillin, jumlah_pembelian_tmp);
                                break;

                            case 4:
                                printf("\nMasukan jumlah pembelian : ");
                                scanf("%d", &jumlah_pembelian_tmp);
                                jumlah_pembelian_epogen = orderObat(jumlah_pembelian_epogen, jumlah_pembelian_tmp);
                                break;

                            case 0:
                                printf("\nMasukan nama                            : ");
                                scanf("%s", nama_pembeli);

                                while (true) {
                                    printf("\nMasukan nomor pesanan [1 - 30 Ganjil]   : ");
                                    scanf("%d", &no_pesanan);
                                    if (isValidOrderNumber(no_pesanan))
                                        break;
                                    else
                                        printf("\nHarus antara 1 - 30 dan Ganjil[!]\n");
                                }

                                while (true) {
                                    printf("\nApakah anda adalah member? (Y/n)");
                                    scanf("%s", answer);
                                    if (strcmp(answer, "Y") == 0)
                                        apakah_member = true;
                                    else
                                        apakah_member = false;
                                    break;
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
                    if (apakah_member)
                        total_diskon_member = hitungDiskonMember(total_harga_pajak - total_diskon);

                    printf("\n\n ---= TOTAL =--- ");
                    printf("\nTotal harga (tanpa pajak)   : %'d IDR", total_harga_tanpa_pajak);
                    printf("\nTotal pajak                 : %'d IDR", total_pajak);
                    printf("\nTotal harga + pajak         : %'d IDR", total_harga_pajak);
                    printf("\nTotal diskon                : %'d IDR", total_diskon);
                    printf("\nTotal diskon member         : %'d IDR", total_diskon_member);

                    printf("\n\nLanjut ke pembayaran? (Y/n)");
                    scanf("%s", answer);

                    if (strcmp(answer, "Y") == 0) {
                        printf("\n\n ---= PEMBAYARAN =--- ");

                        while (true) {
                            printf("\nMasukan uang                : ");
                            scanf("%d", &total_uang_pembeli);
                            if (total_uang_pembeli >= total_harga_pajak) {
                                printf("Total uang pembeli          : %'d IDR", total_uang_pembeli);
                                printf("\nTotal harga + pajak         : %'d IDR", total_harga_pajak);
                                printf("\nTotal diskon                : %'d IDR", total_diskon);
                                printf("\nTotal diskon member         : %'d IDR", total_diskon_member);
                                printf("\nKembalian                   : %'d IDR", total_uang_pembeli - total_harga_pajak + total_diskon + total_diskon_member);
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

            case 5:
                if (!is_authenticated || !status_pesanan) {
                    printf("\nTidak bisa akses[!]\n");
                } else {
                    do {
                        clear_screen_f();

                        tampilRincianPesanan();

                        printf("\nMenu >> ");
                        scanf("%d", &menu_edit_pesanan);

                        switch (menu_edit_pesanan) {
                            case 1:
                                printf("\n[1] Tambah");
                                printf("\n[2] Kurang");
                                printf("\nMenu >> ");
                                scanf("%d", &menu_edit_pesanan);
                                switch (menu_edit_pesanan) {
                                    case 1:
                                        printf("\nMasukan jumlah tambah : ");
                                        scanf("%d", &jumlah_pembelian_tmp);
                                        jumlah_pembelian_hydrocodone = tambahJumlahPembelianObat(jumlah_pembelian_hydrocodone, jumlah_pembelian_tmp);
                                        break;

                                    case 2:
                                        if (jumlah_pembelian_hydrocodone == 0) {
                                            printf("\nAnda belum memesan obat ini[!]\n");
                                            break;
                                        }
                                        printf("\nMasukan jumlah kurang : ");
                                        scanf("%d", &jumlah_pembelian_tmp);
                                        jumlah_pembelian_hydrocodone = kurangJumlahPembelianObat(jumlah_pembelian_hydrocodone, jumlah_pembelian_tmp);
                                        break;

                                    default:
                                        printf("\nERROR[!]\n");
                                        break;
                                }
                                break;

                            case 2:
                                printf("\n[1] Tambah");
                                printf("\n[2] Kurang");
                                printf("\nMenu >> ");
                                scanf("%d", &menu_edit_pesanan);
                                switch (menu_edit_pesanan) {
                                    case 1:
                                        printf("\nMasukan jumlah tambah : ");
                                        scanf("%d", &jumlah_pembelian_tmp);
                                        jumlah_pembelian_lisinopril = tambahJumlahPembelianObat(jumlah_pembelian_lisinopril, jumlah_pembelian_tmp);
                                        break;

                                    case 2:
                                        if (jumlah_pembelian_lisinopril == 0) {
                                            printf("\nAnda belum memesan obat ini[!]\n");
                                            break;
                                        }
                                        printf("\nMasukan jumlah kurang : ");
                                        scanf("%d", &jumlah_pembelian_tmp);
                                        jumlah_pembelian_lisinopril = kurangJumlahPembelianObat(jumlah_pembelian_lisinopril, jumlah_pembelian_tmp);
                                        break;

                                    default:
                                        printf("\nERROR[!]\n");
                                        break;
                                }
                                break;

                            case 3:
                                printf("\n[1] Tambah");
                                printf("\n[2] Kurang");
                                printf("\nMenu >> ");
                                scanf("%d", &menu_edit_pesanan);
                                switch (menu_edit_pesanan) {
                                    case 1:
                                        printf("\nMasukan jumlah tambah : ");
                                        scanf("%d", &jumlah_pembelian_tmp);
                                        jumlah_pembelian_antibiotika_moxicillin = tambahJumlahPembelianObat(jumlah_pembelian_antibiotika_moxicillin, jumlah_pembelian_tmp);
                                        break;

                                    case 2:
                                        if (jumlah_pembelian_antibiotika_moxicillin == 0) {
                                            printf("\nAnda belum memesan obat ini[!]\n");
                                            break;
                                        }
                                        printf("\nMasukan jumlah kurang : ");
                                        scanf("%d", &jumlah_pembelian_tmp);
                                        jumlah_pembelian_antibiotika_moxicillin = kurangJumlahPembelianObat(jumlah_pembelian_antibiotika_moxicillin, jumlah_pembelian_tmp);
                                        break;

                                    default:
                                        printf("\nERROR[!]\n");
                                        break;
                                }
                                break;

                            case 4:
                                printf("\n[1] Tambah");
                                printf("\n[2] Kurang");
                                printf("\nMenu >> ");
                                scanf("%d", &menu_edit_pesanan);
                                switch (menu_edit_pesanan) {
                                    case 1:
                                        printf("\nMasukan jumlah tambah : ");
                                        scanf("%d", &jumlah_pembelian_tmp);
                                        jumlah_pembelian_epogen = tambahJumlahPembelianObat(jumlah_pembelian_epogen, jumlah_pembelian_tmp);
                                        break;

                                    case 2:
                                        if (jumlah_pembelian_epogen == 0) {
                                            printf("\nAnda belum memesan obat ini[!]\n");
                                            break;
                                        }
                                        printf("\nMasukan jumlah kurang : ");
                                        scanf("%d", &jumlah_pembelian_tmp);
                                        jumlah_pembelian_epogen = kurangJumlahPembelianObat(jumlah_pembelian_epogen, jumlah_pembelian_tmp);
                                        break;

                                    default:
                                        printf("\nERROR[!]\n");
                                        break;
                                }
                                break;

                            case 0:
                                printf("\nBerhasil[!]\n");
                                break;

                            default:
                                printf("\nMenu tidak tersedia[!]\n");
                                break;
                        }
                        pause_f();
                    } while (menu_edit_pesanan != 0);
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
    apakah_member = false;
    no_pesanan = 1;

    jumlah_pembelian_hydrocodone = 0;
    jumlah_pembelian_lisinopril = 0;
    jumlah_pembelian_antibiotika_moxicillin = 0;
    jumlah_pembelian_epogen = 0;

    total_harga_tanpa_pajak = 0;
    total_pajak = 0;
    total_harga_pajak = 0;
    total_diskon = 0;
    total_diskon_member = 0;
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
    printf("\n[1] Hydrocodone               %'d IDR", harga_hydrocodone);
    printf("\n[2] Lisinopril                %'d IDR", harga_lisinopril);
    printf("\n[3] Antibiotik Amoxicillin    %'d IDR", harga_antibiotika_moxicillin);
    printf("\n[4] Epogen                    %'d IDR", harga_epogen);
    printf("\n[0] Keluar");
    printf("\n---------------------");
}

void tampilRincianPesanan() {
    printf("\n ---= RINCIAN PESANAN =--- ");
    printf("\n[1] Hydrocodone               %d", jumlah_pembelian_hydrocodone);
    printf("\n[2] Lisinopril                %d", jumlah_pembelian_lisinopril);
    printf("\n[3] Antibiotik Amoxicillin    %d", jumlah_pembelian_antibiotika_moxicillin);
    printf("\n[4] Epogen                    %d", jumlah_pembelian_epogen);
    printf("\n[0] Selesai");
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

int hitungDiskonMember(int total_harga_pajak) {
    return total_harga_pajak * 0.055;
}

int orderObat(int jumlah_pembelian_obat, int n) {
    if (n >= 1) {
        printf("\nBerhasil memesan dengan jumlah %d \n", n);
        return jumlah_pembelian_obat + n;
    } else {
        printf("\nPesanan tidak boleh kurang dari 1[!]\n");
        return jumlah_pembelian_obat;
    }
}

int tambahJumlahPembelianObat(int jumlah_pembelian_obat, int n) {
    if (n >= 1) {
        printf("\nBerhasil [!]\n");
        return jumlah_pembelian_obat + n;
    } else {
        printf("\nTidak boleh kurang dari 1[!]\n");
        return jumlah_pembelian_obat;
    }
}

int kurangJumlahPembelianObat(int jumlah_pembelian_obat, int n) {
    if (n >= 1) {
        if (jumlah_pembelian_obat - n >= 0) {
            printf("\nBerhasil [!]\n");
            return jumlah_pembelian_obat - n;
        } else {
            printf("\nTidak boleh lebih dari %d [!]\n", jumlah_pembelian_obat);
            return jumlah_pembelian_obat;
        }
    } else {
        printf("\nTidak boleh kurang dari 1[!]\n");
        return jumlah_pembelian_obat;
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