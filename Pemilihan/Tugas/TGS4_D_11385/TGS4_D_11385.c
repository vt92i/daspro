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

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

typedef char string[40];

int main(int argc, char const *argv[]) {
    string user, password;

    string nama = "x";
    string no_telp, kode_kamar;
    int umur, lama_sewa;

    string jawab;

    bool run = true;

    int pilihan;
    int cekLog = 0;
    int cekInput = 0;
    int cekReservasi = 0;

    float harga, total_harga;
    float diskon;
    float uang_penyewa;

    float kamar_luxury_harga = 1200000;
    string kamar_luxury_kode = "KL";
    string kamar_luxury_fasilitas = "Ya";

    float kamar_business_harga = 1000000;
    string kamar_business_kode = "BS";
    string kamar_business_fasilitas = "Ya";

    float kamar_eksklusif_harga = 850000;
    string kamar_eksklusif_kode = "EL";
    string kamar_eksklusif_fasilitas = "Ya";

    float kamar_reguler_harga = 500000;
    string kamar_reguler_kode = "RL";
    string kamar_reguler_fasilitas = "Tidak";

    float kamar_ekonomi_harga = 350000;
    string kamar_ekonomi_kode = "EM";
    string kamar_ekonomi_fasilitas = "Tidak";

    while (run == true) {
        if (PLATFORM_NAME == "linux")
            system("clear");

        if (PLATFORM_NAME == "windows")
            system("cls");

        printf("\n---= Kos Putra Sejahtera =---");

        if (strlen(nama) > 1)
            printf("\n[ Calon penyewa : %s ]", nama);
        else
            printf("\n[ Calon penyewa : - ]");

        printf("\n1. Login");
        printf("\n2. Display");
        printf("\n3. Reservasi");
        printf("\n4. Pembayaran");
        printf("\n0. Keluar");

        printf("\n\nMenu > ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                if (cekLog == 0) {
                    printf("\n[ LOGIN ]\n");

                    printf("User      : ");
                    scanf("%s", &user);

                    printf("Password  : ");
                    scanf("%s", &password);

                    if ((strcmp(user, "Vila") == 0 && strcmp(password, "11385") == 0) || strcmp(user, "admin") == 0 && strcmp(password, "admin") == 0) {
                        printf("\nBerhasil login[!]\n");
                        cekLog = 1;
                    } else {
                        printf("\nUser tidak ditemukan[!]\n");
                    }
                } else {
                    printf("\nAnda sudah login[!]\n");
                }
                break;

            case 2:
                if (cekLog == 0) {
                    printf("\nAnda harus login terlebih dahulu[!]\n");
                } else {
                    printf("\n\t[ Kamar Kos ] \n");

                    printf("\n[1] Kamar Luxury\n");
                    printf("\tHarga Sewa/bulan        : Rp %.0f\n", kamar_luxury_harga);
                    printf("\tKode kamar              : %s\n", kamar_luxury_kode);
                    printf("\tFasilitas Lengkap       : %s\n", kamar_luxury_fasilitas);

                    printf("\n[2] Kamar Business\n");
                    printf("\tHarga Sewa/bulan        : Rp %.0f\n", kamar_business_harga);
                    printf("\tKode kamar              : %s\n", kamar_business_kode);
                    printf("\tFasilitas Lengkap       : %s\n", kamar_business_fasilitas);

                    printf("\n[3] Kamar Eksklusif\n");
                    printf("\tHarga Sewa/bulan        : Rp %.0f\n", kamar_eksklusif_harga);
                    printf("\tKode kamar              : %s\n", kamar_eksklusif_kode);
                    printf("\tFasilitas Lengkap       : %s\n", kamar_eksklusif_fasilitas);

                    printf("\n[4] Kamar Reguler\n");
                    printf("\tHarga Sewa/bulan        : Rp %.0f\n", kamar_reguler_harga);
                    printf("\tKode kamar              : %s\n", kamar_reguler_kode);
                    printf("\tFasilitas Lengkap       : %s\n", kamar_reguler_fasilitas);

                    printf("\n[5] Kamar Ekonomi\n");
                    printf("\tHarga Sewa/bulan        : Rp %.0f\n", kamar_ekonomi_harga);
                    printf("\tKode kamar              : %s\n", kamar_ekonomi_kode);
                    printf("\tFasilitas Lengkap       : %s\n", kamar_ekonomi_fasilitas);
                }
                break;

            case 3:
                if (cekLog == 0) {
                    printf("\nAnda harus login terlebih dahulu[!]\n");
                } else if (cekReservasi == 1) {
                    printf("\nAnda sudah melakukan reservasi[!]");
                    printf("\nHarap lakukan pembayaran terlebih dahulu[!]\n");
                } else {
                    printf("\n\t[ Reservasi ]\n");

                    printf("Nama          : ");
                    getchar();
                    fflush(stdin);
                    gets(nama);

                    if (!(strlen(nama) > 0)) {
                        printf("\nNama tidak boleh kosong[!]\n");
                        break;
                    }

                    printf("Umur          : ");
                    scanf("%d", &umur);

                    if (!(umur > 0)) {
                        printf("\nUmur harus lebih dari 0[!]\n");
                        break;
                    }

                    printf("No telepon    : ");
                    scanf("%s", &no_telp);

                    printf("Lama sewa     : ");
                    scanf("%d", &lama_sewa);

                    if (!(lama_sewa > 0)) {
                        printf("\nLama sewa harus lebih dari 0[!]\n");
                        break;
                    }

                    printf("Kode kamar    : ");
                    scanf("%s", &kode_kamar);

                    if ((strcmp(kode_kamar, "KL") == 0) || (strcmp(kode_kamar, "BS") == 0) || (strcmp(kode_kamar, "EL") == 0) || (strcmp(kode_kamar, "RL") == 0) || (strcmp(kode_kamar, "EM") == 0)) {
                        printf("\nYakin dengan pesanan ini? [Y/n] : ");
                        scanf("%s", &jawab);
                        if (strcasecmp(jawab, "y") == 0) {
                            printf("Reservasi berhasil[!]\n");
                            cekReservasi = 1;
                        } else {
                            printf("Reservasi gagal[!]\n");
                        }
                    } else {
                        printf("\nKamar tidak ditemukan[!]\n");
                    }
                }
                break;

            case 4:
                if (cekLog == 0) {
                    printf("\nAnda harus login terlebih dahulu[!]\n");
                } else if (cekReservasi == 0) {
                    printf("\nAnda belum melakukan reservasi[!]");
                    printf("\nHarap lakukan reservasi terlebih dahulu[!]\n");
                } else {
                    printf("\n\t[ Pembayaran ]\n");

                    if (strcmp(kode_kamar, "KL") == 0) {
                        printf("Kamar           : Luxury\n");
                        harga = kamar_luxury_harga;
                    } else if (strcmp(kode_kamar, "BS") == 0) {
                        printf("Kamar           : Business\n");
                        harga = kamar_business_harga;
                    } else if (strcmp(kode_kamar, "EL") == 0) {
                        printf("Kamar           : Ekslusif\n");
                        harga = kamar_eksklusif_harga;
                    } else if (strcmp(kode_kamar, "RL") == 0) {
                        printf("Kamar           : Reguler\n");
                        harga = kamar_reguler_harga;
                    } else if (strcmp(kode_kamar, "EM") == 0) {
                        printf("Kamar           : Ekonomi\n");
                        harga = kamar_ekonomi_harga;
                    } else {
                        printf("Kamar           : -\n");
                    }

                    printf("Umur            : %d\n", umur);

                    printf("No telepon      : %s\n", no_telp);
                    printf("Harga kamar     : Rp %.2f\n", harga);

                    printf("Lama sewa       : %d bulan\n", lama_sewa);

                    printf("\n===================================\n");

                    total_harga = harga * lama_sewa;
                    if (lama_sewa >= 5) {
                        diskon = total_harga * 0.06;
                        total_harga = total_harga - diskon;
                        printf("Diskon          : Rp  %.2f\n", diskon);
                    } else {
                        printf("Diskon          : Rp -\n");
                    }

                    printf("Total           : Rp %.2f\n", total_harga);

                    printf("Uang anda       : Rp ");
                    scanf("%f", &uang_penyewa);

                    if (uang_penyewa >= total_harga) {
                        printf("\nKembalian       : Rp %2.f", (uang_penyewa - total_harga));
                        printf("\nPembayaran berhasil[!]\n");
                        cekLog = 0;
                        cekReservasi = 0;
                        strcpy(nama, "x");
                    } else {
                        printf("\nUang tidak cukup[!]\n");
                    }
                }
                break;

            case 0:
                printf("\n[Benidiktus Violaz Morello Anjolie | 210711385 | D]");
                printf("\n[Mengerjakan UGD ini dengan jujur]\n");
                run = false;
                break;

            default:
                printf("\nMenu tidak ada[!]\n");
                break;
        }
        if (PLATFORM_NAME == "linux") {
            initscr();
            getch();
            endwin();
        }

        if (PLATFORM_NAME == "windows")
            getch();
    }
    return 0;
}