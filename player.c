#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "player.h"


void InitGiliran(Queue *q, int jumlahPemain) {
    CreateQueue(q);

    getchar();  // Membuang newline dari scanf jumlahPemain, hanya SEKALI

    for (int i = 0; i < jumlahPemain; i++) {
        Pemain pemainBaru;

        printf("\nMasukkan nama pemain %d: ", i + 1);
        fgets(pemainBaru.nama, sizeof(pemainBaru.nama), stdin);
        pemainBaru.nama[strcspn(pemainBaru.nama, "\n")] = 0; // Hapus newline

        pemainBaru.jumlahKartu = 0;
        EnQueue(q, pemainBaru);
        printf("Pemain %s berhasil dimasukkan\n", pemainBaru.nama);
    }
}

void NextGiliran(Queue *q){
    if (is_Empty(*q)){
        printf("tidak ada pemain dalam antrian \n");
    }
    PemainList pemainSekarang;
    deQueue(q, &pemainSekarang.info);
    EnQueue(q, pemainSekarang.info);
    printf("giliran telah berpindah \n");
}
Pemain *CurrentPlayer(Queue *q){
    if(is_Empty(*q)){
        static Pemain playerKosong;
        strcpy(playerKosong.nama, "tidak ada player \n");
        playerKosong.jumlahKartu = 0;
        printf("giliran pemain kosong \n");
        return &playerKosong;
    } else{
        return &q->Front->info;
    }
    return 0; 
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
        printf("pemain '%s' berhasil di alokasikan \n", pemainBaru->info.nama);
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
    if (P != NULL){
        P->next = *head;
        *head = P;
        printf("pemain berhasil di masukkan \n");
    } else {
        printf("gagal memasukkan pemain ke dalam list \n");
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
void DeletePlayer(PemainList **head, const char *nama, Queue *q){
    PemainList *currentplayer = *head;
    PemainList *prev = NULL;

    if ((CurrentPlayer(q)!= NULL) && (strcmp(CurrentPlayer(q)->nama,nama)==0) ){
        *head = currentplayer->next;
        DealokasiPlayer(currentplayer);
        printf("pemain '%s' berhasil di hapus \n", nama);
        return;
    }
    while (currentplayer != NULL && strcmp(currentplayer->info.nama, nama) != 0) {
        prev = currentplayer;
        currentplayer = currentplayer->next;
    }
    if (currentplayer != NULL) {
        prev->next = currentplayer->next;
        DealokasiPlayer(currentplayer);
        printf("pemain '%s' berhasil di hapus \n", nama);
    } else {
        printf("pemain '%s' tidak di temukan \n", nama);
    }
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

    printf("\n=== Daftar Pemain ===\n");
    while (current != NULL) {
        count++;
        printf("%d. %s\n", count, current->info.nama);
        current = current->next;
    }
    printf("Total pemain: %d\n", count);
}