#include <iostream>

using namespace std;

int main() {
	int func, a = 0, b = 0;
	char temp1, temp2;
	int temp3;
	do {
		cin >> func;
		switch (func) {
			case 1:
				cin >> temp1 >> temp3;
				if (temp1 == 65) {
					a = temp3;
				} else {
					b = temp3;
				}
				break;

			case 2:
				cin >> temp1;
				if (temp1 == 65) {
					cout << a << endl;
				} else {
					cout << b << endl;
				}
				break;

			case 3: 
				cin >> temp1 >> temp2;
				if (temp1 - temp2 == 1) {
					b += a;
				} else if (temp1 - temp2 == -1) {
					a += b;
				} else if (temp1 - temp2 == 0 && temp1 == 65) {
					a += a;
				} else {
					b += b;
				}
				break;

			case 4:
				cin >> temp1 >> temp2;
				if (temp1 - temp2 == 1) {
					b *= a;
				} else if (temp1 - temp2 == -1) {
					a *= b;
				} else if (temp1 - temp2 == 0 && temp1 == 65) {
					a *= a;
				} else {
					b *= b;
				}
				break;

			case 5:
				cin >> temp1 >> temp2;
				if (temp1 - temp2 == 1) {
					b -= a;
				} else if (temp1 - temp2 == -1) {
					a -= b;
				} else if (temp1 - temp2 == 0 && temp1 == 65) {
					a -= a;
				} else {
					b -= b;
				}
				break;

			case 6:
				cin >> temp1 >> temp2;
				if (temp1 - temp2 == 1) {
					b /= a;
				} else if (temp1 - temp2 == -1) {
					a /= b;
				} else if (temp1 - temp2 == 0 && temp1 == 65) {
					a /= a;
				} else {
					b /= b;
				}
				break;
		}
	} while (func < 7);


    return 0;
}