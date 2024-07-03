#include <iostream>
using namespace std;

int N;

int retN(int n) {
    if (n == 1 || n == 2) return (2 * n);

    return ((retN(n - 1) % 100) * (retN(n - 2) % 100)) % 100;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    cout << retN(N);
    return 0;
}