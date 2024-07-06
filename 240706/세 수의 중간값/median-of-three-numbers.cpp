#include <iostream>
using namespace std;
int a, b, c;
int main() {
    cin >> a >> b >> c;
    if (b > a && b < c) cout << 1;
    else cout << 0;
    return 0;
}