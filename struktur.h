struct Kata {
    char teks[100];
    int jumlah;
    int panjang;
};

void bersihkan_file(const char*, const char*);
int  tokenisasi(const char*, struct Kata[]);
int  hitung_kata(struct Kata[], int);

void sort_frekuensi(struct Kata[], int);
void sort_panjang(struct Kata[], int);
void sort_alfabet(struct Kata[], int);
