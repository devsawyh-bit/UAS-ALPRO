#include <stdio.h>

#define MAX 30

int nim[MAX];
float nilai[MAX][3];
int jumlah = 0;


long long faktorial(int n) {
    if (n <= 1)
        return 1;
    return n * faktorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}


void inputData() {
    int i;
    printf("Masukkan jumlah mahasiswa (maks 30): ");
    scanf("%d", &jumlah);

    if (jumlah > MAX) {
        jumlah = MAX;
        printf("Jumlah melebihi batas, diset menjadi 30\n");
    }

    for (i = 0; i < jumlah; i++) {
        printf("\nMahasiswa ke-%d\n", i + 1);

        do {
            printf("NIM : ");
            scanf("%d", &nim[i]);
            if (nim[i] < 10000 || nim[i] > 99999)
                printf("NIM harus 5 digit!\n");
        } while (nim[i] < 10000 || nim[i] > 99999);

        printf("Nilai Tugas  : ");
        scanf("%f", &nilai[i][0]);
        printf("Nilai UTS    : ");
        scanf("%f", &nilai[i][1]);
        printf("Nilai UAS    : ");
        scanf("%f", &nilai[i][2]);
    }
}

void tampilData() {
    int i;
    printf("\n====================================================\n");
    printf("NIM\tTugas\tUTS\tUAS\tRata-rata\n");
    printf("====================================================\n");

    for (i = 0; i < jumlah; i++) {
        float rata = (nilai[i][0] + nilai[i][1] + nilai[i][2]) / 3;
        printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\n",
               nim[i], nilai[i][0], nilai[i][1], nilai[i][2], rata);
    }
}

void tambahData() {
    if (jumlah >= MAX) {
        printf("Data sudah penuh!\n");
        return;
    }

    do {
        printf("Masukkan NIM (5 digit): ");
        scanf("%d", &nim[jumlah]);
        if (nim[jumlah] < 10000 || nim[jumlah] > 99999)
            printf("NIM harus 5 digit!\n");
    } while (nim[jumlah] < 10000 || nim[jumlah] > 99999);

    printf("Nilai Tugas        : ");
    scanf("%f", &nilai[jumlah][0]);
    printf("Nilai UTS          : ");
    scanf("%f", &nilai[jumlah][1]);
    printf("Nilai UAS          : ");
    scanf("%f", &nilai[jumlah][2]);

    jumlah++;
    printf("Data berhasil ditambahkan.\n");
}

void ubahData() {
    int cari, i, found = 0;
    printf("Masukkan NIM yang akan diubah: ");
    scanf("%d", &cari);

    for (i = 0; i < jumlah; i++) {
        if (nim[i] == cari) {
            printf("Nilai Tugas baru: ");
            scanf("%f", &nilai[i][0]);
            printf("Nilai UTS baru  : ");
            scanf("%f", &nilai[i][1]);
            printf("Nilai UAS baru  : ");
            scanf("%f", &nilai[i][2]);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Data tidak ditemukan.\n");
}

void hapusData() {
    int cari, i, j, found = 0;
    printf("Masukkan NIM yang akan dihapus: ");
    scanf("%d", &cari);

    for (i = 0; i < jumlah; i++) {
        if (nim[i] == cari) {
            for (j = i; j < jumlah - 1; j++) {
                nim[j] = nim[j + 1];
                nilai[j][0] = nilai[j + 1][0];
                nilai[j][1] = nilai[j + 1][1];
                nilai[j][2] = nilai[j + 1][2];
            }
            jumlah--;
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Data tidak ditemukan.\n");
    else
        printf("Data berhasil dihapus.\n");
}

void olahNilai() {
    int i;
    float rataTugas = 0, rataUTS = 0, rataUAS = 0;
    float max = -1, min = 101;
    int idxMax = 0, idxMin = 0;

    for (i = 0; i < jumlah; i++) {
        float rata = (nilai[i][0] + nilai[i][1] + nilai[i][2]) / 3;

        if (rata > max) {
            max = rata;
            idxMax = i;
        }
        if (rata < min) {
            min = rata;
            idxMin = i;
        }

        rataTugas += nilai[i][0];
        rataUTS += nilai[i][1];
        rataUAS += nilai[i][2];
    }

    printf("\nRata-rata Tugas: %.2f\n", rataTugas / jumlah);
    printf("Rata-rata UTS  : %.2f\n", rataUTS / jumlah);
    printf("Rata-rata UAS  : %.2f\n", rataUAS / jumlah);

    printf("\nNilai Tertinggi: NIM %d (%.2f)\n", nim[idxMax], max);
    printf("Nilai Terendah : NIM %d (%.2f)\n", nim[idxMin], min);
}

void menuRekursif() {
    int i;
    printf("\nFaktorial dari %d = %lld\n", jumlah, faktorial(jumlah));

    printf("Fibonacci sebanyak %d: ", jumlah);
    for (i = 0; i < jumlah; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}


int main() {
    int pilihan;

    inputData();

    do {
        printf("\n========== MENU ==========\n");
        printf("1. Tampilkan Data\n");
        printf("2. Tambah Data\n");
        printf("3. Ubah Data\n");
        printf("4. Hapus Data\n");
        printf("5. Olah Nilai\n");
        printf("6. Fitur Rekursif\n");
        printf("7. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: tampilData(); break;
            case 2: tambahData(); break;
            case 3: ubahData(); break;
            case 4: hapusData(); break;
            case 5: olahNilai(); break;
            case 6: menuRekursif(); break;
            case 7: printf("Program selesai.\n"); break;
            default: printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 7);

    return 0;
}
