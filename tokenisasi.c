#include <stdio.h>
#include <string.h>
#include "struktur.h"

struct Kata daftar[2000000];
int jumlahKata = 0;

void tokenisasiKata(char *namaFile)
{
    FILE *fp = fopen(namaFile, "r");
    if (!fp) {
        printf("Gagal membuka bersih.txt\n");
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
