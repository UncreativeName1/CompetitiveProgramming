#include <iostream>
using namespace std;

int rows, columns, whenTheImposterIsSus = 0;
int height[1005][1005];

void checkSurroundings(int row, int column) {
    if (row > 0) {
        if (height[row - 1][column] < height[row][column]) {
            whenTheImposterIsSus += (height[row][column] - height[row - 1][column]);
        }
    }
    if (row < rows - 1) {
        if (height[row + 1][column] < height[row][column]) {
            whenTheImposterIsSus += (height[row][column] - height[row + 1][column]);
        }
    }
    if (column > 0) {
        if (height[row][column - 1] < height[row][column]) {
            whenTheImposterIsSus += (height[row][column] - height[row][column - 1]);
        }
    }
    if (column < columns - 1) {
        if (height[row][column + 1] < height[row][column]) {
            whenTheImposterIsSus += (height[row][column] - height[row][column + 1]);
        }
    }
}

int main() {
    cin >> rows >> columns;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> height[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            checkSurroundings(i, j);
        }
    }
    whenTheImposterIsSus += (rows * columns);
    cout << whenTheImposterIsSus << endl;
    return 0;
}