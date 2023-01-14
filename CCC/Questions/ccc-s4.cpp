#include <iostream>
#include <vector>
#include <cmath>
#define pb push_back
using namespace std;

int n, c;

bool isAcute(int p1, int p2, int other) {
    if (p1 == p2 || p1 == other || p2 == other) return false;

    int smaller, larger;
    if (p1 > p2) {
        smaller = p2;
        larger = p1;
    } else {
        smaller = p1;
        larger = p2;
    }

    // 1st check
    // between smaller and larger
    if (other > smaller && other < larger) {
        if (larger - smaller >= floor(c) + 1) {
            return true;
        }
    } else {
        if (larger - smaller <= ceil(c) - 1) {
            return true;
        }
    }
    return false;
}

int main() {
    int numAcutes = 0;
    cin >> n >> c;
    vector<int> points;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        points.pb(temp);
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (isAcute(points[i], points[j], points[k])) {
                    cout << points[i] << " " << points[j] << " " << points[k] << " " << endl;
                    numAcutes++;
                } else {
                    cout << "NO" << endl;
                }
            }
        }
    }

    cout << numAcutes << endl;
}