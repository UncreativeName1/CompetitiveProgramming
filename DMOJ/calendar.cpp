#include <iostream>

using namespace std;

int main() {
	int weekday, numDays;
	int counter = 0;

	cin >> weekday >> numDays;

	cout << "Sun Mon Tue Wed Thr Fri Sat" << endl;

	for (int i = 0; i < weekday - 1; i++) {
		cout << "    ";
		counter++;
	}
	
	for (int i = 1; i <= numDays; i++) {
		if (i < 10) cout << " ";
		cout << " " << i;
		counter++;
		if (counter == 7 || i == numDays) {
			cout << endl;
			counter = 0;
		} else {
			cout << " ";
		}
	}

    return 0;
}