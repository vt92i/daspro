#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

#define N 50
#define STRING_LENGTH 64

typedef char string[STRING_LENGTH];

typedef struct {
    string model;
    string warna;
    int ukuran;
    int jumlah;
} Sepatu;

typedef Sepatu DaftarSepatu[N];

int generateRandomNumber();
Sepatu stockTerkecil(DaftarSepatu daftar_sepatu);

int main(int argc, char const *argv[]) {
    int i, j;
    DaftarSepatu daftar_sepatu;

    for (i = 0; i < N; i++) {
        strcpy(daftar_sepatu[i].model, "Sepatu");
        strcpy(daftar_sepatu[i].warna, "Hitam");
        daftar_sepatu[i].ukuran = generateRandomNumber();
        daftar_sepatu[i].jumlah = generateRandomNumber() * 2;
    }

    for (i = 0; i < N; i++) {
        printf("%d. %s %s %d %d\n", i + 1, daftar_sepatu[i].model, daftar_sepatu[i].warna, daftar_sepatu[i].ukuran, daftar_sepatu[i].jumlah);
    }

    Sepatu sepatu_stock_terkecil = stockTerkecil(daftar_sepatu);

    printf("\nSepatu Stock Terkecil : %s %s %d %d\n", sepatu_stock_terkecil.model, sepatu_stock_terkecil.warna, sepatu_stock_terkecil.ukuran, sepatu_stock_terkecil.jumlah);

    return 0;
}

int generateRandomNumber() {
    // Generate random number between 1 and 100
    return rand() % (100 - 1 + 1) + 1;
}

Sepatu stockTerkecil(DaftarSepatu daftar_sepatu) {
    int i, j;
    Sepatu sepatu_stock_terkecil;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N - 1; j++) {
            if (daftar_sepatu[j].jumlah < daftar_sepatu[j + 1].jumlah) {
                sepatu_stock_terkecil = daftar_sepatu[j];
            }
        }
    }

    return sepatu_stock_terkecil;
}
