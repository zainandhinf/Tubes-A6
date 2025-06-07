#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "kartu.h"

void InitKartu(List *kartu)
{
    CreateList(kartu);

    WarnaKartu warna;
    int angka;
    int i, j;

    for (warna = MERAH; warna <= KUNING; warna++)
    {
        Kartu k0;
        k0.warna = warna;
        k0.jenis = ANGKA;
        k0.angka = 0;
        k0.efek = '\0';
        InsVLast(kartu, k0);

        for (angka = 1; angka <= 9; angka++)
        {
            for (i = 0; i < 2; i++)
            {
                Kartu k;
                k.warna = warna;
                k.jenis = ANGKA;
                k.angka = angka;
                k.efek = '\0';
                InsVLast(kartu, k);
            }
        }
    }

    JenisKartu aksi[] = {SKIP, REVERSE, DRAW2};
    for (warna = MERAH; warna <= KUNING; warna++)
    {
        for (i = 0; i < 3; i++)
        {
            JenisKartu jenis = aksi[i];
            for (j = 0; j < 2; j++)
            {
                Kartu k;
                k.warna = warna;
                k.jenis = jenis;
                k.angka = -1;
                k.efek = '\0';
                InsVLast(kartu, k);
            }
        }
    }

    for (i = 0; i < 4; i++)
    {
        Kartu wild;
        wild.warna = HITAM;
        wild.jenis = WILD;
        wild.angka = -1;
        wild.efek = '\0';
        InsVLast(kartu, wild);

        Kartu draw4;
        draw4.warna = HITAM;
        draw4.jenis = WILD_DRAW4;
        draw4.angka = -1;
        draw4.efek = '\0';
        InsVLast(kartu, draw4);
    }
}

boolean IsKartuEqual(Kartu a, Kartu b) {
    if (a.warna != b.warna) return false;
    if (a.jenis != b.jenis) return false;
    
    if (a.jenis == ANGKA && b.jenis == ANGKA) {
        return (a.angka == b.angka);
    }
    
    return true;
}

void BagiKartu(Stack *deck, PemainList pemain[]) {
    Kartu kartu;
    int i, j;
    
    for (i = 0; i < 4; i++) {
        pemain[i].root = NULL;
        pemain[i].info.jumlahKartu = 0;
    }
    
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 4; j++) {
            if (!IsEmpty(*deck)) {
                Pop(deck, &kartu);
                TambahKartuKePemain(&pemain[j], kartu);
            }
        }
    }
}

void TambahKartuKePemain(PemainList *pemain, Kartu kartu) {
    pemain->root = insert(pemain->root, kartu);
    pemain->info.jumlahKartu++;
}

void TampilkanKartuPemain(PemainList pemain) {
    printf("Jumlah kartu: %d\n", pemain.info.jumlahKartu);
    printf("Daftar kartu:\n");
    inOrder(pemain.root);
}

void kartuSkip (Queue *q, int jumlahPemain,int skipCount) {
    if (is_Empty(*q)) {
        printf("Tidak ada pemain dalam antrian.\n");
        return;
    }

    if (skipCount < 0 || skipCount >= jumlahPemain) {
        printf("Jumlah pemain yang ingin dilewati tidak valid.\n");
        return;
    }

    for (int i = 0; i < skipCount; i++) {
        PemainList pemainSekarang;
        deQueue(q, &pemainSekarang.info);
        EnQueue(q, pemainSekarang.info);
    }
    printf("Giliran telah dilewati sebanyak %d kali.\n", skipCount);
}


void kartuReverse (Queue *q){
    if (is_Empty(*q)) {
        printf("Tidak ada pemain dalam antrian.\n");
        return;
    }

    addresspemain prev = NULL;
    addresspemain current = q->Front;
    addresspemain next = NULL;

    q->Rear = q->Front; 

    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    }

    q->Front = prev; 
    printf("Antrian pemain telah dibalik.\n");
}