#ifndef HEADER_H
#define HEADER_H

struct Kata {
    char teks[100];
    int panjang;
    int freq;
};

extern struct Kata daftar[2000000];
extern int jumlahKata;

void bersihkanTeks(char *input, char *output);
void tokenisasiKata(char *namaFile);
void hitungFrekuensi();
void sortirFrekuensi();
void sortirPanjang();
void sortirAlfabet();
void simpanBinari(char *namaFile);
void bacaBinari(char *namaFile, int n);

#endif