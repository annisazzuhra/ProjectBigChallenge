#include <stdio.h>
#include "struktur.h"

struct Kata daftar[2000000];
int jumlahKata = 0;

int main()
{
    char input[100];
    char outputBersih[] = "bersih.txt";
    char fileBin[] = "output.bin";

    printf("Masukkan nama file input (txt): ");
    scanf("%s", input);

    printf("Membersihkan file...\n");
    bersihkanTeks(input, outputBersih);

    printf("Tokenisasi...\n");
    tokenisasiKata(outputBersih);

    printf("Menghitung frekuensi...\n");
    hitungFrekuensi();

    printf("Sorting...\n");
    sortirFrekuensi();
    sortirPanjang();
    sortirAlfabet();

    int pilihan;
    while (1)
    {
        printf("\nMENU:\n");
        printf("1) Simpan ke file binari\n");
        printf("2) Tampilkan n kata\n");
        printf("3) Keluar\n");
        printf("Pilihan anda: ");
        scanf("%d", &pilihan);

        if (pilihan == 1)
        {
            simpanBinari(fileBin);
        }
        else if (pilihan == 2)
        {
            int n;
            printf("Masukkan n (1-25): ");
            scanf("%d", &n);
            bacaBinari(fileBin, n);
        }
        else if (pilihan == 3)
        {
            break;
        }
        else
        {
            printf("Pilihan tidak valid\n");
        }
    }

    return 0;
}
