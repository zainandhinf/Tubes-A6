#ifndef uno_H
#define uno_H
#include <stdio.h>
#include "adt-queue/queue.h"
#include "adt-stack/STACK.h"
#include "adt-linked-list/SpNRSLL.H"

typedef enum
{
    MERAH,
    HIJAU,
    BIRU,
    KUNING,
    HITAM
} WarnaKartu;
typedef enum
{
    ANGKA,
    SKIP,
    REVERSE,
    DRAW2,
    DRAW4,
    WILD,
    WILD_DRAW4
} JenisKartu;
typedef char infotype;
typedef struct Kartu *addresskartu;
typedef struct KartuTree *addresstree;
typedef struct KartuList *addresslist;
typedef struct Player *addresspemain;
typedef struct
{
    WarnaKartu warna;
    JenisKartu jenis;
    int angka;
} Kartu;

typedef struct
{
    addresskartu info;
    addresstree left;
    addresstree right;
} KartuTree;

typedef struct
{
    addresskartu info;
    addresslist next;
} KartuList;

typedef struct
{
    char nama[50];
    addresskartu tangan;
    int jumlahKartu;
    int sudahUndoRedo;
    addresspemain next;
} Player;

#endif