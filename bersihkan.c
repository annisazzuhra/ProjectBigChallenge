#include <stdio.h>
#include "struktur.h"

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
        // cek tag <url>
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

        // huruf besar → kecil
        if (c >= 'A' && c <= 'Z')
            c = c + 32;

        // huruf kecil
        if (c >= 'a' && c <= 'z')
            fputc(c, fw);
        else
            fputc(' ', fw);
    }

    fclose(fp);
    fclose(fw);
}
