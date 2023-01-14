#include <iostream>
#include <cmath>

using namespace std;

int needToAdd(double i, int numCharacters, const char characters[]) {
	int totalMatches = 0, matched = 0, needToAdd = 0;
	double k = (double)numCharacters - 1;
	double currentValue = k;
	// cout << "i = " << i << "and numCharacters = " << numCharacters << endl;
	for (double j = 0; j < floor(i); j++) {
		while (k >= ceil(i)) {
			if (characters[(int)j] == characters[(int)k]) {
			    // cout << "index " << (int)j << ": " << characters[(int)j] << " is equal to index " << (int)k << ": " << characters[(int)k] << endl;
				k--;
				// cout << "This occurs at j = " << j << endl;
				currentValue = k;
				totalMatches++;
				matched++;
				break;
			}
			k--;
		}
		if (!matched) {
			k = currentValue;
		}
	}
	if (floor(i) == i) {
	    needToAdd = (i - totalMatches) + (numCharacters - i - totalMatches);
	} else {
	    needToAdd = (floor(i) - totalMatches) + (numCharacters - ceil(i) - totalMatches);
	}
	return needToAdd;
}

int main() {
	int numCharacters;
	cin >> numCharacters;

	char characters[numCharacters + 1];
	for (int i = 0; i < numCharacters; i++) {
		cin >> characters[i];
	}

	int current = 0, lowest = 2147483647;

	for (double i = 0; i <= (double)numCharacters; i += 0.5) {
		current = needToAdd(i, numCharacters, characters);
		// cout << current << endl;
		if (current < lowest) lowest = current;
	}

	cout << lowest << endl;


	return 0;
}