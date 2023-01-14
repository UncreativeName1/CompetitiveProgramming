#include <iostream>
#define ll long long
#define ARR_LENGTH(array)        sizeof(array)/sizeof(*array)
#define SET_ARR(array, value)     for (unsigned int INDEX = 0; INDEX < ARR_LENGTH(array); INDEX++) array[INDEX] = value;
#define PRINT_ARR(array)        for (unsigned int INDEX = 0; INDEX < ARR_LENGTH(array); INDEX++) { cout << array[INDEX] << " "; } cout << endl;
using namespace std;

/*
int inArray(int numToCheck, int array[]) {
	for (int i = 0; i < (int)ARR_LENGTH(array); i++) {
		if (array[i] == numToCheck) {
			return 1;
		}
	}
	return 0;
}
*/

int main() {
	ios_base::sync_with_stdio(false);

	int valuesVisited[1000001] = {0};
	int rows, columns, next = 0, current = 0, currentCellValue = 0;
	cin >> rows >> columns;
	int cells[rows+1][columns+1];
	int totalCells = rows * columns;
	
	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= columns; j++) {
			cin >> cells[i][j];
		}
	}

	// Queue where the adjacent nodes to the current node get added to it. 
	int valuesQueue[totalCells];
	SET_ARR(valuesQueue, -1);

	valuesQueue[next] = cells[1][1];
	next++;

	// If first cell directly leads to final cell.
	if (valuesQueue[current] == totalCells) {
		cout << "yes" << endl;
		return 0;
	}

	// For each member of the queue, look for its adjacent neighbor nodes in a BFS search.
	do {
		for (int i = 1; i <= rows; i++) {
			// The value must be split into 2 factors (x,y) as coordinates of a cell, so if the row cannot evenly divide there's no point in checking.
			if (valuesQueue[current] % i == 0) {
				for (int j = 1; j <= columns; j++) {
					// Check for adjacent neighbor nodes.
					if (i * j == valuesQueue[current]) {
						currentCellValue = cells[i][j];
						// If you reach final value.
						if (currentCellValue == totalCells) {
							cout << "yes" << endl;
							return 0;
						}
						// If the value of this neighbor node was already visited before, "end" this branch of the search. 
						// Otherwise add its value into the queue to be searched for its neighbors and into the array of all values that were visited.
						if (!valuesVisited[currentCellValue]) {
							valuesQueue[next] = currentCellValue;
							next++;
							valuesVisited[currentCellValue] = 1;
						}
						// If the currently checked value is the largest factor, stop checking since there are no more neighbors. 
						if ((j + 1) > (valuesQueue[current] / i)) break;
					}
				}
			}
		}
		current++;
	} while (valuesQueue[current] >= 0); // if there is no more to check, the current will "catch up" with the queue adding point.

	cout << "no" << endl;
	return 0;
}


// 2
// 2
// 2 77
// 55 3