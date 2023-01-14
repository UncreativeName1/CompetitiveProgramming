#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#define ll long long

using namespace std;

ll patchTastiness[200005], patchLocation[200005];

int main() {
    ll numPatches, numEnemy, numCows; 
    cin >> numPatches >> numEnemy >> numCows;
    vector<pair<ll, ll> > interval;
    set<ll> enemyLocation;
    for (int i = 0; i < numPatches; i++) {
        ll location, tastiness; 
        cin >> location >> tastiness;
        patchLocation[i] = location; patchTastiness[i] = tastiness;
    }
    for (int i = 0; i < numEnemy; i++) {
        ll second; 
        cin >> second;
        enemyLocation.insert(second);
    }

    for (int i = 0; i < numPatches; i++) {
        pair<int, int> patch = {patchLocation[i], patchTastiness[i]};
        auto closestEnemy = enemyLocation.upper_bound(patch.first);
        int lowerbound = *(closestEnemy);
        int upperbound = *(prev(closestEnemy));
        lowerbound = abs(lowerbound - patch.first), upperbound = abs(upperbound - patch.first);
        interval.push_back({max(0, patch.first - min(lowerbound, upperbound)),patch.second});
        interval.push_back({patch.first + min(lowerbound, upperbound), -patch.second});
    }
    sort(interval.begin(), interval.end());

    ll currentSum = 0, totalSum = 0, localMax = 0;
    vector<ll> claimedPatchTastiness;
    for (auto x: interval) {
        currentSum += x.second;
        if (x.second > 0) {
            totalSum += x.second;
        }
        localMax = max(localMax, currentSum);
        if (currentSum == 0) {
            claimedPatchTastiness.push_back(localMax);
            claimedPatchTastiness.push_back(totalSum - localMax);
            currentSum = 0;
            totalSum = 0;
            localMax = 0;
        }
    }
    ll maxTastiness = 0;
    sort(claimedPatchTastiness.begin(), claimedPatchTastiness.end()); 
    reverse(claimedPatchTastiness.begin(), claimedPatchTastiness.end());
    int temp = min((ll)claimedPatchTastiness.size(), numCows);
    for (int i = 0; i < temp; i++) {
        maxTastiness += claimedPatchTastiness[i];
    }
    cout << maxTastiness << endl;
}