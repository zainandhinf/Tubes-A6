#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deck.h"

void InitDeck(List *deck) {
    InitKartu(deck);
    ShuffleDeck(deck);
}

void ShuffleDeck(List *deck) {
    Kartu array[108];
    int n = 0;

    address p = First(*deck);
    while (p != Nil && n < 108) {
        array[n++] = Info(p);
        p = Next(p);
    }

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Kartu temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    CreateList(deck);
    for (int i = 0; i < n; i++) {
        InsVLast(deck, array[i]);
    }
}
