#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Benidiktus Violaz Morello Anjolie
// 210711385
// D

typedef char string[64];

typedef struct {
    string title;
    string authors[3];
    int total_pages;
    int year_published;
} Journal;

typedef struct {
    int no_urut;
    Journal journals[3];
    int year_registered;
} Dosen;

void printAllJournals(int no_urut, Dosen dosen[]);
int yearTakenFirstJournalWasPublishedSinceFirstRegistered(int no_urut, Dosen dosen[]);

int main(int argc, char const *argv[]) {
    Dosen dosen[3];

    dosen[0].no_urut = 1;
    dosen[0].year_registered = 2014;

    int i;
    for (i = 0; i < 3; i++) {
        string title;

        sprintf(title, "Journal of Computer Science Part %d", i + 1);
        strcpy(dosen[0].journals[i].title, title);

        strcpy(dosen[0].journals[i].authors[0], "Andi Alexander");
        strcpy(dosen[0].journals[i].authors[1], "John Doe");
        strcpy(dosen[0].journals[i].authors[2], "Jane Doe");

        dosen[0].journals[i].total_pages = 120;
        dosen[0].journals[i].year_published = 2016 + i;
    }

    printAllJournals(1, dosen);

    int tahun_jurnal_pertama = yearTakenFirstJournalWasPublishedSinceFirstRegistered(1, dosen) + dosen[0].year_registered;
    int f = yearTakenFirstJournalWasPublishedSinceFirstRegistered(1, dosen);

    if (f == -1)
        return 0;

    printf("\nTahun Registrasi      : %d", dosen[0].year_registered);
    printf("\nJurnal pertama        : %d", tahun_jurnal_pertama);

    printf("\nJurnal pertama dipublikasi setelah %d tahun semenjak awal registrasi\n", f);

    return 0;
}

void printAllJournals(int no_urut, Dosen dosen[]) {
    int i, index_dosen;

    for (i = 0; i < 3; i++) {
        if (dosen[i].no_urut == no_urut) {
            index_dosen = i;
            break;
        }
    }

    printf("\n[ Data Dosen ]\n");
    printf("No. Urut            : %d\n", dosen[index_dosen].no_urut);
    printf("Tahun Registrasi    : %d\n", dosen[index_dosen].year_registered);

    printf("\n[ Data Journal ]\n");
    for (i = 0; i < 3; i++) {
        printf("%d. %s\n", i + 1, dosen[index_dosen].journals[i].title);
        printf("\tAuthors           : %s, %s, %s\n", dosen[index_dosen].journals[i].authors[0], dosen[index_dosen].journals[i].authors[1], dosen[index_dosen].journals[i].authors[2]);
        printf("\tTotal Pages       : %d\n", dosen[index_dosen].journals[i].total_pages);
        printf("\tYear Published    : %d\n", dosen[index_dosen].journals[i].year_published);
    }
}

int yearTakenFirstJournalWasPublishedSinceFirstRegistered(int no_urut, Dosen dosen[]) {
    int i, index_dosen;
    int year_published = 0;

    for (i = 0; i < 3; i++) {
        if (dosen[i].no_urut == no_urut) {
            index_dosen = i;
            break;
        }
    }

    if (dosen[index_dosen].journals[0].year_published == 0)
        return -1;

    year_published = dosen[index_dosen].journals[0].year_published - dosen[index_dosen].year_registered;

    return year_published;
}