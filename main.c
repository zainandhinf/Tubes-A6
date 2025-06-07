#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sll.h"
#include "deck.h"
#include "kartu.h"

int main(){
    // Seed random
    srand(time(NULL));

    Stack deck, discard;
    PemainList pemain[4];
    int i;

    InitDeck(&deck); 
    BagiKartu(&deck, pemain);
    
    for (i = 0; i < 4; i++) {
        printf("Pemain %d:\n", i+1);
        TampilkanKartuPemain(pemain[i]);
        printf("\n");
    }

    // PrintStack(deck);
    InitDiscard(&deck, &discard); // udh ada printf didalamnya

    Kartu topDiscard = Top(discard);
    printf("\nKartu teratas di discard pile: ");
    printCard(topDiscard);

    printf("\nRekomendasi kartu untuk Pemain 1:\n");
    KartuNBTree* recommendations = buildRecommendations(topDiscard, pemain[0].root);
    
    printRecommendations(recommendations, 0);

    printRecommendationLists(recommendations);

    playSelectedRecommendation(&discard, &pemain[0], recommendations);

        for (i = 0; i < 4; i++) {
        printf("Pemain %d:\n", i+1);
        TampilkanKartuPemain(pemain[i]);
        printf("\n");
    }

    topDiscard = Top(discard);
    printf("\nKartu teratas di discard pile: ");
    printCard(topDiscard);
    
    // deleteNBTree(recommendations);

    // printf("\n");
    printf("Jumlah kartu di deck setelah InitFirstCard: %d\n", CountStack(deck));
    printf("Jumlah kartu di discard setelah InitFirstCard: %d\n", CountStack(discard));
    return 0;
}