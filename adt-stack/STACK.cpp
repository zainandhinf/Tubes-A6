/* File        : stack.cpp */
/* Deskripsi   : Body ADT stack yang diimplementasikan dgn linked list */
/* Dibuat oleh : Ade Chandra Nugraha*/

#include "stack.h"
#include <malloc.h>

/**** Perubahan nilai komponen struktur ****/
void SetTop (Stack *S, Stack NewTop )
/* Memberi Nilai TOP yang baru dengan NewTop */
{
	*S = NewTop;
}

/*    PROTO TYPE    */
/**** Konstruktor/Kreator ****/
void CreateEmpty (Stack *S)
/* IS : S sembarang */
/* FS : Membuat sebuah stack S yang kosong */
/* Ciri stack kosong : TOP bernilai NULL */
{
	*S = NULL;
}

/**** Predikat untuk test keadaan KOLEKSI ****/
boolean IsEmpty (Stack S)
/* Mengirim true jika Stack Kosong */
{
	return (S == Nil);
}

/**** Menambahkan sebuah elemen ke Stack ****/
void Push (Stack *S, infotype X)
/* Menambahkan X sebagai elemen stack S */
/* IS : S mungkin kosong */
/* FS : X menjadi TOP yang baru */
{
	address P;
	
	P = (address)malloc(sizeof(ElmtList));
	
    if (P != NULL) {
    	if (IsEmpty(*S)){
    		Info(P) = X;
	        Next(P) = Nil;
	        SetTop(S, P);
		} else {
			Info(P) = X;
	        Next(P) = *S;
	        SetTop(S, P);			
		}
    }
}

/**** Menghapus sebuah elemen Stack ****/
void Pop (Stack *S, infotype *X)
/* Menghapus X dari Stack S */
/* IS : S tidak mungkin kosong */
/* FS : X adalah nilai elemen TOP yang lama */
{
	address P;
	
	P = (address)malloc(sizeof(ElmtList));
	
	if (P != NULL) {
    	if (IsEmpty(*S)){
    		printf("Stack Kosong!!");
		} else {
			P = *S;
			*X = Info(P);
	        *S = Next(P);
	        Next(P) = Nil;
	        free(P);
		}
    }
}

// modul tambahan untuk melihat isi stack
void PrintStack(Stack S) {
    if (IsEmpty(S)) {
        printf("Stack kosong.\n");
    } else {
        printf("Isi Stack (dari atas ke bawah): ");
        Stack temp = S; 
        while (temp != NULL) {
            printf("%d ", Info(temp));
            temp = Next(temp);
        }
        printf("\n");
    }
}

