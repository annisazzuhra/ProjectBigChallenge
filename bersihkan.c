#include <stdio.h>

void bersihkan_file(const char *input, const char *output) {
    FILE *fp = fopen(input, "r");
    FILE *fw = fopen(output, "w");

    if (fp == NULL || fw == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    int c;
    while ((c = fgetc(fp)) != EOF) {

        // karakter yang boleh hanyalah huruf besar dan kecil + spasi
        if ((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == ' ' || c == '\n') {

            fputc(c, fw);

        } else {
            fputc(' ', fw);   // karakter lain diganti spasi
        }
    }

    fclose(fp);
    fclose(fw);
}

