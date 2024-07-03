#include <iostream>
using namespace std;
int a, b;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b;
    if (a > b) cout << a * b;
    else cout << b / a;
    return 0;
}