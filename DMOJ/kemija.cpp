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
	int n;
	cin >> n;
	int original[n] = {0};
	int answer[n] = {0};
	int finishedCycle = 1, gotSolution = 0;
	for (int i = 0; i < n; i++) {
		cin >> original[i];
	}
	// cout << "ORIGINAL: ";
	// PRINT_ARR(original);
	// PRINT_ARR(answer);
	for (answer[0] = 1; answer[0] < original[0] - 2; answer[0]++) {
	    for (answer[1] = 1; answer[1] < original[0] - answer[0]; answer[1]++) {
	        // cout << "-------------------------------" << endl;
	        for (int i = 2; i < n; i++) {
    			answer[i] = original[i-1] - answer[i-1] - answer[i-2];
    			// cout << answer[i] << " = " << original[i-1] << " - " << answer[i-1] << " - " << answer[i-2] << endl;
    			if (answer[i] <= 0) {
    			    finishedCycle = 0;
    				break;
    			}
    		}
    		// PRINT_ARR(answer);
    		// cout << "finishedCycle?: " << finishedCycle << endl;
    		if (finishedCycle && (answer[n-1] + answer[0] + answer[1] == original[0]) && (answer[n-2] + answer[n-1] + answer[0] == original[n-1])) {
    		    gotSolution = 1;
    		    // cout << "gotSolution: " << gotSolution << endl;
    		    // cout << "-------------------------" << endl;
    		    break;
    		}
    		// cout << "gotSolution: " << gotSolution << endl;
    		// cout << "-------------------------" << endl;
    		finishedCycle = 1;
    		for (int i = 2; i < n; i++) {
    			answer[i] = 0;
    		}
    		
	    }
	    if (gotSolution) break;
	}

	for (int i = 0; i < n; i++) {
		cout << answer[i] << endl;
	}
	
	
	return 0;
}