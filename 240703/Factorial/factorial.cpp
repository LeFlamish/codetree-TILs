#include <iostream>
using namespace std;

int N;

int fact(int n) {
    if (n == 0 || n == 1) return 1;

    return fact(n - 1) * n;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    cout << fact(N);
    return 0;
}