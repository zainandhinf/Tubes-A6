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
    InitDeck(&deck); 
    InitDiscard(&discard);
    InitFirstCard(&deck, &discard); // udh ada printf didalamnya
    printf("\n");
    printf("Jumlah kartu di deck setelah InitFirstCard: %d\n", CountStack(deck));
    printf("Jumlah kartu di discard setelah InitFirstCard: %d\n", CountStack(discard));
    return 0;
}