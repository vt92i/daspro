// Nama     : Benidiktus Violaz Morello Anjolie
// NPM      : 210711385
// Kelas    : D

#include <stdio.h>
#include <stdlib.h>

typedef char string[40];

int main(int argc, char const *argv[]) {
    printf("###=== Welcome to Wakanda's AKI ===### \n");
    printf("Please input your data. \n\n");

    string kereta_1, kereta_2, kereta_3;
    string jenis_1, jenis_2, jenis_3;

    float harga_1, harga_2, harga_3;
    float max_kecepatan_1, max_kecepatan_2, max_kecepatan_3;

    float pajak_kereta = 0.05;
    float pajak_pekerja = 0.06;
    float total_pajak = pajak_kereta + pajak_pekerja;

    // Kereta Api 1
    int model_1 = 12000;
    char type_1[] = "A";

    printf("== Kereta Api 1 == \n");
    printf("Nama                : ");
    scanf("%s", &kereta_1);

    printf("Model               : %d \n", model_1);
    printf("Tipe                : %s \n", type_1);

    printf("Jenis               : ");
    scanf("%s", &jenis_1);

    printf("Harga               : ");
    scanf("%f", &harga_1);

    printf("Kecepatan maksimum  : ");
    scanf("%f", &max_kecepatan_1);

    float total_harga_1 = harga_1 + (harga_1 * total_pajak);
    printf("[ Harga total  : Rp %.2f ] \n", total_harga_1);

    // Kereta Api 2
    int model_2 = model_1 + 1;
    char type_2[] = "B";

    printf("\n== Kereta Api 2 == \n");
    printf("Nama                : ");
    scanf("%s", &kereta_2);

    printf("Model               : %d \n", model_2);
    printf("Tipe                : %s \n", type_2);

    printf("Jenis               : ");
    scanf("%s", &jenis_2);

    printf("Harga               : ");
    scanf("%f", &harga_2);

    printf("Kecepatan maksimum  : ");
    scanf("%f", &max_kecepatan_2);

    float total_harga_2 = harga_2 + (harga_2 * total_pajak);
    printf("[ Harga total  : Rp %.2f ] \n", total_harga_2);

    // Kereta Api 3
    int model_3 = model_2 + 1;
    char type_3[] = "C";

    printf("\n== Kereta Api 3 == \n");
    printf("Nama                : ");
    scanf("%s", &kereta_3);

    printf("Model               : %d \n", model_3);
    printf("Tipe                : %s \n", type_3);

    printf("Jenis               : ");
    scanf("%s", &jenis_3);

    printf("Harga               : ");
    scanf("%f", &harga_3);

    printf("Kecepatan maksimum  : ");
    scanf("%f", &max_kecepatan_3);

    float total_harga_3 = harga_3 + (harga_3 * total_pajak);
    printf("[ Harga total  : Rp %.2f ] \n", total_harga_3);

    // Tampil Data
    float total_harga_kereta = total_harga_1 + total_harga_2 + total_harga_3;
    float rata_kecepatan = (max_kecepatan_1 + max_kecepatan_2 + max_kecepatan_3) / 3;

    printf("\n== Tampil Data == \n");
    printf("Jumlah kereta       : 3 \n");
    printf("Total harga kereta  : Rp %.2f \n", total_harga_kereta);
    printf("Rata-rata kecepatan : %.2f KM/J \n", rata_kecepatan);

    // Perkiraan Untung Atau Tidak

    float harga_tiket, jarak;

    printf("\n== Perkiraan Untung atau Tidak == \n");

    printf("Harga tiket         : ");
    scanf("%f", &harga_tiket);

    printf("Jarak               : ");
    scanf("%f", &jarak);

    float keuntungan = harga_tiket * 100;
    float biaya_operasional = (jarak / 1000) * 1000000;
    int apakah_untung = keuntungan > biaya_operasional;

    printf("Keuntungan          : Rp %.2f \n", keuntungan);
    printf("Biaya operasional   : Rp %.2f \n", biaya_operasional);
    printf("Apakah untung ?     : %d \n", apakah_untung);

    return 0;
}
