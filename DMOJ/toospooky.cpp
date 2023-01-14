#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#define ll long long
#define ARR_LENGTH(array) sizeof(array)/sizeof(*array)
#define SET_ARR(array, value) for (unsigned int INDEX = 0; INDEX < ARR_LENGTH(array); INDEX++) array[INDEX] = value;
#define PRINT_ARR(array) for (unsigned int INDEX = 0; INDEX < ARR_LENGTH(array); INDEX++) { cout << array[INDEX] << " "; } cout << endl;
#define PRINT_VEC(vector) for (unsigned int INDEX = 0; INDEX < vector.size(); INDEX++) { cout << vector[INDEX] << " "; } cout << endl;
using namespace std;

int main() {
    int a;
    int b;
    int s;
    int i = 0;
    int num_decorations;
    long num_houses;
    int too_spook;
    int candy = 0;
    cin >> num_decorations;
    cin >> num_houses;
    cin >> too_spook;
    
    vector<int> house_array;
    for (int i = 0; i < num_houses; i++) {
    	house_array.push_back(0);
    }
    
    while ( i < num_decorations ) {
        cin >> a;
        cin >> b;
        cin >> s;
        a--;
        b--;
        while ( a <= b ) {
            house_array[a] += s;
            a++;
        }
        i++;
    }
    
    i = 0;
    while ( i < num_houses ) {
        if ( house_array[i] < too_spook ) {
            candy++;
        }
        cout << i << " ";
        i++;
    }
    
    cout << candy;
    return 0;
}

