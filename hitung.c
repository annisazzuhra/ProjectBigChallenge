#include <string.h>
#include "struktur.h"

int hitung_kata(struct Kata daftar[], int n) {

    for (int i = 0; i < n; i++) {
        if (daftar[i].jumlah == 0)
            continue;

        for (int j = i + 1; j < n; j++) {

            // jika katanya sama
            if (strcmp(daftar[i].teks, daftar[j].teks) == 0) {

                daftar[i].jumlah++;   // tambahkan frekuensi
                daftar[j].jumlah = 0; // tandai sudah digabung
            }
        }
    }

    return 0;
}

