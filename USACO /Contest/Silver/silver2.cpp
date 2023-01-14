#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#define ll long long
using namespace std;

const ll MAX_LONG = 9223372036854775807;

int connectedSets[100005];
ll distanceToStart[100005], distanceToEnd[100005];
vector<int> adj[100005]; 
set<ll> nodesInComponent[100005];

void dfs(int currentNode, int setNum) {
    nodesInComponent[setNum].insert(currentNode);
    connectedSets[currentNode] = setNum;
    for (int x: adj[currentNode]) {
        if (connectedSets[x] == -1) {
            dfs(x, setNum);
        }
    }
}

ll calcCost(ll node1, ll node2) {
    return (node1 - node2) * (node1 - node2);
}

int main() {
    ios_base::sync_with_stdio(0); 
    int numCases; 
    cin >> numCases;
    for (int z = 0; z < numCases; z++) {
        bool retrn = false;
        int numFields, numPaths; 
        ll currentMinCost = MAX_LONG;
        int startSet, endSet;
        cin >> numFields >> numPaths;
        if (numFields == 1) {
            cout << "0" << endl;
            retrn = true;
        }
        if (retrn) continue;
        for(int i = 1; i < numFields + 1; i++) {
            connectedSets[i] = -1;
            adj[i].clear();
            nodesInComponent[i].clear();
        }
        for(int i = 0; i < numPaths; i++) {
            int node1, node2;
            cin >> node1 >> node2;
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        int k = 1;
        for (int i = 1; i < numFields + 1; i++) {
            if (connectedSets[i] == -1) {
                dfs(i, k++);
            }
        }
        for (int i = 1; i < k; i++) {
            if (nodesInComponent[i].count(1) && nodesInComponent[i].count(numFields)) {
                cout << "0" << endl;
                retrn = true;
                break;
            }
            if (nodesInComponent[i].count(1)) {
                startSet = i;
            } else if (nodesInComponent[i].count(numFields)) {
                endSet = i;
            }
            nodesInComponent[i].insert(1000000000);
            nodesInComponent[i].insert(-1000000000);
        }
        if (retrn) continue;
        for (int i = 1; i < numFields + 1; i++) {
            auto iteratorToStart = nodesInComponent[startSet].lower_bound(i);
            auto iteratorToEnd = nodesInComponent[endSet].lower_bound(i);
            distanceToStart[i] = min(calcCost((*iteratorToStart), i), calcCost((*prev(iteratorToStart)), i));
            distanceToEnd[i] = min(calcCost((*iteratorToEnd), i), calcCost((*prev(iteratorToEnd)), i));
        }
        for (int i = 1; i < k; i++) {
            ll setDistToStart = MAX_LONG, setDistToEnd = MAX_LONG;
            for (int x: nodesInComponent[i]) {
                if (abs(x) == 1000000000) {
                    continue;
                }
                setDistToStart = min(distanceToStart[x], setDistToStart);
                setDistToEnd = min(distanceToEnd[x], setDistToEnd);
            }
            currentMinCost = min(currentMinCost, setDistToStart + setDistToEnd);
        }
        cout << currentMinCost << endl;
    }
}
