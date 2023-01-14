/*
ID: beetwan1
LANG: C
PROG: friday
*/
#include <stdio.h>
#include <stdlib.h>

const int daysForwardPerMonth[12] = {3, 3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2};
const int daysForwardLeapYearPerMonth[12] = {3, 3, 1, 3, 2, 3, 2, 3, 3, 2, 3, 2};

int leapYear(int year) {
	int isLeapYear = 0;
	if (year % 4 == 0) {
		isLeapYear = 1;
		if (year % 100 == 0) {
			isLeapYear = 0;
			if (year % 400 == 0) {
				isLeapYear = 1;
			}
		}
	}
	return isLeapYear;
}

int numOfFriday13(int dayOfLastYear, int year, int total13[]) {
	int isLeapYear = 0;
	int friday13Counter = 0;
	isLeapYear = leapYear(year);
	// printf("isLeapYear: %d\n", isLeapYear);
	for (int i = 0; i < 12; i++) {
		if (isLeapYear == 0) {
			dayOfLastYear += daysForwardPerMonth[i];
		} else {
			dayOfLastYear += daysForwardLeapYearPerMonth[i];
		}
		// printf("%d -> ", dayOfLastYear);
		while (dayOfLastYear > 7) {
			dayOfLastYear -= 7;
		}
		// printf("%d\n", dayOfLastYear);
		total13[dayOfLastYear - 1]++;
	}
	return dayOfLastYear;
}

void main () {
    FILE *fin  = fopen ("friday.in", "r");
    FILE *fout = fopen ("friday.out", "w");

    int N, dayOfLastYear = 3;
    int total13[7] = {0, 0, 0, 0, 0, 0, 0};
    fscanf(fin, "%d", &N);

    for (int i = 1900; i < 1900 + N; i++) {
    	dayOfLastYear = numOfFriday13(dayOfLastYear, i, total13);
    }

    fprintf(fout, "%d %d %d %d %d %d %d\n", total13[5], total13[6], total13[0], total13[1], total13[2], total13[3], total13[4]);

    exit (0);
}



