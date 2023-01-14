#include <iostream>
using namespace std;

char grid[55][55];

int check(bool row, int index, int start, int end) {
    bool valid = true;
    if (row) {
        for (int i = start; i <= end; i++) {
            if (grid[index][i] == 'H') {
                valid = false;
                break;
            }
        }
    } else {
        for (int i = start; i <= end; i++) {
            if (grid[i][index] == 'H') {
                valid = false;
                break;
            }
        }
    }
    if (start == end) valid = false;
    return valid;
}

int oneTurn(int n) {
    int paths = 0;
    if (check(true, 0, 0, n - 1) && check(false, n - 1, 0, n - 1)) {
        paths++;
    }
    if (check(false, 0, 0, n - 1) && check(true, n - 1, 0, n - 1)) {
        paths++;
    }
    return paths;
}

int twoTurn(int n) {
    int paths = 0;
    for (int i = 1; (grid[0][i] == '.') && (i < n - 1); i++) {
        if (check(false, i, 0, n - 1) && check(true, n - 1, i, n - 1)) {
            paths++;
        }
    }
    for (int i = 1; (grid[i][0] == '.') && (i < n - 1); i++) {
        if (check(true, i, 0, n - 1) && check(false, n - 1, i, n - 1)) {
            paths++;
        }
    }
    paths += oneTurn(n);
    return paths;
}

int threeTurn(int n) {
    int paths = 0;
    for (int i = 1; (grid[0][i] == '.') && (i < n - 1); i++) {
        for (int j = 1; (grid[j][i] == '.') && (j < n - 1); j++) {
            if (check(true, j, i, n - 1) && check(false, n - 1, j, n - 1)) {
                paths++;
            }
        }
    }
    for (int i = 1; (grid[i][0] == '.') && (i < n - 1); i++) {
        for (int j = 1; (grid[i][j] == '.') && (j < n - 1); j++) {
            if (check(false, j, i, n - 1) && check(true, n - 1, j, n - 1)) {
                paths++;
            }
        }
    }
    paths += twoTurn(n);
    return paths;
}

int main() {
    int t = 0, n = 0, numTurns = 0, paths = -1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> numTurns;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> grid[j][k];
            }
        }

        switch (numTurns) {
            case 1:
                paths = oneTurn(n);
                break;
            case 2:
                paths = twoTurn(n);
                break;
            case 3:
                paths = threeTurn(n);
                break;
        }
        cout << paths << endl;
    }

    return 0;
}
