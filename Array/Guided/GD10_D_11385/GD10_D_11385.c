#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 5
typedef char string[64];

void tampilArray(int arr[]);
int cariData(int arr[], int cariNilai);
void editArray(int arr[], int cariNilai, int nilaiBaru);

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

int main(int argc, char const *argv[]) {
    int arrA[MAX];
    int arrB[MAX];
    int arrC[MAX];

    int i, j, k;

    printf("\n[ Array A ]\n");
    for (i = 0; i < MAX; i++) {
        printf("Masukan data Array A index-%d : ", i);
        scanf("%d", &arrA[i]);
    }

    printf("\n[ Array B ]\n");
    for (j = 0; j < MAX; j++) {
        printf("Masukan data Array B index-%d : ", j);
        scanf("%d", &arrB[j]);
    }

    printf("\n[ Isi seluruh Array A ]\n");
    tampilArray(arrA);

    printf("\n[ Isi seluruh Array B ]\n");
    tampilArray(arrB);

    printf("\n[ Cari Data Array A ]\n");
    int cari, index, nilaiBaru;

    printf("Masukan nilai yang ingin dicari pada Array A : ");
    scanf("%d", &cari);

    index = cariData(arrA, cari);

    if (index != -1)
        printf("Data '%d' terdapat pada index ke-%d Array A\n", cari, index);
    else
        printf("Data tidak ditemukan[!]\n");

    printf("\n[ Edit Data Array B ]\n");
    printf("Masukan nilai yang ingin diubah pada Array B : ");
    scanf("%d", &cari);

    printf("Masukan nilai baru : ");
    scanf("%d", &nilaiBaru);

    editArray(arrB, cari, nilaiBaru);
    printf("\n[ Updated Array B ]\n");
    tampilArray(arrB);

    return 0;
}

void tampilArray(int arr[]) {
    int i;
    for (i = 0; i < MAX; i++) {
        printf("Array index-%d : %d \n", i, arr[i]);
    }
}

int cariData(int arr[], int cariNilai) {
    int i;
    for (i = 0; i < MAX; i++) {
        if (arr[i] == cariNilai)
            return i;
    }
    return -1;
}

void editArray(int arr[], int cariNilai, int nilaiBaru) {
    int i;
    int indexDiCari = cariData(arr, cariNilai);
    if (indexDiCari != -1)
        arr[indexDiCari] = nilaiBaru;
    else
        printf("Data tidak ditemukan[!] \n");
}