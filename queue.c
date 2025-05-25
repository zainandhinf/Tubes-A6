/*File body untuk ADT Queue*/
// Dibuat tanggal 28-3-2013

#include "queue.h"
#include <malloc.h>

/*Membuat sebuah queue baru dengan Front dan Rear NULL*/
void CreateQueue(Queue *Q)
{
	(*Q).Front = Nil;
	(*Q).Rear = Nil;
}

/*Memeriksa apakah queue kosong */
boolean is_Empty(Queue Q)
{
	return (Q.Front == Nil && Q.Rear == Nil);
}

/*Memeriksa apakah queue penuh */
boolean is_Full(Queue Q)
{
	address P;
	int jumlah;

	jumlah = 0;

	P = Q.Front;
	while (P != Nil)
	{
		jumlah++;
		P = P->next;
	}

	if (jumlah >= NBElement)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*Melekukan insertion pada queue*/
void EnQueue(Queue *Q, infotype X)
{
	address P;

	P = (address)malloc(sizeof(ElmtList));
	if (P != NULL)
	{
		if (is_Full(*Q))
		{
			printf("\nlist full\n");
		}
		else
		{
			Info(P) = X;
			Next(P) = Nil;
			if (is_Empty(*Q))
			{
				(*Q).Front = P;
				(*Q).Rear = P;
			}
			else
			{
				Next((*Q).Rear) = P;
				(*Q).Rear = P;
			}
		}
	}
}

/*Melakukan deletion pada queue*/
void deQueue(Queue *Q, infotype *X)
{
	address P;

	P = (*Q).Front;

	if (is_Empty(*Q))
	{
		printf("underflow!!");
	}
	else
	{
		*X = (*P).info;
		if ((*P).next != Nil)
		{
			(*Q).Front = (*P).next;
			(*P).next = Nil;
		}
		else
		{
			(*Q).Front = Nil;
			(*Q).Rear = Nil;
		}
		free(P);
	}
}
