#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
    Queue Q;
    CreateQueue(&Q);
    int choice, counter = 1, served;

    do {
        printf("\nMenu:\n");
        printf("1. Ambil antrian\n");
        printf("2. Proses antrian\n");
        printf("3. Cetak antrian\n");
        printf("4. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (is_Full(Q)) {
				    printf("Antrian penuh!\n");
				} else {
				    EnQueue(&Q, counter);
				    printf("Nomor antrian %d diambil.\n", counter);
				    PrintInfo(Q);
				    counter++;
				}
                break;
            case 2:
            	deQueue(&Q, &served);
            	printf("Nomor antrian %d sudah diproses.\n", served);
                break;
            case 3:
                PrintInfo(Q);
                break;
            case 4:
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid, coba lagi.\n");
        }
    } while (choice != 4);

    return 0;
}



