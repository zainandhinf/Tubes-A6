#ifndef UNO_H
#define UNO_H

#include <stdio.h>
#include "queue.h"
#include "STACK.h"
#include "SpNRSLL.h"

typedef enum {
    MERAH,
    HIJAU,
    BIRU,
    KUNING,
    HITAM
} WarnaKartu;

typedef enum {
    ANGKA,
    SKIP,
    REVERSE,
    DRAW2,
    DRAW4,
    WILD,
    WILD_DRAW4
} JenisKartu;

typedef struct {
    // Hapus/ubah aja kalo gk perlu
    WarnaKartu warna;
    JenisKartu jenis;
    int angka; // Hanya jika jenis == ANGKA
} Kartu;

typedef struct KartuTree {
    Kartu info;
    struct KartuTree *left;
    struct KartuTree *right;
} KartuTree;

typedef struct KartuList {
    Kartu info;
    struct KartuList *next;
} KartuList;

typedef struct Player {
    char nama[50];
    KartuList *tangan;
    int jumlahKartu;
    int sudahUndoRedo;
    struct Player *next;
} Player;

void InitDeck(List *deck);
// Fungsi untuk menginisialisasi deck kartu
// dengan 108 kartu UNO
// 76 kart u angka (0-9) dari 4 warna
// 8 kartu SKIP dari 4 warna
// 8 kartu REVERSE dari 4 warna
// 8 kartu DRAW2 dari 4 warna
// 4 kartu WILD
// 4 kartu WILD DRAW4
void ShuffleDeck(List *deck);
// Fungsi untuk mengacak urutan kartu dalam deck
infotype DrawCard(List *deck);
// Fungsi untuk menarik kartu dari deck jika tidak yang di mainin
void AddCardToDeck(List *deck, infotype kartu);
// Fungsi untuk menambah kartu ke deck
void InitGiliran(Queue *q, int jumlahPemain);
// Fungsi untuk menginisialisasi giliran pemain
// dengan memasukkan pemain ke dalam queue
void NextGiliran(Queue *q);
// fungsi untuk mengubah giliran pemain
int CurrentPlayer(Queue q);
// Fungsi untuk mendapatkan pemain yang sedang bermain dari queue
void InitDiscard(Stack *s);
// Fungsi untuk menginisialisasi  stack kartu yang dimainin
void PushDiscard(Stack *s, infotype kartu);
// Fungsi untuk menambah kartu ke stack kartu yang dimainin
infotype TopDiscard(Stack s);
// fungsi untuk melihat kartu yang ada di atas stack kartu yang dimainin
infotype PopDiscard(Stack *s);
// fungsi untuk mengeluarkan kartu dari stack untuk undo
void CreatePlayerList(Player **head);
// Fungsi untuk membuat list pemain
Player *AlokasiPlayer(const char *nama);
// Fungsi untuk mengalokasi memori untuk pemain baru
void DealokasiPlayer(Player *P);
// Fungsi untuk dealokasi memori pemain jika sudah tidak digunakan
boolean PlayerListEmpty(Player *head);
// Fungsi untuk mengecek apakah list pemain kosong atau tidak
void InsertPlayerFirst(Player **head, Player *P);
// Fungsi untuk menambah pemain ke list pemain
Player *SearchPlayer(Player *head, const char *nama);
// Fungsi untuk mencari pemain dalam list pemain
void DeletePlayer(Player **head, const char *nama);
// Fungsi untuk menghapus pemain dari list pemain
void PrintPlayerList(Player *head);
// Fungsi untuk mencetak list pemain
KartuList *AlokasiKartu(Kartu k);
// Fungsi untuk mengalokasi memori untuk kartu baru
void DealokasiKartu(KartuList *P);
// Fungsi untuk dealokasi memori kartu jika sudah tidak digunakan
boolean KartuListEmpty(KartuList *head);
// Fungsi untuk mengecek apakah list kartu kosong atau tidak
void InsertKartuFirst(KartuList **head, KartuList *P);
// Fungsi untuk menambah kartu ke list kartu
void InsertKartuLast(KartuList **head, KartuList *P);
// Fungsi untuk menambah kartu ke list kartu
void DeleteKartu(KartuList **head, Kartu kartu);
// Fungsi untuk menghapus kartu dari list kartu
int CountKartu(KartuList *head);
// Fungsi untuk menghitung jumlah kartu dalam list kartu
void PrintKartuList(KartuList *head);
// Fungsi untuk mencetak list kartu

#endif
