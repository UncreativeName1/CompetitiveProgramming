??=include <iostream>
using namespace std;
int main() ??<
    int one = true;
    int two = one << one;
    int four = one << one << one;
    int eight = one << one << one << one;
    int sixteen = one << one << one << one << one;
    int thirtytwo = one << one << one << one << one << one;
    int sixtyfour = one << one << one << one << one << one << one;
    char H = sixtyfour ??! eight;
    char e = sixtyfour ??! thirtytwo ??! four ??! one;
    char l = sixtyfour ??! thirtytwo ??! eight ??! four;
    char o = sixtyfour ??! thirtytwo ??! eight ??! four ??! two ??! one;
    char COMMA = thirtytwo ??! eight ??! four;
    char SPACE = thirtytwo;
    char W = sixtyfour ??! sixteen ??! four ??! two ??! one;
    char r = sixtyfour ??! thirtytwo ??! sixteen ??! two;
    char d = sixtyfour ??! thirtytwo ??! four;
    char EXCL = thirtytwo ??! one;
    cout << H << e << l << l << o << COMMA << SPACE << W << o << r << l << d << EXCL << endl;
??>