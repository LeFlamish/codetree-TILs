#include <iostream>
using namespace std;
int a, b, c, d;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b >> c >> d;
    cout << (c - a) * 60 + d - b;
    return 0;
}