#include <iostream>
using namespace std;

int main() {
    char w; int a, f, l, e;
    cin >> w >> a >> f >> l >> e;
    w += 16; a = a * 2 + 6; f = (f - 3) * 3; l += 7; e -= 3;
    cout << "@Enming, Private Daniel is at " << w << " " << a << " " << f << " " << l << " " << e << "!" << endl;
    return 0;
}