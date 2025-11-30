#ifndef STRUKTUR_H
#define STRUKTUR_H

struct Kata {
    char teks[100];
    int panjang;
    int freq;
};

extern struct Kata daftar[2000000];
extern int jumlahKata;

// bersihkan
void bersihkanTeks(char *input, char *output);

// tokenisasi
void tokenisasiKata(char *namaFile);

// hitung
void hitungFrekuensi();

// sorting
void sortirFrekuensi();
void sortirPanjang();
void sortirAlfabet();

// binary
void simpanBinari(char *namaFile);
void bacaBinari(char *namaFile, int n);

#endif
