#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, k, m, length = 0, minPitchGood = 0; cin >> n >> m >> k;
    vector<long long> finalNotes;

    for (long long i = n; i > 0; i--) {
        length += i;
        minPitchGood = minPitchGood + 1;
        if (length >= k) break;
    }

    if (minPitchGood > m || (k > (n * (n + 1) / 2) || k < n)) {
        cout << -1;
        return 0;
    }

    for (int i = 1; i <= n - length + k; i++) {
        if (i % minPitchGood == 0) cout << minPitchGood << " ";
        else cout << i % minPitchGood << " ";
    }

    for (long long i = n - length + k - minPitchGood + 2; i <= n - length + k; i++) {
        if (i % minPitchGood == 0) finalNotes.push_back(minPitchGood);
        else finalNotes.push_back(i % minPitchGood);
    }

    for (long long i = 0; i < length - k; i++) {
        cout << finalNotes[i % finalNotes.size()] << " ";
    }
    cout << endl;
}

