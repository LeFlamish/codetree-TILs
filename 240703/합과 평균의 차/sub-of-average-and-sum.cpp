#include <iostream>
using namespace std;

int a, b, c;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b >> c;
    int sum = a + b + c;
    cout << sum << '\n';
    cout << sum / 3 << '\n';
    cout << sum * 2 / 3 << '\n';
    return 0;
}