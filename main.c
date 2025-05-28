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

    PrintStack(deck);
    InitDiscard(&discard);
    InitFirstCard(&deck, &discard); // udh ada printf didalamnya
    printf("\n");
    printf("Jumlah kartu di deck setelah InitFirstCard: %d\n", CountStack(deck));
    printf("Jumlah kartu di discard setelah InitFirstCard: %d\n", CountStack(discard));
    return 0;
}