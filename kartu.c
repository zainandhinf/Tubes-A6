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
    preOrder(pemain.root);
}