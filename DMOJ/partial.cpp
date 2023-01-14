#include <iostream>
#define ll long long

using namespace std;

int moreEvenOdd(int numGroups, const int stonesPerGroup[]) {
	ll odd = 0, even = 0;
	for (int i = 0; i < numGroups; i++) {
		if (stonesPerGroup[i] % 2 == 0) {
			even += stonesPerGroup[i] / 2;
		} else {
			odd += stonesPerGroup[i] / 2 + 1;
		}
	}
	if (even > odd) return 0;
	else return 1;
}

int main() {
	int numGroups;
	cin >> numGroups;

	int stonesPerGroup[numGroups];
	for (int i = 0; i < numGroups; i++) {
		cin >> stonesPerGroup[i];
	}

	if (moreEvenOdd(numGroups, stonesPerGroup)) cout << "Alice" << endl;
	else cout << "Duke" << endl;

	return 0;
}