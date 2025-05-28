#include "deck.h"

void InitDeck(Stack *deck) {
    List kartu;
    InitKartu(&kartu);
    ShuffleDeck(&kartu);

    CreateEmpty(deck);

    address p = First(kartu);
    while (p != Nil) {
        Push(deck, Info(p));
        p = Next(p);
    }
}

void ShuffleDeck(List *deck) {
    Kartu array[108];
    int i;
    int n = 0;

    address p = First(*deck);
    while (p != Nil && n < 108) {
        array[n++] = Info(p);
        p = Next(p);
    }

    for (i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Kartu temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    CreateList(deck);
    for (i = 0; i < n; i++) {
        InsVLast(deck, array[i]);
    }
}


void InitDiscard(Stack *s) {
    CreateEmpty(s);
}

infotype Top(Stack s) {
    if (IsEmpty(s)) {
        printf("Stack kosong\n");

        infotype dummy;
        dummy.jenis = ANGKA;
        dummy.angka = -1;
        dummy.warna = HITAM;
        dummy.efek = '\0';

        return dummy;
    } else {
        return Info(s);
    }
}

void InitFirstCard(Stack *deck, Stack *discard) {
    infotype kartu;
    Stack temp1; // Untuk menyimpan kartu aksi sementara
    Stack temp2; // Untuk menyimpan kartu angka sementara (hanya 1 kartu)

    CreateEmpty(&temp1);
    CreateEmpty(&temp2);

    while (!IsEmpty(*deck)) {
        Pop(deck, &kartu);
        if (kartu.jenis == ANGKA) {
            Push(&temp2, kartu);
            break;
        } else {
            Push(&temp1, kartu);
        }
    }

    if (IsEmpty(temp2)) {
        while (!IsEmpty(temp1)) {
            Pop(&temp1, &kartu);
            Push(deck, kartu);
        }
        return;
    }

    while (!IsEmpty(temp1)) {
        Pop(&temp1, &kartu);
        Push(deck, kartu);
    }

    Pop(&temp2, &kartu);
    Push(deck, kartu);

    Pop(deck, &kartu);
    Push(discard, kartu);
    printf("Kartu pertama: ");
    switch (kartu.jenis) {
        case ANGKA: printf("%d ", kartu.angka); break;
        case SKIP: printf("SKIP "); break;
        case REVERSE: printf("REVERSE "); break;
        case DRAW2: printf("DRAW 2 "); break;
        case WILD: printf("WILD "); break;
        case WILD_DRAW4: printf("WILD DRAW 4 "); break;
    }
    switch (kartu.warna) {
        case MERAH: printf("[MERAH]\n"); break;
        case HIJAU: printf("[HIJAU]\n"); break;
        case BIRU: printf("[BIRU]\n"); break;
        case KUNING: printf("[KUNING]\n"); break;
        case HITAM: printf("[HITAM]\n"); break;
    }
}

int CountStack(Stack s) {
    int count = 0;
    while (s != NULL) {
        count++;
        s = Next(s);
    }
    return count;
}