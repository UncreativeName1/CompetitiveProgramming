#include <iostream>
#define ll long long
using namespace std;

int main() {
    int final[100005], initial[100005];
    int numCommands = 0;
    int currentMax = 0;
    int numCows; 
    cin >> numCows;
    for (int i = 0; i < numCows; i++) {
        cin >> final[i];
    }
    for (int i = 0; i < numCows; i++) {
        cin >> initial[i];
        final[i] -= initial[i];
        initial[i] = abs(final[i]);
    }

    bool isPositive;
    if (final[0] > 0) {
        isPositive = true;
    } else {
        isPositive = false;
    }

    for (int i = 0; i < numCows; i++) {
        if (isPositive == (final[i] <= 0)) {
            isPositive = !isPositive;
            currentMax = 0;
        }
        if (initial[i] > currentMax) {
            numCommands += initial[i] - currentMax;
        }
        currentMax = initial[i];
    }
    cout << numCommands << endl;
    return 0;
}
