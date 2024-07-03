#include <iostream>
using namespace std;

int N, arr[11];

int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

int LCM(int a, int b) {
    return (a / GCD(a, b)) * b;
}

int LCMarr(int n) {
    if (n == 0) return arr[n];

    return LCM(LCMarr(n - 1), arr[n - 1]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << LCMarr(N);
    return 0;
}