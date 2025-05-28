#ifndef KARTU_H
#define KARTU_H
#include "boolean.h"
#include "uno.h"
#include "sll.h"
#include "stack.h"
#include "avl.h"

void InitKartu(List *kartu);
boolean IsKartuEqual(Kartu a, Kartu b);
void BagiKartu(Stack *deck, PemainList pemain[]);
void TambahKartuKePemain(PemainList *pemain, Kartu kartu);
void TampilkanKartuPemain(PemainList pemain);

#endif