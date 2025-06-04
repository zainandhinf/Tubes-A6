#ifndef PLAYER_H
#define PLAYER_H
#include "boolean.h"
#include "uno.h"
#include "sll.h"
#include "queue.h"



void InitGiliran(Queue *q, int jumlahPemain);
// Fungsi untuk menginisialisasi giliran pemain
// dengan memasukkan pemain ke dalam queue

void NextGiliran(Queue *q);
// fungsi untuk mengubah giliran pemain

Pemain *CurrentPlayer(Queue *q);
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

void DeletePlayer(PemainList **head, const char *nama, Queue *q);
// Fungsi untuk menghapus pemain dari list pemain

void PrintPlayerList(PemainList *head);
// Fungsi untuk mencetak list pemain

void TampilkanDaftarPemain(Queue q);
// Fungsi untuk menampilkan daftar pemain yang ada dalam queue

void skipPlayer(Queue *q, int jumlahPemain);
// Fungsi untuk melewati giliran pemain jika tidak ada pemain yang bermain

void reversePlayer(Queue *q);
// Fungsi untuk membalik urutan giliran pemain dalam queue
#endif