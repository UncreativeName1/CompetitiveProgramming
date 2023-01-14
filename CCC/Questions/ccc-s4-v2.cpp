#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int freq[1000000];
int n, c, bound;


signed main(){
    bound = c / 2;
    if (n % 2 == 0) bound--;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        freq[a]++;
    }
    int ans = 0;
    for (int i = 0;i<c;i++){
        for (int j = i + 1; j < c; j++) {
            for (int k = j + 1; k < c; k++) {
                if (k - j <= bound && j - i <= bound && (i + c) - k <= bound) {
                    ans += freq[i] * freq[j] * freq[k];
                }
            }
        }
    }
    cout << ans << endl;
}