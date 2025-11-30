#include <string.h>
#include "struktur.h"

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
