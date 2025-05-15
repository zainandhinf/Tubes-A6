/* File        : mainNRSL.cpp */
/* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
/* Dibuat oleh : Ade Chandra Nugraha*/
/* Tanggal     : 25-10-2001 */
/* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar */
/* Diupdate oleh : WW & AM, 8-3-2025, penyesuaian area body & main untuk latihan Diploma 3 */

#include "spnrsll.h"
#include <stdio.h>
//
//int main()
//{
//	/* Kamus Lokal */
//		List MyList;
//		infotype isi;
//		address P, Prec;
//
//	/* Program */
//	CreateList (&MyList);	//List sudah terbentuk, digunakan untuk memanipulasi elemen
//	
//	//aksi mahasiswa untuk implementasi studi kasus
//	
//	// Menambahkan elemen di awal
//    P = Alokasi(10);
//    InsertFirst(&MyList, P);
//
//    // Menambahkan elemen di akhir
//    P = Alokasi(20);
//    InsertLast(&MyList, P);
//
//    // Menambahkan elemen setelah 10
//    P = Alokasi(15);
//    Prec = Search(MyList, 10);
//    if (Prec != NULL)
//    {
//        InsertAfter(&MyList, P, Prec);
//    }
//
//    // Menampilkan list setelah penambahan elemen
//    printf("List setelah penambahan elemen:\n");
//    PrintInfo(MyList);
//
//    // Menghapus elemen pertama
//    DelFirst(&MyList, &P);
//    DeAlokasi(P);
//
//    // Menghapus elemen tertentu (15)
//    DelP(&MyList, 15);
//
//    // Menghapus elemen terakhir
//    DelLast(&MyList, &P);
//    DeAlokasi(P);
//
//    // Menampilkan list setelah penghapusan
//    printf("List setelah penghapusan elemen:\n");
//    PrintInfo(MyList);
//
//    // Menghapus semua elemen
//    DelAll(&MyList);
//
//    // Menampilkan list kosong
//    printf("List setelah semua elemen dihapus:\n");
//    PrintInfo(MyList);
//
//	/* Finishing */
//	
//	//Pastikan List di Dealokasi setelah manipulasi elemen selesai
//	
//	return 0;
//}


///* File        : mainNRSL.cpp */
///* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
///* Dibuat oleh : Ade Chandra Nugraha */
///* Tanggal     : 25-10-2001 */
///* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar */
///* Diupdate oleh : WW & AM, 8-3-2025, penyesuaian area body & main untuk latihan Diploma 3 */
//
//#include "spnrsll.h"
//#include <stdio.h>
//
//int main()
//{
//    /* Kamus Lokal */
//    List MyList;
//    infotype isi;
//    address P, Prec;
//
//    /* Program */
//    CreateList(&MyList); // Membentuk list kosong
//
//    printf("Masukkan elemen pertama: ");
//    scanf("%d", &isi);
//    P = Alokasi(isi);
//    InsertFirst(&MyList, P); // Tambah elemen pertama
//
//    printf("Masukkan elemen kedua: ");
//    scanf("%d", &isi);
//    P = Alokasi(isi);
//    InsertLast(&MyList, P); // Tambah elemen terakhir
//
//    printf("\nIsi List setelah penambahan:\n");
//    PrintInfo(MyList);
//
//    // Hapus elemen pertama
//    DelFirst(&MyList, &P);
//    printf("\nIsi List setelah menghapus elemen pertama:\n");
//    PrintInfo(MyList);
//
//    // Hapus elemen terakhir
//    DelLast(&MyList, &P);
//    printf("\nIsi List setelah menghapus elemen terakhir:\n");
//    PrintInfo(MyList);
//
//    // Pastikan semua elemen didealokasi sebelum program berakhir
//    DelAll(&MyList);
//    printf("\nList setelah DelAll: ");
//    PrintInfo(MyList);
//
//    return 0;
//}


int main() {
	
	/* Kamus Lokal */
	List MyList;
	infotype isi;
	address P, Prec;

	/* Program */
	CreateList (&MyList);	//List sudah terbentuk, digunakan untuk memanipulasi elemen
	printf("List dibuat.\n");
    PrintInfo(MyList);
	
	//aksi mahasiswa untuk implementasi studi kasus
    
    // Menambahkan elemen pertama
    InsVFirst(&MyList, 10);
    InsVFirst(&MyList, 5);
    InsVLast(&MyList, 15);
    printf("List setelah penambahan elemen:\n");
    PrintInfo(MyList);
    
    // Mencari elemen dalam list
    Prec = Search(MyList, 10);
    if (Prec != Nil) {
        printf("Elemen 10 ditemukan.\n");
    } else {
        printf("Elemen 10 tidak ditemukan.\n");
    }
    
    // Menyisipkan elemen setelah elemen tertentu
    P = Alokasi(12);
    if (P != Nil && Prec != Nil) {
        InsertAfter(&MyList, P, Prec);
    }
    printf("List setelah penyisipan elemen 12 setelah 10:\n");
    PrintInfo(MyList);
    
    // Menghapus elemen pertama
    DelVFirst(&MyList, &isi);
    printf("Elemen pertama %d dihapus.\n", isi);
    PrintInfo(MyList);
    
    // Menghapus elemen tertentu
    DelP(&MyList, 10);
    printf("List setelah menghapus elemen 10:\n");
    PrintInfo(MyList);
    
    // Menghapus elemen terakhir
    DelVLast(&MyList, &isi);
    printf("Elemen terakhir %d dihapus.\n", isi);
    PrintInfo(MyList);
    
    // Menghapus semua elemen
    DelAll(&MyList);
    printf("List setelah semua elemen dihapus:\n");
    PrintInfo(MyList);
    
    /* Finishing */
	
	//Pastikan List di Dealokasi setelah manipulasi elemen selesai
    
    return 0;
}

