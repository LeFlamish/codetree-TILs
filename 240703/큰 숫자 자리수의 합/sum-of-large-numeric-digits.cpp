#include <iostream>
using namespace std;

int a, b, c;

int calculate(int n) {
    if (n < 10) return n;

    return calculate(n / 10) + n % 10;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b >> c;
    cout << calculate(a * b * c);
    return 0;
}