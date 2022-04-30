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
#include <time.h>

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

typedef char string[64];

int main(int argc, char const *argv[]) {
    int menu;

    string username, password;
    int cekLog = 0;

    int cekInputBarang = 0;
    int barang1_stok, barang2_stok, barang3_stok;
    int barang1_harga = 0, barang2_harga = 0, barang3_harga = 0;

    int pilihan;
    int uang;

    srand(time(NULL));

    do {
        if (PLATFORM_NAME == "linux")
            system("clear");

        if (PLATFORM_NAME == "windows")
            system("cls");

        printf("\n---= TOKO MASZEH =---");

        printf("\n1. Login");
        printf("\n2. Input stok");
        printf("\n3. Tampil barang");
        printf("\n4. Pelelangan");
        printf("\n5. Pelelangan Auto (Tugas)");
        printf("\n0. Exit");

        printf("\n\nMenu >> ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                if (cekLog == 0) {
                    printf("\n[ LOGIN ]\n");

                    while (true) {
                        printf("Username    : ");
                        scanf("%s", &username);
                        if (!strcmp(username, "tebri") == 0) {
                            printf("[Error] Username salah[!]\n\n");
                        } else {
                            break;
                        }
                    }

                    while (true) {
                        printf("Password    : ");
                        scanf("%s", &password);
                        if (!strcmp(password, "1385") == 0) {
                            printf("[Error] Password salah[!]\n\n");
                        } else {
                            printf("\nLogin berhasil[!]\n");
                            cekLog = 1;
                            break;
                        }
                    }

                } else {
                    printf("\nAnda sudah login[!]\n");
                }
                break;

            case 2:
                if (cekLog == 0) {
                    printf("\nAnda belum login[!]\n");
                } else {
                    printf("\n[ INPUT STOK ]");

                    printf("\nMasukkan jumlah stok yang ingin Anda masukkan untuk barang Barang1");
                    printf("\nJumlah stok : ");
                    scanf("%d", &barang1_stok);

                    printf("\nMasukkan jumlah stok yang ingin Anda masukkan untuk barang Barang2");
                    printf("\nJumlah stok : ");
                    scanf("%d", &barang2_stok);

                    printf("\nMasukkan jumlah stok yang ingin Anda masukkan untuk barang Barang3");
                    printf("\nJumlah stok : ");
                    scanf("%d", &barang3_stok);

                    cekInputBarang = 1;
                }

                break;

            case 3:
                if (cekLog == 0) {
                    printf("\nAnda belum login[!]\n");
                } else if (cekInputBarang == 0) {
                    printf("\nAnda belum input stok[!]\n");
                } else {
                    printf("\n[ STOK BARANG ]");

                    printf("\nNama barang   : Barang1");
                    printf("\nStok barang   : %d\n", barang1_stok);

                    printf("\nNama barang   : Barang2");
                    printf("\nStok barang   : %d\n", barang2_stok);

                    printf("\nNama barang   : Barang3");
                    printf("\nStok barang   : %d\n", barang3_stok);
                }
                break;

            case 4:
                if (cekLog == 0) {
                    printf("\nAnda belum login[!]\n");
                } else if (cekInputBarang == 0) {
                    printf("\nAnda belum input stok[!]\n");
                } else {
                    barang1_harga = 0;
                    barang2_harga = 0;
                    barang3_harga = 0;
                    for (int j = 5; j >= 1; j--) {
                        printf("\n[ PELELANGAN ]");
                        printf("\nKesempatan Lelang : %d\n", j);

                        printf("\n1. Barang1   : %d", barang1_harga);

                        printf("\n2. Barang2   : %d", barang2_harga);

                        printf("\n3. Barang3   : %d", barang3_harga);
                        printf("\n");

                        printf("Pilih Barang yang ingin anda bid (1-3) >> ");
                        scanf("%d", &pilihan);

                        switch (pilihan) {
                            case 1:
                                printf("\nJumlah uang yang anda pasang : ");
                                scanf("%d", &uang);
                                barang1_harga += uang;
                                break;

                            case 2:
                                printf("\nJumlah uang yang anda pasang : ");
                                scanf("%d", &uang);
                                barang2_harga += uang;
                                break;

                            case 3:
                                printf("\nJumlah uang yang anda pasang : ");
                                scanf("%d", &uang);
                                barang3_harga += uang;
                                break;
                            default:
                                printf("\nBarang tidak tersedia[!]\n");
                                j++;
                                break;
                        }
                        if (j == 1) {
                            if (barang1_harga > barang2_harga && barang1_harga > barang3_harga) {
                                printf("\nSelamat barang 1 memenangkan lelang[!]\n");
                            } else if (barang2_harga > barang1_harga && barang2_harga > barang3_harga) {
                                printf("\nSelamat barang 2 memenangkan lelang[!]\n");
                            } else {
                                printf("\nSelamat barang 3 memenangkan lelang[!]\n");
                            }
                        }
                    }
                }
                break;

            case 5:
                if (cekLog == 0) {
                    printf("\nAnda belum login[!]\n");
                } else if (cekInputBarang == 0) {
                    printf("\nAnda belum input stok[!]\n");
                } else {
                    barang1_harga = 0;
                    barang2_harga = 0;
                    barang3_harga = 0;
                    for (int j = 5; j >= 1; j--) {
                        printf("\n[ PELELANGAN ]");
                        printf("\nKesempatan Lelang : %d\n", j);

                        printf("\n1. Barang1   : %d", barang1_harga);

                        printf("\n2. Barang2   : %d", barang2_harga);

                        printf("\n3. Barang3   : %d", barang3_harga);
                        printf("\n");

                        printf("Pilih Barang yang ingin anda bid (1-3) >> ");
                        scanf("%d", &pilihan);

                        switch (pilihan) {
                            case 1:
                                printf("\nJumlah uang yang anda pasang : ");
                                scanf("%d", &uang);
                                barang1_harga += uang;
                                barang2_harga += (rand() % (1024 + 256 + 512 * 24)) + 8;
                                barang3_harga += (rand() % (1024 + 256 + 512 * 24)) + 8;
                                break;

                            case 2:
                                printf("\nJumlah uang yang anda pasang : ");
                                scanf("%d", &uang);
                                barang2_harga += uang;
                                barang1_harga += (rand() % (1024 + 256 + 512 * 24)) + 8;
                                barang3_harga += (rand() % (1024 + 256 + 512 * 24)) + 8;
                                break;

                            case 3:
                                printf("\nJumlah uang yang anda pasang : ");
                                scanf("%d", &uang);
                                barang3_harga += uang;
                                barang2_harga += (rand() % (1024 + 256 + 512 * 24)) + 8;
                                barang1_harga += (rand() % (1024 + 256 + 512 * 24)) + 8;
                                break;

                            default:
                                printf("\nBarang tidak tersedia[!]\n");
                                j++;
                                break;
                        }
                        if (j == 1) {
                            if (barang1_harga > barang2_harga && barang1_harga > barang3_harga) {
                                printf("\nSelamat barang 1 memenangkan lelang[!]\n");
                            } else if (barang2_harga > barang1_harga && barang2_harga > barang3_harga) {
                                printf("\nSelamat barang 2 memenangkan lelang[!]\n");
                            } else {
                                printf("\nSelamat barang 3 memenangkan lelang[!]\n");
                            }
                        }
                    }
                }
                break;

            case 0:
                printf("\n[Benidiktus Violaz Morello Anjolie | 210711385 | D]\n");
                menu = false;
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