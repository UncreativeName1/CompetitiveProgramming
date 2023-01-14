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

void primeFactorize(ll base, ll power, vector<ll>* primeFactorization) {
	ll counter = 0;
	ll temp = base;
	while (temp % 2 == 0) {
		if (counter == 0) primeFactorization->push_back(2);
		counter++;
		temp /= 2;
	}
	counter *= power;
	// cout << temp << " " << counter << endl;
	if (counter > 0) primeFactorization->push_back(counter);
	counter = 0;
	for (ll i = 3; i <= base; i+=2) {
	    // cout << temp << " " << i << " ";
		while (temp % i == 0) {
			if (counter == 0) primeFactorization->push_back(i);
			counter++;
			temp /= i;
		}
		// cout << counter << endl;
		counter *= power;
		if (counter > 0) primeFactorization->push_back(counter);
		counter = 0;
	}
}


ll lowestFactorial(ll prime, ll exponent) {
	ll factorial = 0;
	ll currentExponent = exponent;
	for (ll i = (ll)prime; i <= (ll)prime * exponent; i += (ll)prime) {
	    ll temp = i;
		while (temp % prime == 0) {
			temp /= prime;
			currentExponent--;
		}
		factorial += prime;
		if (currentExponent <= 0) break;
	}
	return factorial;
}


int main() {
	int k = 5;
	for (ll a = 0; a < k; a++) {
		vector<ll> primeFactorization; // even index (0, 2, ...) is the prime factor, odd index (1, 3, ...) is the number of the previous prime factor.
		ll base, power;
		ll current, highest = 0;
		cin >> base >> power;
		primeFactorize(base, power, &primeFactorization);
		for (ll i = 0; i < primeFactorization.size(); i += 2) {
			current = lowestFactorial(primeFactorization[i], primeFactorization[i+1]);
			if (current > highest) highest = current;
		}
		cout << highest << endl;
	}

	return 0;
}



