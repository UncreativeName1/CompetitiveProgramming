#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define ll long long
#define PRINT_VEC(vector) for (unsigned int INDEX = 0; INDEX < vector.size(); INDEX++) { cout << vector[INDEX] << " "; } cout << endl;
using namespace std;

vector<int> p, w, d;
int n;

ll totalTime(int positionOfConcert) {
    ll totalTimeNeeded = 0;
    for (int i = 0; i < n; i++) {
        // Lowest and highest values of the person's range of hearing.
        int lowerbound = p[i] - d[i];
        int upperbound = p[i] + d[i];
        // If the person can already hear the concert (i.e. the concert is inside their range of hearing)
        if ((positionOfConcert <= upperbound) && (positionOfConcert >= lowerbound)) continue;
        totalTimeNeeded += ((ll)w[i] * min(abs(lowerbound - positionOfConcert), abs(positionOfConcert - upperbound)));
    }
    return totalTimeNeeded;
}

int main() {
	ios_base::sync_with_stdio(false);

    cin >> n;

    p.resize(n);
    w.resize(n);
    d.resize(n);

    // Need the left most and right most people.
    int leftmost = 1000000000, rightmost = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> w[i] >> d[i];
        leftmost = min(leftmost, p[i]);
        rightmost = max(rightmost, p[i]);
    }

    ll shortestTime = 1e18;
    for (int i = 0; i < 60; i++) {
        int oneThirdDistance = (rightmost - leftmost) / 3;
        int bound1 = leftmost + oneThirdDistance;
        int bound2 = rightmost - oneThirdDistance;
        ll time1 = totalTime(bound1);
        ll time2 = totalTime(bound2);
        shortestTime = min(time1, shortestTime);
        shortestTime = min(time2, shortestTime);
        if (time1 > time2){
            leftmost = bound1;
            
        } else {
            rightmost = bound2;
        }
    }

    cout << shortestTime << endl;

	return 0;
}

