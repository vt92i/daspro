#include <stdio.h>
#include <stdlib.h>

#define phi 3.14
int main() {
    float volume;
    int tinggi, jari_jari;
    jari_jari = 4;

    printf("Masukkan tinggi : ");
    scanf("%d", &tinggi);

    volume = phi * (jari_jari * jari_jari) * tinggi;
    printf("\nVolume Tabung : %f cm3 \n", volume);

    return 0;
}
