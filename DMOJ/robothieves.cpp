#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#define ll long long
#define ARR_LENGTH(array) sizeof(array)/sizeof(*array)
#define SET_ARR(array, value) for (unsigned int INDEX = 0; INDEX < ARR_LENGTH(array); INDEX++) array[INDEX] = value;
#define INDEX(a, b) columns * a + b
using namespace std;

// not working: sets all to -1, also check for conveyor moving into wall.

int main() {
	ios_base::sync_with_stdio(false);
    // cout << "hello" << endl;
    int rows, columns;
    int startCell;
    cin >> rows >> columns;
    char cells[rows * columns];
    SET_ARR(cells, 46);
    // cout << rows << columns << endl;

    int movesToReach[rows * columns];
    SET_ARR(movesToReach, -3);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> cells[INDEX(i, j)];
        }
    }
    
    vector<int> cameras;
    vector<int> openSpaces;
    vector<int> conveyors;
    // Setting up default values for amount of moves to reach each node. 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            switch (cells[INDEX(i, j)]) {
                case 'S':
                    startCell = INDEX(i, j);
                    movesToReach[INDEX(i, j)] = 0;
                    openSpaces.push_back(INDEX(i, j));
                    break;

                case 'W':
                    movesToReach[INDEX(i, j)] = -1;
                    break;
                
                case 'C':
                    movesToReach[INDEX(i, j)] = -1;
                    // cameras.push_back(i);
                    // cameras.push_back(j);
                    // Invalidating all spaces seen by camera.
                    // cout << "CAMERA: (" << i << "," << j << ")"<< endl; 
                    // cout << "------" << endl;
                    for (int a = i + 1; a < rows; a++) {
                        // cout << "--CHECKING: (" << a << "," << j << ") = " << cells[INDEX(a,j)] << endl;
                        if (cells[INDEX(a, j)] == 'W') break;
                        if ((cells[INDEX(a, j)] == 'L') || (cells[INDEX(a, j)] == 'R') || (cells[INDEX(a, j)] == 'U') || (cells[INDEX(a, j)] == 'D')) continue;
                        // cout << "^CAMERA SPOTS: (" << a << "," << j << ")"<< endl; 
                        movesToReach[INDEX(a, j)] = -1;
                    }
                    // cout << "------" << endl;
                    for (int a = i - 1; a >= 0; a--) {
                        // cout << "--CHECKING: (" << a << "," << j << ") = " << cells[INDEX(a,j)] << endl;
                        if (cells[INDEX(a, j)] == 'W') break;
                        if ((cells[INDEX(a, j)] == 'L') || (cells[INDEX(a, j)] == 'R') || (cells[INDEX(a, j)] == 'U') || (cells[INDEX(a, j)] == 'D')) continue;
                        // cout << "^CAMERA SPOTS: (" << a << "," << j << ")"<< endl; 
                        movesToReach[INDEX(a, j)] = -1;
                    }
                    // cout << "------" << endl;
                    for (int a = j + 1; a < columns; a++) {
                        // cout << "--CHECKING: (" << i << "," << a << ") = " << cells[INDEX(i,a)] << endl;
                        if (cells[INDEX(i, a)] == 'W') break;
                        if ((cells[INDEX(i, a)] == 'L') || (cells[INDEX(i, a)] == 'R') || (cells[INDEX(i, a)] == 'U') || (cells[INDEX(i, a)] == 'D')) continue;
                        // cout << "^CAMERA SPOTS: (" << i << "," << a << ")"<< endl; 
                        movesToReach[INDEX(i, a)] = -1;
                    }
                    // cout << "------" << endl;
                    for (int a = j - 1; a >= 0; a--) {
                        // cout << "--CHECKING: (" << i << "," << a << ") = " << cells[INDEX(i,a)] << endl;
                        if (cells[INDEX(i, a)] == 'W') break;
                        if ((cells[INDEX(i, a)] == 'L') || (cells[INDEX(i, a)] == 'R') || (cells[INDEX(i, a)] == 'U') || (cells[INDEX(i, a)] == 'D')) continue;
                        // cout << "^CAMERA SPOTS: (" << i << "," << a << ")"<< endl; 
                        movesToReach[INDEX(i, a)] = -1;
                    }
                    // cout << "------" << endl;
                    break;
                
                case '.':
                    if (movesToReach[INDEX(i,j)] != -1) {
                        movesToReach[INDEX(i, j)] = 0;
                        openSpaces.push_back(INDEX(i, j));
                    }
                    break;
                
                default:
                    if (movesToReach[INDEX(i,j)] != -1) {
                        movesToReach[INDEX(i, j)] = -2;
                        conveyors.push_back(INDEX(i, j));
                    }
                    break;
            }
        }
    }
    /*
    -3 default
    -2 conveyor
    -1 camera, its spotted cells, walls
    0 open spaces
    */

    // for (int f = 0; f < rows; f++) {
    //     for (int g = 0; g < columns; g++) {
    //         cout << cells[INDEX(f, g)] << " ";
    //     }
    //     cout << endl;
    // }
    // for (int f = 0; f < rows; f++) {
    //     for (int g = 0; g < columns; g++) {
    //         if (movesToReach[INDEX(f, g)] >= 0) {
    //             cout << " ";
    //         }
    //         cout << movesToReach[INDEX(f, g)];
    //     }
    //     cout << endl;
    // }

    // If the start was in range of a camera, nothing is possible.
    if (movesToReach[startCell] == -1) {
        SET_ARR(movesToReach, -1);
    } else {
        int adj[rows * columns][4];
        for (int i = 0; i < rows * columns; i++) {
            SET_ARR(adj[i], -1);
        }

        // Creating adjacency list for open cells.
        for (auto i: openSpaces) {
            int k = 0;
            // Check if the adjacent node was a "." or conveyor. We don't need to check for out of bounds array since the wall (-1) border never passes the check for 0 and -2.
            // Cell above current.
            if (movesToReach[i - columns] == 0 || movesToReach[i - columns] == -2) {
                adj[i][k] = i - columns;
                k++;
            }
            // Cell below current.
            if (movesToReach[i + columns] == 0 || movesToReach[i + columns] == -2) {
                adj[i][k] = i + columns;
                k++;
            }
            // Cell left of current.
            if (movesToReach[i - 1] == 0 || movesToReach[i - 1] == -2) {
                adj[i][k] = i - 1;
                k++;
            }
            // Cell right of current.
            if (movesToReach[i + 1] == 0 || movesToReach[i + 1] == -2) {
                adj[i][k] = i + 1;
                k++;
            }
        }

        // Creating adjacency list for conveyors.
        for (auto i: conveyors) {
            // Conveyors are only adjacent to the immediate cell in the direction they travel in.
            switch (cells[i]) {
                case 'L':
                    if (movesToReach[i - 1] == 0 || movesToReach[i - 1] == -2) {
                        adj[i][0] = i - 1;
                    }
                    break;
                
                case 'R':
                    if (movesToReach[i + 1] == 0 || movesToReach[i + 1] == -2) {
                        adj[i][0] = i + 1;
                    }
                    break;

                case 'U':
                    if (movesToReach[i - columns] == 0 || movesToReach[i - columns] == -2) {
                        adj[i][0] = i - columns;
                    }
                    break;
                
                case 'D':
                    if (movesToReach[i + columns] == 0 || movesToReach[i + columns] == -2) {
                        adj[i][0] = i + columns;
                    }
                    break;
                
                default:
                    break;
            }
            adj[i][1] = -2;
        }

        // for (int f = 0; f < rows * columns; f++) {
        //     cout << f << ": ";
        //     for (int g = 0; g < 4; g++) {
        //         cout << adj[f][g] << " ";
        //         if (adj[f][g] < 0) {
        //             cout << "END";
        //             break;
        //         }
        //     }
        //     cout << endl;
        // }

        // doesnt work because if (adj[current][1] == -2) {} on line 230 is checking node->conveyor interaction and not continuing. continue is currently when you are already on a conveyor node (wrong).
        // should check for node->conveyor and also continue until node->conveyor->...->node.
        // BFS to find distance
        queue<int> q, subq;
        int invalid = 0, visit = 0;
        int visited[rows * columns]; // relevant for visited all open spaces or conveyors.
        SET_ARR(visited, 0);
        q.push(startCell);
        visited[startCell] = 1;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            invalid = 0;
            for (auto next: adj[current]) {
                visit = 0;
                if (next < 0) break;
                if (visited[next]) continue;
                visited[next] = 1;
                // cout << current << " visiting " << next << "." << endl;
                // If a conveyor is reached.
                if (adj[next][1] == -2) {
                    // cout << "Checking for non-conveyor: adj[next=" << next << "][1] = " << adj[next][1] << endl;
                    // Finding the next non-conveyor node.
                    subq.push(adj[next][0]);
                    while (!subq.empty()) {
                        // The adjacent nodes to the node (if it's a conveyor it will only have 1 adjacent maximum)
                        next = subq.front();
                        subq.pop();
                        if (next < 0) {
                            invalid = 1;
                            break;
                        }
                        // cout << "Visited " << next << ": " << visited[next] << endl;
                        if (visited[next]) {
                            visit = 1;
                            break;
                        }
                        visited[next] = 1;
                        // If it's still a conveyor, queue the node the conveyor is adjacent to.
                        if (adj[next][1] == -2) {
                            subq.push(adj[next][0]);
                        }
                    }
                }
                if (invalid) break;
                if (visit) continue;
                movesToReach[next] = movesToReach[current] + 1;
                // cout << current << " visiting " << next << ". Total moves made is now " << movesToReach[next] << endl;
                q.push(next);
            }
        }
    }

    // for (int f = 0; f < rows; f++) {
    //     for (int g = 0; g < columns; g++) {
    //         cout << cells[INDEX(f, g)] << " ";
    //     }
    //     cout << endl;
    // }
    // for (int f = 0; f < rows; f++) {
    //     for (int g = 0; g < columns; g++) {
    //         if (movesToReach[INDEX(f, g)] >= 0) {
    //             cout << " ";
    //         }
    //         cout << movesToReach[INDEX(f, g)];

    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < rows * columns; i++) {
        if (cells[i] == '.') {
            if (movesToReach[i] == 0) {
                cout << "-1" << endl;
            } else {
                cout << movesToReach[i] << endl;
            }
        }
    }

	return 0;
}

// g++ -std=c++20 -g robothieves.cpp -o robothieves