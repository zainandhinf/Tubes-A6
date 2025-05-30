#ifndef DECK_H
#define DECK_H
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "sll.h"
#include "stack.h"
#include "kartu.h"

void InitDeck(Stack *deck);
// Fungsi untuk menginisialisasi deck kartu
// dengan 108 kartu UNO
// 76 kart u angka (0-9) dari 4 warna
// 8 kartu SKIP dari 4 warna
// 8 kartu REVERSE dari 4 warna
// 8 kartu DRAW2 dari 4 warna
// 4 kartu WILD
// 4 kartu WILD DRAW4
void ShuffleDeck(List *deck);
// Fungsi untuk mengacak urutan kartu dalam deck
void DrawCard(Stack *deck, PemainList *pemain);
// Fungsi untuk mengambil kartu dari deck ke tangan pemain 
void AddCardToDeck(Stack *deck, Stack *discard);
// Fungsi untuk menambah kartu ke stack 
void InitDiscard(Stack *deck, Stack *discard);
// Fungsi untuk menginisialisasi  stack kartu yang dimainkan dan kartu pertamanya
void PushDiscard(Stack *s, infotype kartu);
// Fungsi untuk menambah kartu ke stack kartu yang dimainkan
infotype Top(Stack s);
// fungsi untuk melihat kartu yang ada di atas stack kartu yang dimainkan
infotype PopDiscard(Stack *s);
// fungsi untuk mengeluarkan kartu dari stack
boolean IsDiscardEmpty(Stack discard);
// Untuk mengecek apakah stack kosong
boolean IsDeckEmpty(List deck);
// Mengecek apakah deck kosong (untuk mencegah DrawCard dari deck kosong)
void RefillDeck(List *deck, Stack *discard);
// Saat deck habis, isi ulang deck dari discard pile kecuali kartu paling atas
int CountStack(Stack s);
// Menghitung jumlah kartu di dalam deck


#endif