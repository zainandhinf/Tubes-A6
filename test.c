#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sll.h"
#include "deck.h"
#include "kartu.h"
#include "player.h"
#include "menu.h"

#include <stdio.h>
#include "player.h"

int main() {
    PemainList *playerList;
    Queue giliran;

    // Inisialisasi pemain dan giliran
    initPlayer(&playerList, &giliran);
    InitGiliran(&giliran, playerList);

    printf("\n--- Urutan awal pemain ---\n");
    TampilkanDaftarPemain(giliran);

    // Test skipPlayer
    printf("\n--- Test skipPlayer (lewati 1 pemain) ---\n");
    // Simulasi input (tanpa scanf)
    int skipCount = 1;
    for (int i = 0; i < skipCount; i++) {
        PemainList pemainSekarang;
        deQueue(&giliran, &pemainSekarang.info);
        EnQueue(&giliran, pemainSekarang.info);
    }
    printf("Giliran telah dilewati sebanyak %d kali.\n", skipCount);
    printf("\n--- Setelah skip ---\n");
    TampilkanDaftarPemain(giliran);

    // Test reversePlayer
    printf("\n--- Test reversePlayer ---\n");
    reversePlayer(&giliran);
    printf("\n--- Setelah dibalik ---\n");
    TampilkanDaftarPemain(giliran);

    return 0;
}
