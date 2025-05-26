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

int CurrentPlayer(Queue q);
// Fungsi untuk mendapatkan pemain yang sedang bermain dari queue

void CreatePlayerList(Pemain **head);
// Fungsi untuk membuat list pemain

Pemain *AlokasiPlayer(const char *nama);
// Fungsi untuk mengalokasi memori untuk pemain baru

void DealokasiPlayer(Pemain *P);
// Fungsi untuk dealokasi memori pemain jika sudah tidak digunakan

boolean PlayerListEmpty(Pemain *head);
// Fungsi untuk mengecek apakah list pemain kosong atau tidak

void InsertPlayerFirst(Pemain **head, Pemain *P);
// Fungsi untuk menambah pemain ke list pemain

Pemain *SearchPlayer(Pemain *head, const char *nama);
// Fungsi untuk mencari pemain dalam list pemain

void DeletePlayer(Pemain **head, const char *nama);
// Fungsi untuk menghapus pemain dari list pemain

void PrintPlayerList(Pemain *head);
// Fungsi untuk mencetak list pemain

#endif