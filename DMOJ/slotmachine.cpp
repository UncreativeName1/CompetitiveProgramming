#include <iostream>

using namespace std;

int main() {
	int payoutFreq[3] = {35, 100, 10};
	int payout[3] = {30, 60, 9};
	int quarters, slot1, slot2, slot3;
	cin >> quarters >> slot1 >> slot2 >> slot3;
	int timesPlayed[3] = {slot1, slot2, slot3};

	int machine = 0;
	int counter = 0;

	for (int i = quarters; i > 0; i--) {
		timesPlayed[machine]++;
		machine++;
		machine %= 3;
		if (timesPlayed[machine] == payoutFreq[machine]) {
			timesPlayed[machine] = 0;
			i += payout[machine];
		}
		counter++;
	}

	cout << "Martha plays " << counter << " times before going broke." << endl;

    return 0;
}