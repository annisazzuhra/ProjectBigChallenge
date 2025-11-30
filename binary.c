#include <stdio.h>
#include <string.h>
#include "struktur.h"

extern struct Kata daftar[2000000];
extern int jumlahKata;

void simpanBinari(char *namaFile)
{
    FILE *fb = fopen(namaFile, "wb");
    if (!fb) {
        printf("Gagal membuka file binari\n");
        return;
    }

    for (char abjad = 'a'; abjad <= 'z'; abjad++)
    {
        int jumlahAbjad = 0;

        for (int i = 0; i < jumlahKata; i++) {
            if (daftar[i].freq > 0 && daftar[i].teks[0] == abjad)
                jumlahAbjad++;
        }

        fwrite(&abjad, sizeof(char), 1, fb);
        fwrite(&jumlahAbjad, sizeof(int), 1, fb);

        for (int i = 0; i < jumlahKata; i++) {
            if (daftar[i].freq > 0 && daftar[i].teks[0] == abjad)
            {
                int p = daftar[i].panjang;
                fwrite(&p, sizeof(int), 1, fb);
                fwrite(daftar[i].teks, sizeof(char), p, fb);
                fwrite(&daftar[i].freq, sizeof(int), 1, fb);
            }
        }
    }

    fclose(fb);
}

void bacaBinari(char *namaFile, int n)
{
    FILE *fb = fopen(namaFile, "rb");
    if (!fb) {
        printf("Gagal membuka file binari\n");
        return;
    }

    char abjad;
    int jumlahAbjad;

    while (fread(&abjad, sizeof(char), 1, fb) == 1)
    {
        fread(&jumlahAbjad, sizeof(int), 1, fb);

        printf("%c : { ", abjad);

        int tampil = 0;

        for (int i = 0; i < jumlahAbjad; i++)
        {
            int panjang;
            char kata[200];
            int freq;

            fread(&panjang, sizeof(int), 1, fb);
            fread(kata, sizeof(char), panjang, fb);
            kata[panjang] = '\0';
            fread(&freq, sizeof(int), 1, fb);

            if (tampil < n) {
                printf("%s (%d)", kata, freq);
                tampil++;
                if (tampil < n) printf(", ");
            }
        }

        printf(" }\n");
    }

    fclose(fb);
}

