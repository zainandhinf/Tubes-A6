#ifndef PLAYER_H
#define PLAYER_H
#include "boolean.h"
#include "uno.h"
#include "sll.h"
#include "queue.h"

void initPlayer(PemainList **head, Queue *q);
// Fungsi untuk menginisialisasi list pemain dan queue
// dengan memasukkan pemain ke dalam list dan queue

void InitGiliran(Queue *q, PemainList *head);
// Fungsi untuk menginisialisasi giliran pemain
// dengan memasukkan pemain ke dalam queuec

void NextGiliran(Queue *q);
// fungsi untuk mengubah giliran pemain

PemainList *CurrentPlayer(Queue *q);
// Fungsi untuk mendapatkan pemain yang sedang bermain dari queue

void CreatePlayerList(PemainList **head);
// Fungsi untuk membuat list pemain

PemainList *AlokasiPlayer(const char *nama);
// Fungsi untuk mengalokasi memori untuk pemain baru

void DealokasiPlayer(PemainList *P);
// Fungsi untuk dealokasi memori pemain jika sudah tidak digunakan

boolean PlayerListEmpty(PemainList *head);
// Fungsi untuk mengecek apakah list pemain kosong atau tidak

void InsertPlayerFirst(PemainList **head, PemainList *P);
// Fungsi untuk menambah pemain ke list pemain

PemainList *SearchPlayer(PemainList *head, const char *nama);
// Fungsi untuk mencari pemain dalam list pemain

void DeletePlayer(PemainList **head, Queue *q);
// Fungsi untuk menghapus pemain dari list pemain

void PrintPlayerList(PemainList *head);
// Fungsi untuk mencetak list pemain

void TampilkanDaftarPemain(Queue q);
// Fungsi untuk menampilkan daftar pemain yang ada dalam queue

#endif