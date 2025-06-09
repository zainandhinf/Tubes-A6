#ifndef UNO_H
#define UNO_H

#include <stdio.h>
#include <stdbool.h>

extern bool pemainSudahDiinput;

/* Deklarasi Enum */
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


/* Struktur Data Kartu */
typedef struct Kartu{
    WarnaKartu warna;
    JenisKartu jenis;
    int angka;
    char efek;
} Kartu;

typedef Kartu infotype;

typedef struct KartuBTree {
    Kartu info;
    struct KartuBTree *left;
    struct KartuBTree *right;
    int height;
} KartuBTree;

typedef struct KartuNBTree {
    Kartu card;
    struct KartuNBTree* firstson;
    struct KartuNBTree* nextbrother;
    struct KartuNBTree* parent;
} KartuNBTree;

typedef struct KartuList {
    Kartu card;
    struct KartuList* next;
} KartuList;

typedef struct RecommendationList {
    KartuList* head;
    KartuList* tail;
    struct RecommendationList* next;
} RecommendationList;


/* Struktur Data Pemain */
typedef struct  PemainList *addresspemain;
typedef struct Pemain {
    char nama[50];
    int jumlahKartu;
} Pemain;
typedef struct PemainList {
    Pemain info;
    struct PemainList *next;
    KartuBTree *root;
} PemainList;

typedef struct {
    addresspemain Front;
    addresspemain Rear;
} Queue;

void startProgram();
// Tampilan awal program saat di jalankan
void menuPlay();
// Tampilan menu play
void menuInfo();
// Tampilan menu info untuk how to play
void backToMenu();
// Handle kembali ke menu
void menuPemain();  
// Tampilan menu pemain

#endif
