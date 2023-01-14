#include <iostream>
using namespace std;

int main() {
    string s;
    char amogus[5] = {'v', 'i', 'r', 'u', 's'};
    int imposter = 0;
    getline(cin, s);
    for (int i = 0; i < (int)s.size(); i++) {
        if (tolower(s[i]) == amogus[imposter]) {
            imposter++;
        }
        if (imposter > 4) {
            cout << "WARNING: Virus detected!" << endl;
            return 0;
        }
    }
    cout << "Safe to use!" << endl;
    return 0;
}