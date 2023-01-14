#include <iostream>
#include <vector>
#include <array>
#define ll long long
#define ARR_LENGTH(array) sizeof(array)/sizeof(*array)
#define SET_ARR(array, value) for (unsigned int INDEX = 0; INDEX < ARR_LENGTH(array); INDEX++) array[INDEX] = value;
#define PRINT_ARR(array) for (unsigned int INDEX = 0; INDEX < ARR_LENGTH(array); INDEX++) { cout << array[INDEX] << " "; } cout << endl;
#define PRINT_VEC(vector) for (unsigned int INDEX = 0; INDEX < vector.size(); INDEX++) { cout << vector[INDEX] << " "; } cout << endl;
using namespace std;

int main() {
	// Using first number, mean[0] = (num[0] + num[1])/2, so do all cases for 1 number. everything else should follow. 
	// if a decimal or if the number is less than the previous, break (continue) that iteration of the loop, and reset the num[] array
	int n;
	cin >> n;
	int mean[n];
	int original[n+1];
	SET_ARR(mean, 0);
	SET_ARR(original, 0);
	int isValid = 1, numOfValid = 0;
	for (int i = 0; i < n; i++) {
		cin >> mean[i];
	}
	original[1] = mean[1];
	original[0] = 2 * mean[0] - original[1];
	while (original[0] <= original[1]) {
		for (int i = 2; i < n+1; i++) {
			original[i] = 2 * mean[i-1] - original[i-1];
			// cout << original[i] << " = 2 * " << mean[i-1] << " - " << original[i-1] << endl;
			if (original[i] < original[i-1]) {
				isValid = 0;
				break;
			}
		}
		if (isValid) {
			cout << "Valid Array: ";
			PRINT_ARR(original);
			numOfValid++;
		}
		isValid = 1;
		for (int i = 2; i < n; i++) {
			original[i] = 0;
		}
		original[0]++;
		original[1]--;
	}

	cout << numOfValid << endl;

	return 0;
}






