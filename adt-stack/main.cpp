#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
	int number;
    printf("Masukkan bilangan desimal: ");
    scanf("%d", &number);
    
    if (number < 0) {
        printf("Bilangan harus positif!\n");
    } else if (number == 0) {	
        printf("Biner: 0\n");
    } else {
        Stack S;
	    CreateEmpty(&S);
	    
	    while (number > 0) {
	        Push(&S, number % 2);
	        number /= 2;
//	        PrintStack(S);
	    }
	    
	    printf("Biner: ");
	    
	    while (!IsEmpty(S)) {
	        int bit;
	        Pop(&S, &bit);
	        printf("%d", bit);
	    }
	    printf("\n");
    }
    
	return 0;
}

