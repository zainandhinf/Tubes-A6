#ifndef KARTU_H
#define KARTU_H
#include "boolean.h"
#include "uno.h"
#include "sll.h"
#include "stack.h"
#include "avl.h"
#include "player.h"

void InitKartu(List *kartu);
boolean IsKartuEqual(Kartu a, Kartu b);
void BagiKartu(Stack *deck, PemainList pemain[]);
void TambahKartuKePemain(PemainList *pemain, Kartu kartu);
void TampilkanKartuPemain(PemainList pemain);
void kartuSkip(Queue *q, int jumlahPemain, int skipCount);
// Fungsi untuk melewati giliran pemain jika tidak ada pemain yang bermain
void kartuReverse(Queue *q);
// Fungsi untuk membalik urutan giliran pemain dalam queue

#endif