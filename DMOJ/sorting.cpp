#include <iostream>
#include <vector>
#include <algorithm>
#define PRINT_VEC(vector) for (unsigned int INDEX = 0; INDEX < vector.size(); INDEX++) { cout << vector[INDEX] << endl; }
using namespace std;
int main() {
    int num, temp;
	vector<int> numbers; 
	cin >> num;
	while ((int)numbers.size() < num) { cin >> temp; numbers.push_back(temp); }
	sort(numbers.begin(), numbers.end());
	PRINT_VEC(numbers);
	return 0;
}