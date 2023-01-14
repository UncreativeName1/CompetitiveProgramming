#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#define ll long long
#define ARR_LENGTH(array) sizeof(array)/sizeof(*array)
#define SET_ARR(array, value) for (unsigned int INDEX = 0; INDEX < ARR_LENGTH(array); INDEX++) array[INDEX] = value;
#define PRINT_ARR(array) for (unsigned int INDEX = 0; INDEX < ARR_LENGTH(array); INDEX++) { cout << array[INDEX] << " "; } cout << endl;
#define PRINT_VEC(vector) for (unsigned int INDEX = 0; INDEX < vector.size(); INDEX++) { cout << vector[INDEX] << " "; } cout << endl;
using namespace std;

string sum(string num1, string num2) {
	int carryOver = 0;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	if ()
	num1.pop_back();
	num2.pop_back();

	for (int i = 0; i < num1.length(); i++) {
		num1[i] -= 48;
	}
	for (int i = 0; i < num2.length(); i++) {
		num2[i] -= 48;
	}
	for (int i = )
}

int main() {
	int numOfProblems;
	cin >> numOfProblems;
	string temp;
	vector<string> numbers;
	for (int i = 0; i < numOfProblems; i++) {
		cin >> string;
		numbers.push_back(string);
		cin >> string; 
		numbers.push_back(string);
	}

	
	return 0;
}
