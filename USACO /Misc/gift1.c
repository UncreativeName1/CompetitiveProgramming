/*
ID: beetwan1
LANG: C
PROG: gift1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int indexOfString(int numOfStrings, const char stringArray[][15], char string[15]) {
    int position = -1;
    for (int i = 0; i < numOfStrings; i++) {
        position = i;
        if (strcmp(string, stringArray[i]) == 0) {
            break;
        }
    }
    return position;
}

void
main () {
    FILE *fin  = fopen ("gift1.in", "r");
    FILE *fout = fopen ("gift1.out", "w");
    int numOfPeople;
    fscanf(fin, "%d", &numOfPeople);
    printf("numOfPeople: %d\n");
    // length of numOfPeople, each person must have max 14 length name + null character
    char names[numOfPeople][15];
    char current[15];
    int currentIndex;
    int giveInfo[2];
    int netGain[numOfPeople];
    for (int i = 0; i < numOfPeople; i++) {
        netGain[i] = 0;
    }
    for (int i = 0; i < numOfPeople; i++) {
        fscanf(fin, "%s", names[i]);
    }
    for (int i = 0; i < numOfPeople; i++) {
        fscanf(fin, "%s", current);
        currentIndex = indexOfString(numOfPeople, names, current);
        fscanf(fin, "%d", &giveInfo[0]);
        fscanf(fin, "%d", &giveInfo[1]);
        if (giveInfo[1] > 0) {
            netGain[currentIndex] += (giveInfo[0] % giveInfo[1]);
        }
        netGain[currentIndex] -= giveInfo[0];
        printf("netGain[%d] = %d\n", currentIndex, netGain[currentIndex]);
        for (int i = 0; i < giveInfo[1]; i++) {
            fscanf(fin, "%s", current);
            currentIndex = indexOfString(numOfPeople, names, current);
            netGain[currentIndex] += (giveInfo[0] / giveInfo[1]);
        }
    }
    
    for (int i = 0; i < numOfPeople; i++) {
        fprintf(fout, "%s %d\n", names[i], netGain[i]);
    }
    
}

