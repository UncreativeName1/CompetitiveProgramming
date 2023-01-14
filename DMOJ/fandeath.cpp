#include <iostream>
#include <cmath>
using namespace std;
int sumDivisors(int x) {  
    int sum = 1 + x; 
    int rootx = sqrt(x);
    for(int i = 2; i < rootx + 1; i++) {
        if(x % i == 0) sum = sum + i + x/i;
    }
    if( rootx * rootx == x ) return sum - rootx;
    else return sum;
}

int main() {
    int n;
    cin >> n;
    cout << sumDivisors(n)*5 - 24 << endl;
}