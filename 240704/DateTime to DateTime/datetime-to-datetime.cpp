#include <iostream>
using namespace std;
int a, b, c;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b >> c;
    int gap = (a - 11) * 24 * 60 + (b - 11) * 60 + c - 11;
    if (gap < 0) cout << -1;
    else cout << gap;
    return 0;
}