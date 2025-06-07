#ifndef KARTU_H
#define KARTU_H
#include "boolean.h"
#include "uno.h"
#include "sll.h"
#include "stack.h"
#include "avl.h"

typedef enum {
    COMPARE_EQUAL,      // Persis sama (warna+jenis+angka)
    COMPARE_SAMETYPE,   // Jenis sama (abaikan warna)
    COMPARE_PLAYABLE,   // Bisa dimainkan (termasuk wildcard)
    COMPARE_GROUP       // Untuk grup kartu sejenis
} CompareMode;

KartuNBTree* createNBTreeNode(Kartu card);
void InitKartu(List *kartu);
boolean compareCards(Kartu a, Kartu b, CompareMode mode);
void BagiKartu(Stack *deck, PemainList pemain[]);
void TambahKartuKePemain(PemainList *pemain, Kartu kartu);
void TampilkanKartuPemain(PemainList pemain);
void addChild(KartuNBTree* parent, KartuNBTree* child);
void printCard(Kartu k);
KartuNBTree* buildRecommendations(Kartu topDiscard, KartuBTree* playerCards);
void findMatchingCards(KartuNBTree* parent, KartuBTree* playerCards);
void findGroupMatches(KartuNBTree* node, Kartu matchPattern, KartuBTree* playerCards);
void deleteNBTree(KartuNBTree* node);
void printRecommendationLists(KartuNBTree* root);
void buildPaths(KartuNBTree* node, RecommendationPath** paths);
void printAllPaths(RecommendationPath* paths);
void printRecommendations(KartuNBTree* node, int depth);
void addPathFromLeaf(KartuNBTree* leaf, RecommendationPath** paths);
void printCardNoNewline(Kartu k);
int chooseRecommendation(RecommendationPath* paths);
RecommendationPath* getSelectedPath(RecommendationPath* paths, int choice);
void playSelectedRecommendation(Stack* discardDeck, PemainList* player, KartuNBTree* recommendations);

#endif