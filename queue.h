/*File header untuk ADT Queue*/

#ifndef queue_h
#define queue_h
#include "BOOLEAN.H"
#include "SpNRSLL.H"
#define NBElement 10

typedef ListQueue Queue;

/*Membuat sebuah queue baru dengan Front dan Rear NULL*/
void CreateQueue (Queue *Q);

/*Memeriksa apakah queue kosong */
boolean is_Empty (Queue Q);

/*Memeriksa apakah queue penuh */
boolean is_Full (Queue Q);

/*Melekukan insertion pada queue*/
void EnQueue (Queue *Q, infotype X);

/*Melakukan deletion pada queue*/
void deQueue (Queue *Q, infotype *X);

#endif

