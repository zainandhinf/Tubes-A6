#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sll.h"
#include "deck.h"
#include "kartu.h"

int main(){
    // Seed random
    srand(time(NULL));

    List kartu;
    InitDeck(&kartu);

    PrintInfo(kartu);
    return 0;
}