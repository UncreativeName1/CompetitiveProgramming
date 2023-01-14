#include <iostream>

using namespace std;

// 1 = BLACK
// 2 = WHITE

void makeMove(int board[][8], const int point[], int placed) {
	int check;
	int shift[8][2];
	int shiftIndex = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 2; j++) {
			shift[i][j] = 0;
		}
	}
	board[point[0]][point[1]] = placed;
	// If placed = 1 (black), then check = 2 (white). Also works opposite.
	check = (placed % 2) + 1;
	// i & point[0] are rows
	for (int i = point[0] - 1; i <= point[0] + 1; i++) {
		if (i >= 0 && i <= 7) {
			// j & point[1] are columns
			for (int j = point[1] - 1; j <= point[1] + 1; j++) {
				if (j >= 0 && j <= 7) {
					if (board[i][j] == check) {
						shift[shiftIndex][0] = i - point[0];
						shift[shiftIndex][1] = j - point[1];
						shiftIndex++;
					}
				}
			}
		}
	}

    int pointsToChange[8][2];
    int changeIndex = 0;
    int i = 1;
    int temp = 0;
	for (int h = 0; h < shiftIndex; h++) {
		changeIndex = 0;
		i = 1;
		temp = 0;
		for (int j = 0; j < 8; j++) {
    		for (int k = 0; k < 2; k++) {
    			pointsToChange[j][k] = 8;
    		}
    	}
		while (
    		(point[0] + i * shift[h][0] <= 7) && 
    		(point[0] + i * shift[h][0] >= 0) && 
    		(point[1] + i * shift[h][1] <= 7) && 
    		(point[1] + i * shift[h][1] >= 0)
		) {
			if (board[point[0] + i * shift[h][0]][point[1] + i * shift[h][1]] == check) {
				pointsToChange[changeIndex][0] = point[0] + i * shift[h][0];
				pointsToChange[changeIndex][1] = point[1] + i * shift[h][1];
				changeIndex++;
			} else {
			    temp = 1;
			    break;
			}
			i++;
		}
    	if (temp) {
    		if (board[point[0] + i * shift[h][0]][point[1] + i * shift[h][1]] == placed) {
    			for (int j = 0; j < changeIndex; j++) {
    				board[pointsToChange[j][0]][pointsToChange[j][1]] = placed;
    			}
    		}
    	}
	}
}

int countColor(const int board[][8], int color) {
	int numOfColor = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == color) {
				numOfColor++;
			}
		}
	}
	return numOfColor;
}

int main() {
	int board[8][8];
	char boardNum;
	int numMoves, totalPieces;
	cin >> boardNum >> numMoves;
	int moves[numMoves][2];
	for (int i = 0; i < numMoves; i++) {
		cin >> moves[i][0] >> moves[i][1];
		moves[i][0]--;
		moves[i][1]--;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = 0;
		}
	}
	
	// Using the board letter, determine the appropriate board to set pieces to.
	switch (boardNum) {
		case 'a':
			for (int i = 3; i < 5; i++) {
				board[i][i] = 2;
				board[i][7 - i] = 1;
			}
			totalPieces = 4 + numMoves;
			break;
		case 'b':
			for (int i = 0; i < 8; i++) {
				board[i][i] = 1;
				board[i][7 - i] = 2; 
			}
			totalPieces = 16 + numMoves;
			break;
		case 'c':
			for (int i = 0; i < 8; i++) {
				board[i][2] = 1;
				board[i][3] = 1;
				board[i][4] = 2;
				board[i][5] = 2;
			}
			totalPieces = 32 + numMoves;
			break;
	}

	// Now that the board is set, begin moves.
	for (int i = 0; i < numMoves; i++) {
		makeMove(board, moves[i], (i % 2) + 1);
	}

	// All moves are made.
	cout << countColor(board, 1) << " " << countColor(board, 2) << endl;

    return 0;
}

