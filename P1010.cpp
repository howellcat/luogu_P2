#include <iostream>
#include <cmath>

using namespace std;

const int a = 2;

void confirm(int x) {
    if (x != 0)
        cout << "2";
    else return;
    int k = log(x) / log(a);
    if (k == 2) {
        cout << "(2)";
    } else if (k == 0) {
        cout << "(0)";
    } else if (k > 2) {
        cout << "(";
        confirm(k);
        cout << ")";
    }
    int remainder = x - pow(a, k);
    if (remainder) {
        cout << "+";
        confirm(remainder);
    }
}

int main() {
    int x;
    cin >> x;
    confirm(x);
    return 0;
}