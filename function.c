#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struktur.h"

/* ============================================
   DEKLARASI GLOBAL
   ============================================ */
struct Kata daftar[2000000];
int jumlahKata = 0;

/* ============================================
   1. MEMBERSIHKAN TEKS
   ============================================ */
void bersihkanTeks(char *input, char *output)
{
    FILE *fp = fopen(input, "r");
    FILE *fw = fopen(output, "w");

    if (!fp || !fw) {
        printf("Gagal membuka file input/output.\n");
        return;
    }

    int c;
    int dalamURL = 0;

    while ((c = fgetc(fp)) != EOF)
    {
        if (c == '<') {
            char tag[10] = {0};
            tag[0] = c;

            for (int i = 1; i < 9; i++) {
                tag[i] = fgetc(fp);
                if (tag[i] == '>') break;
            }

            if (strncmp(tag, "<url", 4) == 0)
                dalamURL = 1;

            if (strncmp(tag, "</url>", 6) == 0)
                dalamURL = 0;

            continue;
        }

        if (dalamURL) continue;

        if (c >= 'A' && c <= 'Z')
            c = c + 32;

        if (c >= 'a' && c <= 'z')
            fputc(c, fw);
        else
            fputc(' ', fw);
    }

    fclose(fp);
    fclose(fw);
}

/* ============================================
   2. TOKENISASI KATA
   ============================================ */
void tokenisasiKata(char *namaFile)
{
    FILE *fp = fopen(namaFile, "r");
    if (!fp) {
        printf("Gagal membuka file %s\n", namaFile);
        return;
    }

    char baris[5000];
    char *token;

    while (fgets(baris, sizeof(baris), fp) != NULL)
    {
        token = strtok(baris, " \n\t");

        while (token != NULL)
        {
            strcpy(daftar[jumlahKata].teks, token);
            daftar[jumlahKata].panjang = strlen(token);
            daftar[jumlahKata].freq = 1;
            jumlahKata++;

            token = strtok(NULL, " \n\t");
        }
    }

    fclose(fp);
}

/* ============================================
   3. HITUNG FREKUENSI
   ============================================ */
void hitungFrekuensi()
{
    for (int i = 0; i < jumlahKata; i++)
    {
        if (daftar[i].freq == 0)
            continue;

        for (int j = i + 1; j < jumlahKata; j++)
        {
            if (daftar[j].freq == 0)
                continue;

            if (strcmp(daftar[i].teks, daftar[j].teks) == 0)
            {
                daftar[i].freq++;
                daftar[j].freq = 0;
            }
        }
    }
}

/* ============================================
   4. SORTIR
   ============================================ */
void swap(struct Kata *a, struct Kata *b)
{
    struct Kata t = *a;
    *a = *b;
    *b = t;
}

// Sort berdasarkan frekuensi
void sortirFrekuensi()
{
    for (int i = 0; i < jumlahKata - 1; i++) {
        int max = i;
        for (int j = i + 1; j < jumlahKata; j++) {
            if (daftar[j].freq > daftar[max].freq)
                max = j;
        }
        swap(&daftar[i], &daftar[max]);
    }
}

// Sort berdasarkan panjang (freq sama)
void sortirPanjang()
{
    for (int i = 0; i < jumlahKata - 1; i++) {
        int max = i;
        for (int j = i + 1; j < jumlahKata; j++) {
            if (daftar[i].freq == daftar[j].freq) {
                if (daftar[j].panjang > daftar[max].panjang)
                    max = j;
            }
        }
        swap(&daftar[i], &daftar[max]);
    }
}

// Sort alfabet (freq & panjang sama)
void sortirAlfabet()
{
    for (int i = 0; i < jumlahKata - 1; i++) {
        int max = i;
        for (int j = i + 1; j < jumlahKata; j++) {
            if (daftar[i].freq == daftar[j].freq &&
                daftar[i].panjang == daftar[j].panjang)
            {
                if (strcmp(daftar[j].teks, daftar[max].teks) > 0)
                    max = j;
            }
        }
        swap(&daftar[i], &daftar[max]);
    }
}

/* ============================================
   5. SIMPAN KE FILE BINARI
   ============================================ */
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

/* ============================================
   6. BACA FILE BINARI (TOP N)
   ============================================ */
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
