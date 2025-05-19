#ifndef UNO_H
#define UNO_H

#include <stdio.h>
#include "adt-queue/queue.h"
#include "adt-stack/STACK.h"
#include "adt-linked-list/SpNRSLL.h"

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
void ShuffleDeck(List *deck);
infotype DrawCard(List *deck);
void AddCardToDeck(List *deck, infotype kartu);
void InitGiliran(Queue *q, int jumlahPemain);
void NextGiliran(Queue *q);
int CurrentPlayer(Queue q);
void InitDiscard(Stack *s);
void PushDiscard(Stack *s, infotype kartu);
infotype TopDiscard(Stack s);
infotype PopDiscard(Stack *s);
void CreatePlayerList(Player **head);
Player *AlokasiPlayer(const char *nama);
void DealokasiPlayer(Player *P);
int PlayerListEmpty(Player *head);
void InsertPlayerFirst(Player **head, Player *P);
Player *SearchPlayer(Player *head, const char *nama);
int DeletePlayer(Player **head, const char *nama);
void PrintPlayerList(Player *head);
KartuList *AlokasiKartu(Kartu k);
void DealokasiKartu(KartuList *P);
int KartuListEmpty(KartuList *head);
void InsertKartuFirst(KartuList **head, KartuList *P);
void InsertKartuLast(KartuList **head, KartuList *P);
int DeleteKartu(KartuList **head, Kartu kartu);
int CountKartu(KartuList *head);
void PrintKartuList(KartuList *head);

#endif
