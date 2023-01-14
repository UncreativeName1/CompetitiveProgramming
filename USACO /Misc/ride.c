/*
ID: beetwan1
LANG: C
PROG: ride
*/
#include <stdio.h>
#include <stdlib.h>

int asciiProduct(char string[], int length) {
    int product = 1;
    for (int i = 0; i < length; i++) {
        printf("String[i] = %d, ", string[i]);
        if (string[i] == 0) {
            break;
        }
        if (string[i] != 0) {
            product *= (string[i] - 64);
            printf("New product: %d, String value multiplier: %d", product, string[i] - 64);
        }
        printf("\n");
    }
    return product;
}

void main () {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    char cometName[8];
    char groupName[8];
    int product1, product2;
    
    fscanf(fin, "%s", cometName);
    fscanf(fin, "%s", groupName);
    
    product1 = asciiProduct(cometName, 8);
    product2 = asciiProduct(groupName, 8);
    
    printf("%d, %d\n", product1, product2);
    if (product1 % 47 == product2 % 47) {
        fprintf(fout, "GO\n");
    } else {
        fprintf(fout, "STAY\n");
    }
    exit (0);
}
