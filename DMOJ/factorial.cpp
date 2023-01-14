#include <iostream>
#define ll long long
#define ARR_LENGTH(array)        sizeof(array)/sizeof(*array)
#define SET_ARR(array, value)     for (unsigned int INDEX = 0; INDEX < ARR_LENGTH(array); INDEX++) array[INDEX] = value;
#define PRINT_ARR(array)        for (unsigned int INDEX = 0; INDEX < ARR_LENGTH(array); INDEX++) { cout << array[INDEX] << " "; } cout << endl;
using namespace std;

// a^(p-2) = a^(-1) (mod p)
ll inverseMod(ll num, ll p) { 
    ll remainder = 1, power = p-2;
    num %= p;
    while (power > 0) {
        if (power % 2) {
            remainder *= num;
            remainder %= p;
        }
        power /= 2;
        num *= num;
        num %= p;
    }
    return remainder;
}

// (p-1)! = -1 (mod p)
ll calcMod(ll n, ll p) { 
    ll remainder = p - 1; 
    if (p <= n) return 0; 
    for (ll i = n + 1; i < p; i++) {
        remainder *= inverseMod(i, p);
        remainder %= p; 
    }
    return remainder;
}

int main() { 
    ll N, P;
    cin >> N >> P;
    cout << calcMod(N, P) << endl;
    return 0; 
}
