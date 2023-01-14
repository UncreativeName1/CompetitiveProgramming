/*
ID: beetwan1
LANG: C
PROG: beads
*/
#include <stdio.h>
#include <stdlib.h>

int maxBeads(const char beads[], int N, char reqColor, char otherColor) {
	int j = 0, numOfBeads = 0, currentMax = 0;
	for (int i = 0; i < N; i++) {
		if (beads[i] != otherColor) {
			j = i; 
			while (beads[j] != otherColor && numOfBeads < N) {
				numOfBeads++;
				j++;
				if (j >= N) {
					j = 0;
				}
			}
			while (beads[j] != reqColor && numOfBeads < N) {
				numOfBeads++;
				j++;
				if (j >= N) {
					j = 0;
				}

			}
			if (numOfBeads > currentMax) {
				currentMax = numOfBeads;
			}
			numOfBeads = 0;
		}
	}

	return currentMax;
}

void main () {
    FILE *fin  = fopen ("beads.in", "r");
    FILE *fout = fopen ("beads.out", "w");

    int maxRedStart, maxBlueStart;
    int N;
    fscanf(fin, "%d", &N);

    char beads[N+1];
    fscanf(fin, "%s", beads);

    maxBlueStart = maxBeads(beads, N, 'b', 'r');
    maxRedStart = maxBeads(beads, N, 'r', 'b');

    if (maxBlueStart > maxRedStart) {
    	fprintf(fout, "%d\n", maxBlueStart);
    } else {
    	fprintf(fout, "%d\n", maxRedStart);
    }

    exit (0);
}





