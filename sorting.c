#include <string.h>
#include "struktur.h"

// 1. Berdasarkan frekuensi (descending)
void sort_frekuensi(struct Kata d[], int n) {

    for (int i = 0; i < n; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            if (d[j].jumlah > d[max].jumlah)
                max = j;
        }
        struct Kata temp = d[i];
        d[i] = d[max];
        d[max] = temp;
    }
}

// 2. Berdasarkan panjang kata (descending)
void sort_panjang(struct Kata d[], int n) {

    for (int i = 0; i < n; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            if (d[j].panjang > d[max].panjang)
                max = j;
        }
        struct Kata t = d[i];
        d[i] = d[max];
        d[max] = t;
    }
}

// 3. Berdasarkan alfabet (ascending)
void sort_alfabet(struct Kata d[], int n) {

    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(d[j].teks, d[min].teks) < 0)
                min = j;
        }
        struct Kata t = d[i];
        d[i] = d[min];
        d[min] = t;
    }
}

