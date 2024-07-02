#include <iostream>
using namespace std;

int a, b;

void calculator(int& a, int& b) {
    if (a > b) {
        a += 25;
        b *= 2;
    }
    else {
        a *= 2;
        b += 25;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b;
    calculator(a, b);
    cout << a << ' ' << b;
    return 0;
}