#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int npmSaya = 210711385, npmTeman = 210711441;
    int inputan;
    bool boolean;

    printf("\n1 : Benar / True");
    printf("\n0 : Salah / False");

    printf("\n\nMasukkan NPM : ");
    scanf("%d", &inputan);

    boolean = npmSaya == inputan;
    printf("\n%d sama dengan %d ? %d", npmSaya, inputan, boolean);

    boolean = npmSaya != npmTeman;
    printf("\nNPM saya tidak sama dengan NPM teman ? %d", boolean);

    boolean = npmSaya > npmTeman;
    printf("\nNPM saya lebih besar dengan NPM teman ? %d", boolean);

    boolean = npmSaya < npmTeman;
    printf("\nNPM saya lebih kecil dengan NPM teman ? %d", boolean);

    printf("\n");

    return 0;
}