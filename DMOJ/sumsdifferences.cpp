#include <iostream>
#define ll long long
#define ARR_LENGTH(array)        sizeof(array)/sizeof(*array)
#define SET_ARR(array, value)     for (unsigned int INDEX = 0; INDEX < ARR_LENGTH(array); INDEX++) array[INDEX] = value;
#define PRINT_ARR(array)        for (unsigned int INDEX = 0; INDEX < ARR_LENGTH(array); INDEX++) { cout << array[INDEX] << " "; } cout << endl;
using namespace std;

// flush before outputting.
int main() {
	int N;
	cin >> N;
	int returned[N] = {0}, final[N] = {0};
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int temp = i + 2;
		if (temp > N) temp = 1;
		cout << "? " << i + 1 << " " << temp << endl;
		cout << flush;
		cin >> returned[i];
	}
	// Aj[] (returned values) are filled.
	for (int i = 2; i < N; i++) {
		final[i] = returned[i-2] - returned[i-1];
		sum += final[i];
	}
	final[1] = (sum + returned[N-1]) / (0-2);
	final[0] = final[1] + returned[0];
	cout << "! ";
	for (int i = 0; i < N; i++) {
		cout << final[i];
		if (i != N-1) cout << " ";
	}
	cout << endl;

	return 0;
}