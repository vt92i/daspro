#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

typedef char string[30];

int main(int argc, char const *argv[]) {
    string user, nama, npm, jawab;

    int pil;
    bool menu = true;

    int cekLog = 0;
    int cekInput = 0;

    while (menu == true) {
        system("cls");

        printf("\n\t---=== GD PEMILIHAN SWITCH CASE ===---");
        printf("\n\t1. Login");
        printf("\n\t2. Input data");
        printf("\n\t3. Tampilkan data");
        printf("\n\t0. Keluar");

        printf("\n\n\tPilih menu >> ");
        scanf("%d", &pil);

        switch (pil) {
            case 1:
                if (cekLog == 0) {
                    printf("\n\t[LOGIN]");

                    printf("\n\tUser : ");
                    fflush(stdin);
                    gets(user);

                    if (strcmp(user, "Vila") == 0 || strcmp(user, "Admin") == 0) {
                        printf("\n\t\tBerhasil login... \n");
                        cekLog = 1;
                    } else {
                        printf("\n\t\tUser tidak ditemukan[!] \n");
                    }
                } else {
                    printf("\n\t\tAnda sudah login[!] \n");
                }
                break;

            case 2:
                if (cekLog == 0) {
                    printf("\n\t\tAnda harus login terlebih dahulu[!] \n");
                } else if (cekInput == 1) {
                    printf("\n\t\tAnda sudah input data[!] \n");
                } else {
                    printf("\n\t[Input Data] \n");

                    printf("\tNama    : ");
                    fflush(stdin);
                    gets(nama);

                    printf("\tNPM     : ");
                    fflush(stdin);
                    gets(npm);

                    printf("\n\t\tBerhasil input data[!] \n");
                    cekInput = 1;
                }
                break;

            case 3:
                if (cekLog == 0) {
                    printf("\n\t\tAnda harus login terlebih dahulu[!] \n");
                } else if (cekInput == 0) {
                    printf("\n\t\tAnda belum input data[!] \n");
                } else {
                    printf("\n\t[Tampil Data]");
                    printf("\n\tNama    : %s", nama);
                    printf("\n\tNPM     : %s", npm);

                    printf("\n\tIngin hapus data ini? [y/N] : ");
                    fflush(stdin);
                    gets(jawab);

                    if (strcmpi(jawab, "y") == 0) {
                        cekInput = 0;
                        printf("\n\t\tData berhasil dihapus[!] \n");
                    }
                }
                break;

            case 0:
                printf("\n\t\tKeluar dari program... \n");
                menu = false;
                break;

            default:
                printf("\n\t\tMenu tidak ada[!] \n");
                break;
        }
        getch();
    }

    return 0;
}