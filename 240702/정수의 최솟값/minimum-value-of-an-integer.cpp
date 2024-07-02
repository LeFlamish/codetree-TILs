#include <iostream>
using namespace std;
int a, b, c;

int MIN(int a, int b, int c) {
    return (a > b) ? (b > c ? c : b) : (a > c ? c : a);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b >> c;
    cout << MIN(a, b, c);
    return 0;
}