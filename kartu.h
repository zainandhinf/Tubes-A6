#ifndef KARTU_H
#define KARTU_H
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef max
#undef min

#include "boolean.h"
#include "uno.h"
#include "sll.h"
#include "stack.h"
#include "avl.h"
#include "player.h"
#include "deck.h"

typedef enum {
    COMPARE_EQUAL,      // Persis sama (warna+jenis+angka)
    COMPARE_SAMETYPE,   // Jenis sama (abaikan warna)
    COMPARE_PLAYABLE,   // Bisa dimainkan (termasuk wildcard)
    COMPARE_GROUP       // Untuk grup kartu sejenis
} CompareMode;


/* Inisialisasi & Struktur Data Kartu */
KartuNBTree* createNBTreeNode(Kartu card); 
// Membuat node untuk non binary tree rekomendasi kartu 
void InitKartu(List *kartu);
// Menginisialisasi list kartu sebanyak 108 node


/* Komparasi Kartu */
boolean compareCards(Kartu a, Kartu b, CompareMode mode);
// Membandingkan dua kartu berdasarkan CompareMode (kesamaan warna, jenis, atau kelayakan dimainkan)


/* Manajemen Gameplay */ 
void BagiKartu(Stack *deck, Queue *head);
// Membagikan kartu dari deck (stack) menjadi avltree (binarytree) ke pemain (queue) dan dihubungkan dengan pointer pada linkedlist pemain
void TambahKartuKePemain(PemainList *pemain, Kartu kartu);
// Menambahkan kartu ke tangan pemain
void TampilkanKartuPemain(PemainList *pemain);
// Menampilkan kartu yang dimiliki pemain
void printCard(Kartu k);
// Mencetak representasi kartu ke layar (dengan newline)
void printCardNoNewline(Kartu k);
// Versi printCard tanpa newline


/* Rekomendasi Kartu Non Binary Tree */
KartuNBTree* buildRecommendations(Kartu topDiscard, KartuBTree* playerCards);
// Membangun pohon rekomendasi kartu yang bisa dimainkan berdasarkan kartu di discard pile (topDiscard)
void addChild(KartuNBTree* parent, KartuNBTree* child);
// Menambahkan sebuah node child ke dalam tree rekomendasi kartu non binary tree sebagai anak dari node parent
void findMatchingCards(KartuNBTree* parent, KartuBTree* playerCards);
// Mencari kartu di tangan pemain yang cocok dengan pola tertentu
void findGroupMatches(KartuNBTree* node, Kartu matchPattern, KartuBTree* playerCards);
// Mencari grup kartu sejenis
void printRecommendations(KartuNBTree* node, int depth);
// Mencetak rekomendasi kartu yang bisa dimainkan
void deleteNBTree(KartuNBTree* node);
// Menghapus tree rekomendasi (dealokasi memori)


/* Rekomendasi Kartu Linked List */
void buildList(KartuNBTree* node, RecommendationList**list);
// Membangun linked list rekomendasi dari non bonary tree rekomendasi
void printAllList(RecommendationList* list);
// Mencetak semua linked list rekomendasi yang mungkin
void printRecommendationLists(KartuNBTree *root);
// Mencetak semua rekomendasi list
void addListFromLeaf(KartuNBTree* leaf, RecommendationList**list);
// Menambahkan linkedlist baru dari leaf node tree
int chooseRecommendation(RecommendationList* list);
// Meminta input pemain untuk memilih rekomendasi
RecommendationList* getSelectedList(RecommendationList* list, int choice);
// Mengambil linked list rekomendasi berdasarkan pilihan pemain
void playSelectedRecommendation(Stack* discardDeck, PemainList* player, KartuNBTree* recommendations);
// Memproses rekomendasi yang dipilih (memindahkan kartu ke discard pile)


/*  Efek Kartu Spesial */
void kartuReverse(Queue *q);
// Fungsi untuk membalik urutan giliran pemain dalam queue
void handleWildCard(Stack *discardDeck, Kartu playedCard);
// Menangani efek wildcard
void handleCardEffect(Stack *discardDeck, Queue *turnQueue, PemainList *currentPlayer, Stack *deck);
// Handle kartu efek


/* Gameplay */
void startGame(PemainList *players, Queue *turnQueue);
// Inisialisasi permainan dan gameplay
void checkWinCondition(Queue *turnQueue, bool *gameRunning);
// Handle cek kondisi menang dengan cek jumlah kartu pemain


/* Print Lain Lain */
void printSpaces(int count);
void printBTRecursive(KartuBTree *node, int depth, bool isLeft);
void printBinaryTree(KartuBTree *root);

#endif