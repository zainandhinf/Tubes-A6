#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"

void InitGiliran(Queue *q, int jumlahPemain);
void NextGiliran(Queue *q);
int CurrentPlayer(Queue q);
void CreatePlayerList(Pemain **head);
Pemain *AlokasiPlayer(const char *nama);
void DealokasiPlayer(Pemain *P);
boolean PlayerListEmpty(Pemain *head);
void InsertPlayerFirst(Pemain **head, Pemain *P);
Pemain *SearchPlayer(Pemain *head, const char *nama);
void DeletePlayer(Pemain **head, const char *nama);
void PrintPlayerList(Pemain *head);