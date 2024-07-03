#include <iostream>
using namespace std;
int a;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a;
    if (a & 1) a += 3;
    if (a % 3 == 0) a /= 3;
    cout << a;
    return 0;
}