#include "menu.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void startProgram(){
    int pilihan;
    bool runing = true;

    while (runing){
        printf("Selamat datang di Game UNO! \n");
        printf("1. Mulai Game \n");
        printf("2. Info \n");
        printf("3. Keluar \n");
        printf("Masukkan Pilihan Anda: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
                menuPlay();
                break;
            case 2:
                // menuInfo();
                break;
            case 3: 
                runing = false;
                printf("Terima kasih telah bermain! \n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi. \n");
                break;
        }
    }
}

void menuPlay(){
    int sub;
    bool stay = true;
    int jumlahPemain;
    bool pemainSudahDiinput = false;
    while (stay){
        printf("\n=== Menu Play ===\n");
        printf("1. Masukkan jumlah pemain \n");
        printf("2. Masukan Nama Pemain \n");
        printf("3. Tampilkan semua Pemain \n");
        printf("4. mulai permainan \n");
        printf("5. Kembali ke Menu Utama ");
        printf("\nMasukkan pilihan Anda: ");
        scanf("%d", &sub);
        getchar();

        switch (sub) {
            case 1:
                printf("Masukkan jumlah pemain: \n");
                scanf("%d", &jumlahPemain);
                break;
            case 2:
                printf("Masukkan nama pemain: \n");
                Queue q;
                CreateQueue(&q);
                InitGiliran(&q, jumlahPemain);
                pemainSudahDiinput = true;
                break;
            case 3:
                printf("menampilkan daftar pemain: \n");
                TampilkanDaftarPemain(q);
                break;
            case 4:
                printf("Memulai permainan... \n");
                break;
            case 5:
                stay = false;
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi. \n");
                break;
        }
    }

}