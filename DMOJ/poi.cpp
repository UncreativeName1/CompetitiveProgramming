#include <iostream>
#define ll long long
#define ARR_LENGTH(array)		sizeof(array)/sizeof(*array)
#define SET_ARR(array, value) 	for (unsigned int INDEX = 0; INDEX < ARR_LENGTH(array); INDEX++) array[INDEX] = value;
#define PRINT_ARR(array)		for (unsigned int INDEX = 0; INDEX < ARR_LENGTH(array); INDEX++) { cout << array[INDEX] << " "; } cout << endl;
using namespace std;

int numOfOnes(int array[], int length) {
	int ones = 0;
	for (int i = 0; i < length; i++) {
		if (array[i] == 1) ones++;
	}
	return ones;
}

int main() {
	int contestants, tasks, pID, pScore, pSolved, pRank = 1;
	cin >> contestants >> tasks >> pID;
	int correct[contestants][tasks];
	int contestantScores[contestants];
	int taskScores[tasks];
	for (int i = 0; i < contestants; i++) {
		for (int j = 0; j < tasks; j++) {
			cin >> correct[i][j];
		}
	}
	// Array is filled with boolean values of correct/wrong answer.

	SET_ARR(contestantScores, 0);
	SET_ARR(taskScores, 0);
	
	// -------------------------------DEFAULT------------------------------
// 	cout << "D----------correct----------D" << endl;
// 	for (int i = 0; i < contestants; i++) {
// 	    PRINT_ARR(correct[i]);
// 	}
// 	cout << "D---------taskScores--------D" << endl;
// 	PRINT_ARR(taskScores);
// 	cout << "D------contestantScores-----D" << endl;
// 	PRINT_ARR(contestantScores);
// 	cout << "D---------------------------D" << endl;
	// -------------------------------DEFAULT------------------------------

	// Calculating the amount of points each task will be worth by checking the amount of contestants that got it wrong.
	for (int i = 0; i < tasks; i++) {
		for (int j = 0; j < contestants; j++) {
			if (correct[j][i] == 0) {
				taskScores[i]++;
				// cout << "Index " << j << " got question index " << i << " wrong." << endl;
			}
		}
	}
	// Tasks now have proper score values.
	
	

	// Calculating the amount of points each contestant should receive.
	for (int i = 0; i < contestants; i++) {
		for (int j = 0; j < tasks; j++) {
			if (correct[i][j] == 1) {
				contestantScores[i] += taskScores[j];
			}
		}
	}
	// Contestants now have proper scores.
	
    // --------------------------------------------------------------------
// 	cout << "-----------correct-----------" << endl;
// 	for (int i = 0; i < contestants; i++) {
// 	    PRINT_ARR(correct[i]);
// 	}
// 	cout << "----------taskScores---------" << endl;
// 	PRINT_ARR(taskScores);
// 	cout << "-------contestantScores------" << endl;
// 	PRINT_ARR(contestantScores);
// 	cout << "-----------------------------" << endl;
	// --------------------------------------------------------------------

	pScore = contestantScores[pID - 1];
	pSolved = numOfOnes(correct[pID - 1], tasks);

	for (int i = 0; i < contestants; i++) {
		if (contestantScores[i] > pScore) pRank++;
		else if (contestantScores[i] == pScore) {
			if (numOfOnes(correct[i], tasks) > pSolved) pRank++;
			else if (numOfOnes(correct[i], tasks) == pSolved) {
				if (i+1 < pID) pRank++;
			}
		}
	}

	cout << pScore << " " << pRank << endl;

	return 0;
}

