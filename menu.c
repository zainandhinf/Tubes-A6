#include "menu.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

Queue q;
bool pemainSudahDiinput = false;

void startProgram(){
    int pilihan;
    bool runing = true;

    CreateQueue(&q); 

    while (runing){
        printf("\n");
        printf("=============================================================\n");
        printf("||                                                         ||\n");
        printf("||           UUU   UUU    NNN   NNN     OOOOOOO            ||\n");
        printf("||           UUU   UUU    NNNNN NNN    OOO   OOO           ||\n");
        printf("||           UUU   UUU    NNNNNNNNN    OOO   OOO           ||\n");
        printf("||           UUUU UUUU    NNN NNNNN    OOO   OOO           ||\n");
        printf("||            UUUUUUU     NNN   NNN     OOOOOOO            ||\n");   
        printf("||                                                         ||\n");
        printf("=============================================================\n");
        printf("\n              Selamat datang di Game UNO!                \n\n");
        printf("1. Mulai\n");
        printf("2. Info\n");
        printf("3. Keluar\n");
        printf("Masukkan Pilihan Anda: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
                system("cls");
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

    while (stay){
        system("cls");
        printf("=============================================================\n");
        printf("||                                                         ||\n");
        printf("||     MMM    MMM    EEEEEEE    NNN   NNN    UUU   UUU     ||\n");
        printf("||     MMMM  MMMM    EEE        NNNNN NNN    UUU   UUU     ||\n");
        printf("||     MMMMMMMMMM    EEEEEEE    NNNNNNNNN    UUU   UUU     ||\n");
        printf("||     MMM MM MMM    EEE        NNN NNNNN    UUUU UUUU     ||\n");
        printf("||     MMM    MMM    EEEEEEE    NNN   NNN     UUUUUUU      ||\n");   
        printf("||                                                         ||\n");
        printf("=============================================================\n");
        printf("\n                     Silahkan pilih                      \n\n");
        printf("1. Menu Pemain \n");
        printf("2. Mulai Permainan \n");
        printf("3. Kembali ke Menu Utama \n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &sub);
        getchar();

        switch (sub) {
            case 1:
                TampilkanDaftarPemain(q);
                break;  
            case 2:
                printf("Memulai permainan... \n");
                break;
            case 3:
                system("cls");
                stay = false;
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi. \n");
                break;
        }
    }
}
void backToMenu (){
    int pilihan;
    printf("\nKetik '1' untuk kembali: ");
    scanf("%d", &pilihan);
    getchar();
}