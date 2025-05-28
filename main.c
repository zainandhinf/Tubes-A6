#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sll.h"
#include "deck.h"
#include "kartu.h"

int main(){
    // Seed random
    srand(time(NULL));

    Stack deck;
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
    return 0;
}