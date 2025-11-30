#include <stdio.h>
#include "struktur.h"

struct Kata daftar[2000000]; // maksimal 2 juta kata (contoh)

int main() {

    char input[]  = "input.txt";
    char bersih[] = "bersih.txt";

    // 1. Bersihkan file
    bersihkan_file(input, bersih);

    // 2. Tokenisasi
    int total = tokenisasi(bersih, daftar);

    // 3. Hitung frekuensi
    hitung_kata(daftar, total);

    // 4. Sorting (sesuai PDF → 3 output)
    sort_frekuensi(daftar, total);

    printf("=== URUT FREKUENSI ===\n");
    for (int i = 0; i < total; i++) {
        if (daftar[i].jumlah > 0)
            printf("%s  %d\n", daftar[i].teks, daftar[i].jumlah);
    }

    sort_panjang(daftar, total);

    printf("\n=== URUT PANJANG ===\n");
    for (int i = 0; i < total; i++) {
        if (daftar[i].jumlah > 0)
            printf("%s  (%d)\n", daftar[i].teks, daftar[i].panjang);
    }

    sort_alfabet(daftar, total);

    printf("\n=== URUT ALFABET ===\n");
    for (int i = 0; i < total; i++) {
        if (daftar[i].jumlah > 0)
            printf("%s\n", daftar[i].teks);
    }

    return 0;
}

