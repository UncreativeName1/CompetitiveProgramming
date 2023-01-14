#include <iostream>
#include <vector>
#include <utility>
#include <map>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int numIntervals, maxValue; 
    ll consecutiveKDifference[100005];
    vector<ll> startPoint(10005), endPoint(10005);
    ll numOfPairs = 0;
    cin >> numIntervals >> maxValue;
    for (int i = 0; i < numIntervals; i++) {
        int ai, bi;
        cin >> ai >> bi;
        startPoint[ai]++;
        endPoint[bi]++;
    }
    for (int i = 0;i <= maxValue; i++) {
        for (int j = 0; j <= maxValue; j++) {
            int index = i + j;
            consecutiveKDifference[index + 1] -= (ll)(endPoint[i] * endPoint[j]);
            consecutiveKDifference[index] += (ll)(startPoint[i] * startPoint[j]);
        }
    }
    for(int i = 0; i < 2 * maxValue + 1; i++) {
        numOfPairs += consecutiveKDifference[i];
        cout << numOfPairs << endl;
    }
}

