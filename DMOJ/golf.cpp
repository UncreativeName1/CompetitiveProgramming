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
    int distance, numOfClubs;
    cin >> distance >> numOfClubs;
    int clubs[numOfClubs];
    int minStrokesToReach[distance + 1];
    for (int i = 0 ; i < numOfClubs; i++) {
        cin >> clubs[i];
    }
    for (int i = 0; i <= distance; i++) {
        minStrokesToReach[i] = -1;
    }
    
    minStrokesToReach[0] = 0;
    // Calculate minimum number of strokes to reach each meter length with the given clubs.
    for (int i = 1; i <= distance; i++) {
        int currentMinStrokes = 2147483647;
        for (int j = 0; j < ARR_LENGTH(clubs); j++/*auto p: clubs*/) {
            int previousDistance = i - clubs[j]; // The distance at which club[j] had to be shot at to reach the current distance.
            if (previousDistance >= 0 && minStrokesToReach[previousDistance] >= 0 && minStrokesToReach[previousDistance] < currentMinStrokes) {
                currentMinStrokes = minStrokesToReach[previousDistance];
            }
        }
        
        if (currentMinStrokes < 2147483647) minStrokesToReach[i] = currentMinStrokes + 1; // Get smallest amount of strokes to the previous distance and add one to get to the current distance.
        else minStrokesToReach[i] = -1;
    }
    
    if (minStrokesToReach[distance] == -1) cout << "Roberta acknowledges defeat." << endl;
    else cout << "Roberta wins in " << minStrokesToReach[distance] << " strokes." << endl;
}