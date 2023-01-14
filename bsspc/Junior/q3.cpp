#include <iostream>
using namespace std;

char grid[3][3];

bool checkIfSus() {
    if (grid[0][0] == 'O' && grid[1][0] == 'O' && grid[2][0] == 'O') return false;
    if (grid[0][2] == 'O' && grid[1][2] == 'O' && grid[2][2] == 'O') return false;
    if (grid[0][1] == 'O') {
        if (grid[0][0] == 'O' && grid[0][2] == 'O') return false;
        if (grid[1][1] == 'O' && grid[2][1] == 'O') return false;
    }
    if (grid[1][1] == 'O') {
        if (grid[0][0] == 'O' && grid[2][2] == 'O') return false;
        if (grid[0][2] == 'O' && grid[2][0] == 'O') return false;
        if (grid[1][0] == 'O' && grid[1][2] == 'O') return false;
    }
    if (grid[2][1] == 'O') {
        if (grid[2][0] == 'O' && grid[2][2] == 'O') return false;
    }
    return true;
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                cin >> grid[r][c];
            }
        }
        if (!checkIfSus()) {
            cout << "Lose" << endl;
            continue;
        }
        if (grid[0][0] == '-') {
            if (grid[0][1] == 'X' && grid[0][2] == 'X') {
                cout << "Win" << endl;
                continue;
            }
            if (grid[1][0] == 'X' && grid[2][0] == 'X') {
                cout << "Win" << endl;
                continue;
            }
            if (grid[1][1] == 'X' && grid[2][2] == 'X') {
                cout << "Win" << endl;
                continue;
            }
        }
        if (grid[0][1] == '-') {
            if (grid[0][0] == 'X' && grid[0][2] == 'X') {
                cout << "Win" << endl;
                continue;
            }
            if (grid[1][1] == 'X' && grid[2][1] == 'X') {
                cout << "Win" << endl;
                continue;
            }
        }
        if (grid[0][2] == '-') {
            if (grid[0][1] == 'X' && grid[0][0] == 'X') {
                cout << "Win" << endl;
                continue;
            }
            if (grid[1][2] == 'X' && grid[2][2] == 'X') {
                cout << "Win" << endl;
                continue;
            }
            if (grid[1][1] == 'X' && grid[2][0] == 'X') {
                cout << "Win" << endl;
                continue;
            }
        }
        if (grid[1][0] == '-') {
            if (grid[0][0] == 'X' && grid[2][0] == 'X') {
                cout << "Win" << endl;
                continue;
            }
            if (grid[1][1] == 'X' && grid[1][2] == 'X') {
                cout << "Win" << endl;
                continue;
            }
        }
        if (grid[1][1] == '-') {
            if (grid[0][1] == 'X' && grid[2][1] == 'X') {
                cout << "Win" << endl;
                continue;
            }
            if (grid[1][0] == 'X' && grid[1][2] == 'X') {
                cout << "Win" << endl;
                continue;
            }
            if (grid[0][0] == 'X' && grid [2][2] =='X') {
                cout << "Win" << endl;
                continue;
            }
            if (grid[0][2] == 'X' && grid [2][0] =='X') {
                cout << "Win" << endl;
                continue;
            }
        }
        if (grid[1][2] == '-') {
            if (grid[0][2] == 'X' && grid[2][2] == 'X') {
                cout << "Win" << endl;
                continue;
            }
            if (grid[1][0] == 'X' && grid[1][1] == 'X') {
                cout << "Win" << endl;
                continue;
            }
        }
        if (grid[2][0] == '-') {
            if (grid[0][0] == 'X' && grid[1][0] == 'X') {
                cout << "Win" << endl;
                continue;
            }
            if (grid[2][1] == 'X' && grid[2][2] == 'X') {
                cout << "Win" << endl;
                continue;
            }
            if (grid[1][1] == 'X' && grid[0][2] == 'X') {
                cout << "Win" << endl;
                continue;
            }
        }
        if (grid[2][1] == '-') {
            if (grid[0][1] == 'X' && grid[1][1] == 'X') {
                cout << "Win" << endl;
                continue;
            }
            if (grid[2][0] == 'X' && grid[2][2] == 'X') {
                cout << "Win" << endl;
                continue;
            }
        }
        if (grid[2][2] == '-') {
            if (grid[2][0] == 'X' && grid[2][1] == 'X') {
                cout << "Win" << endl;
                continue;
            }
            if (grid[0][2] == 'X' && grid[1][2] == 'X') {
                cout << "Win" << endl;
                continue;
            }
            if (grid[0][0] == 'X' && grid[1][1] == 'X') {
                cout << "Win" << endl;
                continue;
            }
        }
        cout << "Lose" << endl;
    }
    return 0;
}