#include <stdio.h>
#include <string.h>
#include "struktur.h"

int tokenisasi(const char *nama_file, struct Kata daftar[]) {

    FILE *fp = fopen(nama_file, "r");
    if (fp == NULL) {
        printf("Gagal membuka file tokenisasi.\n");
        return 0;
    }

    char kata[200];
    int jumlah_kata = 0;

    while (fscanf(fp, "%199s", kata) == 1) {

        // masukkan kata ke struct
        strcpy(daftar[jumlah_kata].teks, kata);
        daftar[jumlah_kata].jumlah  = 1;
        daftar[jumlah_kata].panjang = strlen(kata);

        jumlah_kata++;
    }

    fclose(fp);
    return jumlah_kata;
}

