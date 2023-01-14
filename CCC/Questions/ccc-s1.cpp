#include <iostream>
using namespace std;

int main() {
    int num; cin >> num;
    int ans = 0, maxFives = 200000;
    for (int i = 0; i <= maxFives; i++) {
        if (num - 5 * i >= 0) {
            if ((num - 5*i) % 4 == 0) ans++;
        } else break;
    }
    cout << ans << endl;
}