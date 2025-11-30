#include <string.h>
#include "struktur.h"

extern struct Kata daftar[2000000];
extern int jumlahKata;

void swap(struct Kata *a, struct Kata *b)
{
    struct Kata t = *a;
    *a = *b;
    *b = t;
}

// 1. Sort Frekuensi
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

// 2. Sort Panjang (jika freq sama)
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

// 3. Sort Alfabet (jika freq & panjang sama)
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
