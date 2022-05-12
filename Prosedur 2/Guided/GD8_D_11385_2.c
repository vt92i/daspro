#if defined(_WIN32) || defined(_WIN64)
    #define PLATFORM_NAME "windows"
    #include <conio.h>
#endif

#if defined(__linux__)
    #define PLATFORM_NAME "linux"
    #include <ncurses.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define hargaA 500000
#define hargaB 650000
#define hargaC 700000

#define MAX 64
typedef char string[MAX];

void inisialisasi(int *toleransi, int *tipeA, int *tipeB, int *tipeC, int *pembeli, int *pembelian, int *jmlA, int *jmlB, int *jmlC, int *totA, int *totB, int *totC, int *total);
void cekLogin(int *cek, string user, int pass);
void penjumlahan(int *angka, int penjumlahan);
void pengurangan(int *angka, int pengurangan);
void perkalian(int *hasil, int angka, int pengali);
void cekHarga(int *harga, string tipe);
void cekJumlahTipe(int *temp, int tasA, int tasB, int tasC, string tipe);
void pembaruanKetersediaanTas(int *tasA, int *tasB, int *tasC, int *jmlA, int *jmlB, int *jmlC, int jml, string tipe);
void printRincian(string nama, string tgl, int jmlA, int jmlB, int jmlC, int totA, int totB, int totC, int total);
void hitungTotal(int *tot, int jmlA, int jmlB, int jmlC);
void cekLogout(int *logout, string konfirm);

void clear_screen_f();
void pause_f();

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

int main(int argc, char const *argv[]) {
    string user, konfirm, nama, tgl, tipe;
    int pass, menu, cek, logout, harga, jumlah, tempJumlah;
    int toleransi, tipeA, tipeB, tipeC, pembeli, pembelian, jmlA, jmlB, jmlC, totA, totB, totC, total;

    inisialisasi(&toleransi, &tipeA, &tipeB, &tipeC, &pembeli, &pembelian, &jmlA, &jmlB, &jmlC, &totA, &totB, &totC, &total);

    if (PLATFORM_NAME == "linux")
        pause_f();

    do {
        logout = 0;
        clear_screen_f();
        printf("\n---= LOGIN FORM =---\n");
        printf("[ Toleransi : %d ]\n", toleransi);

        printf("\n");
        printf("Username : ");
        scanf("%s", &user);

        printf("Password : ");
        scanf("%d", &pass);

        cekLogin(&cek, user, pass);

        if (cek == 1) {
            do {
                clear_screen_f();

                printf("\n ---= TOKO TAS SISKA =--- \n");

                printf("\n === Daftar Barang === \n");
                printf("Barang (Stok) \t = Harga\n");
                printf("TipeA (%d) \t = %d IDR \n", tipeA, hargaA);
                printf("TipeB (%d) \t = %d IDR \n", tipeB, hargaB);
                printf("TipeC (%d) \t = %d IDR \n", tipeC, hargaC);

                printf("\n === Menu Utama ===");
                printf("\n[1] Input data pembeli");
                printf("\n[2] Input pembelian");
                printf("\n[3] Rincian");
                printf("\n[0] Logout");
                printf("\n---------------------");
                printf("\nMenu >> ");

                scanf("%d", &menu);

                switch (menu) {
                    case 1:
                        if (pembeli == 1) {
                            printf("\nData pembeli sudah terinput[!]\n");
                        } else {
                            printf("\n === Input Data Pembeli === \n");

                            printf("Nama \t\t  : ");
                            scanf("%s", &nama);
                            while (strlen(nama) == 0 || strcmp(nama, "-") == 0) {
                                printf("\nNama tidak boleh kosong[!]");
                                printf("\nNama \t\t : ");
                                scanf("%s", &nama);
                            }

                            printf("Tanggal pembelian : ");
                            scanf("%s", &tgl);
                            while (strlen(tgl) != 10) {
                                printf("\nFormat tanggal salah[!]\n");
                                printf("\nTanggal pembelian : ");
                                scanf("%s", &tgl);
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

                            printf("Tipe tas (A/B/C) : ");
                            scanf("%s", tipe);
                            while (strcmp(tipe, "A") != 0 && strcmp(tipe, "B") != 0 && strcmp(tipe, "C") != 0) {
                                printf("\nTipe tidak diketahui[!]\n");
                                printf("Tipe tas (A/B/C) : ");
                                scanf("%s", tipe);
                            }

                            cekHarga(&harga, tipe);
                            printf("\nHarga \t\t : %d IDR per pcs", harga);

                            printf("\nJumlah pembelian : ");
                            scanf("%d", &jumlah);
                            cekJumlahTipe(&tempJumlah, tipeA, tipeB, tipeC, tipe);

                            if (jumlah <= 0) {
                                ("\nJumlah pembelian tidak boleh kurang dari 1[!]\n");
                            } else if (jumlah > tempJumlah) {
                                printf("\nJumlah pembelian melebihi ketersediaan[!]\n");
                            } else {
                                pembaruanKetersediaanTas(&tipeA, &tipeB, &tipeC, &jmlA, &jmlB, &jmlC, jumlah, tipe);
                                printf("\nBerhasil input data pembelian[!]\n");
                                pembelian = 1;
                            }
                        }
                        break;

                    case 3:
                        if (pembeli == 0) {
                            printf("\nData pembeli belum terinput[!]\n");
                        } else if (pembelian == 0) {
                            printf("\nData pembelian belum terinput[!]\n");
                        } else {
                            printf("\n === Rincian Pembelian === \n");
                            perkalian(&totA, jmlA, hargaA);
                            perkalian(&totB, jmlB, hargaB);
                            perkalian(&totC, jmlC, hargaC);

                            hitungTotal(&total, totA, totB, totC);
                            printRincian(nama, tgl, jmlA, jmlB, jmlC, totA, totB, totC, total);
                        }
                        break;

                    case 0:
                        printf("\nYakin ingin logout? (Y/n)");
                        scanf("%s", &konfirm);
                        cekLogout(&logout, konfirm);

                        if (logout == 1) {
                            printf("Terima kasih [!]\n");
                            inisialisasi(&toleransi, &tipeA, &tipeB, &tipeC, &pembeli, &pembelian, &jmlA, &jmlB, &jmlC, &totA, &totB, &totC, &total);
                        }
                        break;

                    default:
                        printf("\nMenu tidak tersedia[!]\n");
                        break;
                }
                pause_f();
            } while (logout != 1);
        } else {
            printf("\n[Error] Username atau Password salah[!]\n");
            pengurangan(&toleransi, 1);
        }
        pause_f();
    } while (toleransi != 0);

    printf("Keluar [!]\n");
    printf("Terima kasih [!]\n");

    return 0;
}

void inisialisasi(int *toleransi, int *tipeA, int *tipeB, int *tipeC, int *pembeli, int *pembelian, int *jmlA, int *jmlB, int *jmlC, int *totA, int *totB, int *totC, int *total) {
    *toleransi = 5;
    *tipeA = 10;
    *tipeB = 10;
    *tipeC = 10;
    *pembeli = 0;
    *pembelian = 0;
    *jmlA = 0;
    *jmlB = 0;
    *jmlC = 0;
    *totA = 0;
    *totB = 0;
    *totC = 0;
    *total = 0;
}

void cekLogin(int *cek, string user, int pass) {
    if (strcmp(user, "Siska") == 0 && pass == 12345) {
        *cek = 1;
        printf("\n[OK] Login berhasil[!]\n");
        pause_f();
    } else {
        *cek = 0;
    }
}

void penjumlahan(int *angka, int penjumlahan) {
    *angka = (*angka) + penjumlahan;
}

void pengurangan(int *angka, int pengurang) {
    *angka = (*angka) - pengurang;
}

void perkalian(int *hasil, int angka, int pengali) {
    *hasil = angka * pengali;
}

void cekHarga(int *harga, string tipe) {
    if (strcmp(tipe, "A") == 0) {
        *harga = hargaA;
    } else if (strcmp(tipe, "B") == 0) {
        *harga = hargaB;
    } else {
        *harga = hargaC;
    }
}

void cekJumlahTipe(int *temp, int tasA, int tasB, int tasC, string tipe) {
    if (strcmp(tipe, "A") == 0) {
        *temp = tasA;
    } else if (strcmp(tipe, "B") == 0) {
        *temp = tasB;
    } else {
        *temp = tasC;
    }
}

void pembaruanKetersediaanTas(int *tasA, int *tasB, int *tasC, int *jmlA, int *jmlB, int *jmlC, int jml, string tipe) {
    if (strcmp(tipe, "A") == 0) {
        pengurangan(&(*tasA), jml);
        penjumlahan(&(*jmlA), jml);
    } else if (strcmp(tipe, "B") == 0) {
        pengurangan(&(*tasB), jml);
        penjumlahan(&(*jmlB), jml);
    } else {
        pengurangan(&(*tasC), jml);
        penjumlahan(&(*jmlC), jml);
    }
}

void printRincian(string nama, string tgl, int jmlA, int jmlB, int jmlC, int totA, int totB, int totC, int total) {
    printf("Nama              : %s", nama);
    printf("\nTanggal pembelian : %s\n", tgl);

    printf("\n[Tas A]  | %d |\t| %d IDR |\t---> Total : %d IDR", jmlA, hargaA, totA);
    printf("\n[Tas B]  | %d |\t| %d IDR |\t---> Total : %d IDR", jmlB, hargaB, totB);
    printf("\n[Tas C]  | %d |\t| %d IDR |\t---> Total : %d IDR", jmlC, hargaC, totC);

    printf("\n");
    printf("\nTotal yang harus dibayar : %d IDR\n", total);
}

void hitungTotal(int *tot, int jmlA, int jmlB, int jmlC) {
    *tot = jmlA + jmlB + jmlC;
}

void cekLogout(int *logout, string konfirm) {
    if (strcmp(konfirm, "Y") == 0) {
        *logout = 1;
    } else {
        *logout = 0;
    }
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