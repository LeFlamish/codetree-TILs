#include <iostream>
using namespace std;

int N;

int Sum(int n, int ret) {
    if (n == 1 || n == 2) return ret + n;

    return Sum(n - 2, ret + n);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    cout << Sum(N, 0);
    return 0;
}