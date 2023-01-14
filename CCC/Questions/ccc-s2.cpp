#include <iostream>
#include <vector>
#include <map>
#define pb push_back
using namespace std;


int main() {
    int x, y, g, violations = 0;

    vector<pair<string, string>> sameGroup, diffGroup;
    map<string, int> personGroup; // name key

    // same group
    cin >> x;
    for (int i = 0; i < x; i++) {
        pair<string, string> tempSameGroup; cin >> tempSameGroup.first >> tempSameGroup.second;
        sameGroup.pb(tempSameGroup);
    }

    // different group
    cin >> y;
    for (int i = 0; i < y; i++) {
        pair<string, string> tempDiffGroup; cin >> tempDiffGroup.first >> tempDiffGroup.second;
        diffGroup.pb(tempDiffGroup);
    }

    // real groups
    cin >> g;
    for (int i = 1; i <= g; i++) {
        string p1, p2, p3; cin >> p1 >> p2 >> p3;
        personGroup[p1] = i;
        personGroup[p2] = i;
        personGroup[p3] = i;
    }

    // same group violations
    for (int i = 0; i < x; i++) {
        if (personGroup[sameGroup[i].first] != personGroup[sameGroup[i].second]) violations++;
    }

    // different group violations
    for (int i = 0; i < y; i++) {
        if (personGroup[diffGroup[i].first] == personGroup[diffGroup[i].second]) violations++;
    }

    cout << violations << endl;
}
