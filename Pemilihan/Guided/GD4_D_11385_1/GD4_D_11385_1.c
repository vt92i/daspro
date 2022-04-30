#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <conio.h>

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

typedef char string[40];

int main() {
    string nama, hobi, kode;
    int umur;

    printf("---=== GD PEMILIHAN IF-ELSE ===--- \n");

    printf("Nama : ");
    fflush(stdin);
    gets(nama);

    printf("Hobi : ");
    fflush(stdin);
    gets(hobi);

    printf("Umur : ");
    scanf("%d", &umur);

    if (strlen(nama) > 0 && strlen(hobi) > 0 && umur > 0) {
        printf("\n\tNama : %s", nama);
        printf("\n\tHobi : %s", hobi);
        printf("\n\tUmur : %d", umur);

        printf("\n\tKode [A23 | B45]: ");
        scanf("%s", &kode);
        // fflush(stdin);
        // gets(kode);

        if (strcmp(kode, "A23") == 0) {
            printf("\n\tSelamat kamu menjadi Gold Member... \n");
        } else if (strcmp(kode, "B45") == 0) {
            printf("\n\tSelamat kamu menjadi Silver Member... \n");
        } else {
            printf("\n\tKode salah [!] \n");
        }
    } else {
        printf("\nSemua data tidak boleh kosong[!] \n");
    }

    return 0;
}