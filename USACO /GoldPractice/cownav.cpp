#include <iostream>
#include <fstream>
#include <queue>
#define input cin // inFile
#define output cout // outFile
using namespace std;

const int debug = 1;

int grid[21][21]; // the grid, 1 = empty space, 0 = haybale, max is 20x20
int visited[21][21][21][21][4] = {0}; // 20 possible x and y coordinates for both cows, + 4 possible directions

// cow1 = one facing up at start
// cow2 = one facing right at start

/*
Directions: (adding = clockwise)
0: Cow1 forward, Cow2 right
1: Cow1 right, Cow2 backward
2: Cow1 backward, Cow2 left
3: Cow1 left, Cow2 forward
*/

/*
4 * * * *
3 * * * *
2 * * * *
1 * * * *
  1 2 3 4
*/

struct Position {
    int x1; // cow 1 x position
    int y1; // cow 1 y position
    int x2; // cow 2 x position
    int y2; // cow 2 y position
    int direction1; // direction cow1 
    int numMoves;

    Position(int x1, int y1, int x2, int y2, int direction1) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->direction1 = direction1;
        this->numMoves = 0;
    }
};

int xOffset[4] = {0, 1, 0, -1};
int yOffset[4] = {1, 0, -1, 0};

int validate(int x, int y, int n) {
    if (x >= 0 && x <= n - 1 && y >= 0 && y <= n - 1) {
        if (grid[y][x] == 1) {
            return 1;
        }
    }
    return 0;
}

int checkVisited(Position position) {
    return visited[position.x1][position.y1][position.x2][position.y2][position.direction1];
}

void setVisited(Position position) {
    visited[position.x1][position.y1][position.x2][position.y2][position.direction1] = 1;
}

int main() {
    ifstream inFile("cownav.in");
    ofstream outFile("cownav.out");

    int n; // length of side of square grid
    input >> n;

    char temp; // Temporary letter to get the state of each cell in the grid

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            input >> temp;
            if (temp == 'E') {
                grid[n - i][j] = 1;
            } else {
                grid[n - i][j] = 0;
            }
        }
    }
    // grid is now fully set up
    if (debug) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    // final position is (n, n, n, n, anything)

    // BFS
    Position startPosition(0, 0, 0, 0, 0);
    Position currentPosition(0, 0, 0, 0, 0);
    queue<Position> q;
    q.push(startPosition);
    while (!q.empty()) {
        currentPosition = q.front();
        Position newPosition = currentPosition;
        q.pop();
        setVisited(currentPosition);
        if (debug) {
            cout << "[MOVE NUMBER " << currentPosition.numMoves << "]" << endl;
            cout << "cow 1 position: (" << currentPosition.y1 << ", " << currentPosition.x1 << "), direction: " << currentPosition.direction1 << endl;
            cout << "cow 2 position: (" << currentPosition.y2 << ", " << currentPosition.x2 << "), direction: " << (currentPosition.direction1 + 1) % 4 << endl;
        }
        if (currentPosition.x1 == n - 1 && currentPosition.y1 == n - 1 && currentPosition.x2 == n - 1 && currentPosition.y2 == n - 1) {
            if (debug) cout << "fully reached end" << endl;
            break;
        }

        // probably a problem here
        // Move in the direction its facing
        // if move stays inside grid + cow is not at the end cell
        if (validate(newPosition.x1 + xOffset[newPosition.direction1], newPosition.y1 + yOffset[newPosition.direction1], n) && (newPosition.x1 != n - 1 && newPosition.y1 != n - 1)) {
            newPosition.x1 += xOffset[newPosition.direction1];
            newPosition.y1 += yOffset[newPosition.direction1];
        } 
        if (validate(newPosition.x2 + xOffset[(newPosition.direction1 + 1) % 4], newPosition.y2 + yOffset[(newPosition.direction1 + 1) % 4], n) && (newPosition.x2 != n - 1 && newPosition.y2 != n - 1)) {
            newPosition.x2 += xOffset[(newPosition.direction1 + 1) % 4];
            newPosition.y2 += yOffset[(newPosition.direction1 + 1) % 4];
        } 
        if (!checkVisited(newPosition)) {
            newPosition.numMoves++;
            q.push(newPosition);
        }
        newPosition = currentPosition; // reset

        // Turning Clockwise
        newPosition.direction1 = (currentPosition.direction1 + 1) % 4;
        if (!checkVisited(newPosition)) {
            newPosition.numMoves++;
            q.push(newPosition);
        }
        newPosition = currentPosition; // reset

        // Turning Counterclockwise
        newPosition.direction1 = (currentPosition.direction1 + 3) % 4;
        if (!checkVisited(newPosition)) {
            newPosition.numMoves++;
            q.push(newPosition);
        }
    }
    output << currentPosition.numMoves << endl;

    return 0;
}