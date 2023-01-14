#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    int n;
    double a = 0;
    cin >> n;
    double h[n+1];
    double i[n];
    int c = 0;
    int g;
    int l;
    
    while ( c <= n ) {
        cin >> h[c];
        c += 1;
    }
    
    c = 0;
    
    while ( c < n ) {
        cin >> i[c];
        c++;
    }
    
    c = 0;
    
    while ( c < n ) {
        if ( h[c] > h[c+1] ) {
            g = h[c];
            l = h[c+1];
        } else {
            g = h[c+1];
            l = h[c];
        }
        
        a += l * i[c] + ( i[c] * (g-l) / 2 );
        c++;
    }
    
    cout << fixed << a;
    return 0;
}