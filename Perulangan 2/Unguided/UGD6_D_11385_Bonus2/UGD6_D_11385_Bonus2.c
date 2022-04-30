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

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

int main(int argc, char const *argv[]) {
    int i, j;

    int menu, cekMenu;
    cekMenu = 0;

    int total_paket;
    float harga_per_paket = 12000;
    float total_harga, total_diskon;

    do {
        if (PLATFORM_NAME == "linux")
            system("clear");

        if (PLATFORM_NAME == "windows")
            system("cls");

        printf("\n---= Toko Alat Tulis =---");

        printf("\n[1] Masukan pesanan");
        printf("\n[2] Print bukti pembayaran");
        printf("\n[3] Kupon");
        printf("\n[4] Tugas");
        printf("\n[0] Keluar");
        printf("\n---------------------");

        printf("\nMenu >> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                do {
                    printf("\n[ Pesanan ]\n");
                    printf("Masukan banyak pesanan alat tulis (Rp 12,000 per Paket) : ");
                    scanf("%d", &total_paket);

                    if (total_paket < 1) {
                        printf("\nPesanan tidak boleh kurang dari 1[!]\n");
                    } else {
                        printf("\nBerhasil input pesanan[!]\n");
                        total_harga = harga_per_paket * total_paket;
                        cekMenu++;
                    }
                } while (total_paket < 1);
                break;

            case 2:
                if (cekMenu == 0) {
                    printf("\nHarap input pesanan terlebih dahulu[!]\n");
                } else {
                    printf("\n[ Pembayaran ]\n");
                    printf("Bukti pembelian %d paket alat tulis", total_paket);
                    printf("\n\n");

                    for (i = 1; i <= 5; i++) {
                        for (j = 1; j <= total_paket; j++) {
                            printf("|* ");
                        }
                        printf("\n");
                    }

                    printf("\nTotal harga   : Rp %.0f\n", total_harga);
                }
                break;

            case 3:
                if (cekMenu == 0) {
                    printf("\nHarap input pesanan terlebih dahulu[!]\n");
                } else {
                    printf("\n[ Kupon ]\n");
                    if (total_paket >= 6) {
                        printf("\nSelamat anda mendapatkan kupon diskon[!]\n");
                        printf("\n");
                        for (i = 1; i <= 6; i++) {
                            for (j = 1; j <= total_paket; j++) {
                                if (i == 1 || j == 1 || i == 6 || j == total_paket)
                                    printf("*");
                                else
                                    printf(" ");
                            }
                            printf("\n");
                        }
                        total_diskon = total_harga - (total_harga * 0.1);
                        printf("\nTotal diskon (10%): Rp %.0f", total_diskon);
                        printf("\nTotal harga       : Rp %.0f", total_harga);
                        printf("\n");
                    } else {
                        printf("\nMaaf, anda tidak mendapatkan diskon[!]\n");
                    }
                }
                break;

            case 4:
                if (cekMenu == 0) {
                    printf("\nHarap input pesanan terlebih dahulu[!]\n");
                } else {
                    printf("\n[ Tugas ]\n");
                    if (total_paket >= 2 && total_paket % 2 != 0) {
                        printf("\n");
                        for (i = 1; i <= total_paket; i++) {
                            for (j = 1; j <= i; j++) {
                                if (j % 2 == 0)
                                    printf("* ");
                                else
                                    printf("%d ", i);
                            }
                            printf("\n");
                        }
                        printf("\nSelamat anda mendapatkan penggaris Segitiga Unik[!]\n");
                    } else {
                        printf("\nMaaf, anda tidak mendapatkan penggaris Segitiga Unik[!]\n");
                    }
                }
                break;

            case 0:
                printf("\n[Berhasil keluar | Benidiktus Violaz Morello Anjolie | 210711385 | D]\n");
                break;

            default:
                printf("\nMenu tidak tersedia[!]\n");
                break;
        }
        if (PLATFORM_NAME == "linux") {
            initscr();
            getch();
            endwin();
        }

        if (PLATFORM_NAME == "windows")
            getch();
    } while (menu != 0);

    return 0;
}