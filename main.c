#include <stdio.h>
#include "struktur.h"

struct Kata daftar[2000000];
int jumlahKata = 0;

int main()
{
    char input[100];
    char outputBersih[] = "bersih.txt";
    char fileBin[] = "output.bin";

    int sudahSimpan = 0;   // <--- penanda penting sesuai perintah tugas

    printf("Masukkan nama file input (txt): ");
    scanf("%s", input);

    // proses awal
    bersihkanTeks(input, outputBersih);
    tokenisasiKata(outputBersih);
    hitungFrekuensi();
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
            sudahSimpan = 1;

            printf("\nFile binari berhasil disimpan.\n");
            printf("Tekan ENTER untuk kembali ke menu...");
        getchar(); getchar();   // <-- pause biar tidak langsung ke menu
        }

        else if (pilihan == 2)
        {
            int n;
            printf("Masukkan n (1-25): ");
            scanf("%d", &n);

            // <=== BAGIAN PALING PENTING (PERBAIKAN)
            if (!sudahSimpan)
            {
                printf("File binari belum dibuat. Menyimpan terlebih dahulu...\n");
                simpanBinari(fileBin);
                sudahSimpan = 1;
            }

            bacaBinari(fileBin, n);
        }
        else if (pilihan == 3)
        {
            break;
        }
        else
        {
            printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}
