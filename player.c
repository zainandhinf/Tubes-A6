#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "player.h"
#include "avl.h"

void initPlayer(PemainList **head, Queue *q) {
    int i;
    const char *namaPemain[] = {"Pemain 1", "Pemain 2", "Pemain 3", "Pemain 4"};

    *head = NULL;

    for (i = 0; i < 4; i++) {
        PemainList *pemainBaru = AlokasiPlayer(namaPemain[i]);
        InsertPlayerFirst(head, pemainBaru);
    }

    printf("Inisialisasi 4 pemain selesai.\n");
}

void InitGiliran(Queue *q, PemainList *head ) {
    CreateQueue(q);

    PemainList *current = head;
    while (current != NULL) {
        Pemain pemain;
        strncpy(pemain.nama, current->info.nama, sizeof(pemain.nama) - 1);
        pemain.nama[sizeof(pemain.nama) - 1] = '\0';
        pemain.jumlahKartu = current->info.jumlahKartu;

        EnQueue(q, pemain);
        current = current->next;
    }

    printf("Giliran pemain berhasil diinisialisasi dari daftar pemain.\n");
}

void NextGiliran(Queue *q){
    if (is_Empty(*q)){
        printf("Tidak ada pemain dalam antrian \n");
    }
    PemainList pemainSekarang;
    deQueue(q, &pemainSekarang.info);
    EnQueue(q, pemainSekarang.info);
}
// Pemain *CurrentPlayer(Queue *q){
//     if(is_Empty(*q)){
//         static Pemain playerKosong;
//         strcpy(playerKosong.nama, "tidak ada player \n");
//         playerKosong.jumlahKartu = 0;
//         printf("giliran pemain kosong \n");
//         return &playerKosong;
//     } else{
//         return &q->Front->info;
//     }
//     return 0; 
// }

PemainList *CurrentPlayer(Queue *q){
    if(is_Empty(*q)){
        printf("giliran pemain kosong \n");
        return NULL;
    } else{
        return q->Front; 
    }
}
void CreatePlayerList(PemainList **head){
    *head = NULL;
    printf("list berhasil di buat : \n");
}
PemainList *AlokasiPlayer(const char *nama){
    PemainList *pemainBaru = (PemainList *)malloc(sizeof(PemainList));
    if (pemainBaru != NULL){
        
        strncpy(pemainBaru->info.nama, nama, sizeof(pemainBaru->info.nama)-1);
        pemainBaru->info.nama[sizeof(pemainBaru->info.nama) - 1] = '\0';
        pemainBaru->info.jumlahKartu = 0;
        pemainBaru->next = NULL;
        // printf("pemain '%s' berhasil di alokasikan \n", pemainBaru->info.nama);
    } else {
        printf("gagal mengalokasikan pemain \n");
    }
    return pemainBaru;
}  
void DealokasiPlayer(PemainList *P){
    if (P != NULL){
        printf("dealokasi pemain '%s' \n", P->info.nama);
        free(P);
    } else {
        printf("gagal mendealokasi pemain \n");
    }
}
boolean PlayerListEmpty(PemainList *head){
    return (head == NULL);
}
void InsertPlayerFirst(PemainList **head, PemainList *P){
    if (*head == NULL) {
        *head = P;
    } else {
        PemainList *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = P;
    }
}
PemainList *SearchPlayer(PemainList *head, const char *nama){
    PemainList *CurrentPlayer = head;
    while (CurrentPlayer != NULL){
        if (strcmp(CurrentPlayer->info.nama,nama)==0){
            printf("pemain '%s' di temukan \n", nama);
            return CurrentPlayer;
            }
        CurrentPlayer = CurrentPlayer->next;
        }
    printf("pemain '%s' tidak di temukan", nama);
    return NULL;
}
void DeletePlayer(PemainList **head, Queue *q){
    // PemainList *currentplayer = *head;
    // PemainList *prev = NULL;

    // if ((CurrentPlayer(q)!= NULL) && (strcmp(CurrentPlayer(q)->info.nama,nama)==0) ){
    //     *head = currentplayer->next;
    //     DealokasiPlayer(currentplayer);
    //     printf("pemain '%s' berhasil di hapus \n", nama);
    //     return;
    // }
    // while (currentplayer != NULL && strcmp(currentplayer->info.nama, nama) != 0) {
    //     prev = currentplayer;
    //     currentplayer = currentplayer->next;
    // }
    // if (currentplayer != NULL) {
    //     prev->next = currentplayer->next;
    //     DealokasiPlayer(currentplayer);
    //     printf("pemain '%s' berhasil di hapus \n", nama);
    // } else {
    //     printf("pemain '%s' tidak di temukan \n", nama);
    // }
    while (*head != NULL) {
        PemainList *temp = *head;
        *head = (*head)->next;
        // Hapus tree kartu pemain jika perlu
        deleteTree(temp->root);
        free(temp);
    }
    
    // Reset queue
    CreateQueue(q);
    
    // Reset flag
    pemainSudahDiinput = false;
}

void PrintPlayerList(PemainList *head){
    PemainList *currentplayer = head;
    if (PlayerListEmpty(head)) {
        printf("list pemain kosong \n");
        return;
    }
    printf("List Pemain:\n");
    while (currentplayer != NULL) {
        printf("Nama: %s, Jumlah Kartu: %d\n", 
                currentplayer->info.nama, 
                currentplayer->info.jumlahKartu);
        currentplayer = currentplayer->next;
    }
}

void TampilkanDaftarPemain(Queue q) {
    if (is_Empty(q)) {
        printf("Belum ada pemain yang didaftarkan.\n");
        return;
    }

    int count = 0;
    addresspemain current = q.Front;
    printf("=============================================================\n");
    printf("||                                                         ||\n");
    printf("||     MMM    MMM    EEEEEEE    NNN   NNN    UUU   UUU     ||\n");
    printf("||     MMMM  MMMM    EEE        NNNNN NNN    UUU   UUU     ||\n");
    printf("||     MMMMMMMMMM    EEEEEEE    NNNNNNNNN    UUU   UUU     ||\n");
    printf("||     MMM MM MMM    EEE        NNN NNNNN    UUUU UUUU     ||\n");
    printf("||     MMM    MMM    EEEEEEE    NNN   NNN     UUUUUUU      ||\n");   
    printf("||                                                         ||\n");
    printf("=============================================================\n");
    printf("\n                     Daftar Pemain                         \n");
    while (current != NULL) {
        count++;
        printf("%d. %s\n", count, current->info.nama);
        current = current->next;
    }
    printf("Total pemain: %d\n", count);
}


