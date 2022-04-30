#include <stdio.h>
#include <stdlib.h>

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

typedef char string[64];

int main(int argc, char const *argv[]) {
    int current_population = 9870;
    int target_population = 9870;
    int count_years = 0;

    printf("Total populasi sekarang : %d manusia\n\n", current_population);

    while (target_population < 30000) {
        target_population += target_population * 0.1;
        count_years += 1;

        printf("Jumlah populasi tahun ke %d : %d manusia\n", count_years, target_population);
    }

    printf("\nDibutuhkan %d tahun untuk mencapai populasi lebih dari 30,000 manusia\n", count_years);

    return 0;
}