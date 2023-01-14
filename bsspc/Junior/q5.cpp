#include <iostream>
#include <utility>
#define pii pair<int, int>
using namespace std;

char grid[10][10];
int rows, columns;
bool currentVisited[10][10] = {0};
bool allVisited[10][10] = {0};

pii start;
pii finish;

void imposterFirstSearch(pii node) {
    if (node == finish) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (currentVisited[i][j]) allVisited[i][j] = currentVisited[i][j];
            }
        }
        return;
    }
    pii newNode = node;
    if (node.first > 0) {
        newNode.first -= 1;
        if (!currentVisited[newNode.first][newNode.second] && grid[newNode.first][newNode.second] == '.') {
            currentVisited[newNode.first][newNode.second] = true;
            imposterFirstSearch(newNode);
            currentVisited[newNode.first][newNode.second] = false;
        }
    }
    if (node.first < rows - 1) {
        newNode.first += 1;
        if (!currentVisited[newNode.first][newNode.second] && grid[newNode.first][newNode.second] == '.') {
            currentVisited[newNode.first][newNode.second] = true;
            imposterFirstSearch(newNode);
            currentVisited[newNode.first][newNode.second] = false;
        }
    }
    if (node.second > 0) {
        newNode.second -= 1;
        if (!currentVisited[newNode.first][newNode.second] && grid[newNode.first][newNode.second] == '.') {
            currentVisited[newNode.first][newNode.second] = true;
            imposterFirstSearch(newNode);
            currentVisited[newNode.first][newNode.second] = false;
        }
    }
    if (node.second < columns - 1) {
        newNode.second += 1;
        if (!currentVisited[newNode.first][newNode.second] && grid[newNode.first][newNode.second] == '.') {
            currentVisited[newNode.first][newNode.second] = true;
            imposterFirstSearch(newNode);
            currentVisited[newNode.first][newNode.second] = false;
        }
    }
}

int main() {
    cin >> rows >> columns;
    cin >> start.first >> start.second;
    cin >> finish.first >> finish.second;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> grid[i][j];
        }
    }
    imposterFirstSearch(start);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (allVisited[i][j] == true) {
                cout << "+";
            } else {
                cout << grid[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
