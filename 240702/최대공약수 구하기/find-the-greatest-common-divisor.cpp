#include <iostream>
using namespace std;

int GCD(int n, int m) {
    if (m == 0) return n;
    return GCD(m, n % m);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    cout << GCD(n, m);
    return 0;
}