#include <iostream>
#define ll long long
using namespace std;
int main() {
	int numOfTestCases;
	ll temp, num;
	cin >> numOfTestCases;
	for (int i = 0; i < numOfTestCases; i++) {
		cin >> temp;
		num = temp + 1;
		cout << num << "^3 = " << num * num * num << endl;
		for (ll j = temp + 1; (j * j * j) % 1000 != 888; j++) {
		    cout << num << "^3 = " << num * num * num << endl;
			num = j + 1;
		}
		cout << num << endl;
	}
	return 0;
}