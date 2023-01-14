#include <iostream>
#define ll long long
#define ARR_LENGTH(array)       sizeof(array)/sizeof(*array)
#define SET_ARR(array, value)   for (unsigned int INDEX = 0; INDEX < ARR_LENGTH(array); INDEX++) array[INDEX] = value;
#define PRINT_ARR(array)       	for (unsigned int INDEX = 0; INDEX < ARR_LENGTH(array); INDEX++) { cout << array[INDEX] << " "; } cout << endl;
using namespace std;

// Warshall
void findAllPaths(int adjacent[26][26]){
	for (int i = 0 ; i < 26 ; i++) {
	    for (int j = 0 ; j < 26 ; j++) {
    		if (adjacent[j][i]) {
    		    for (int k = 0 ; k < 26 ; k++) {
    			    if (adjacent[i][k]) adjacent[j][k] = 1;
    		    }
		    }
	    }
	}
}

int main() {
	int adj[26][26] = {0};
	int temp[26][26] = {0};
	char current[3] = {0};
	int numOfDiscRoads = 0;
	cin >> current[0] >> current[1];
	while (current[0] != '*' || current[1] != '*') {
		adj[current[0] - 65][current[1] - 65] = 1;
		adj[current[1] - 65][current[0] - 65] = 1;
		temp[current[0] - 65][current[1] - 65] = 1;
		temp[current[1] - 65][current[0] - 65] = 1;
		cin >> current[0] >> current[1];
	}
	
	for (int i = 0; i < 26; i++) {
		for (int j = i+1; j < 26; j++) {
			if (temp[i][j] == 1) {
				// Removes a road that is identified to exist.
				temp[i][j] = 0;
				temp[j][i] = 0;
				findAllPaths(temp);
				if (!temp[0][1]) {
					current[0] = i + 65;
					current[1] = j + 65;
					numOfDiscRoads++;
					cout << current[0] << current[1] << endl;
				}
			}
			for (int i = 0; i < 26; i++) {
			    for (int j = 0; j < 26; j++) {
			        temp[i][j] = adj[i][j];
			    }
			}
		}
	}
	cout << "There are " << numOfDiscRoads << " disconnecting roads." << endl;

	return 0;
}

