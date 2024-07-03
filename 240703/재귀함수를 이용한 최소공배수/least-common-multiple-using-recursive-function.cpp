#include <iostream>
using namespace std;

int N, arr[11];

int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

int LCM(int n) {
    if (n == 2) return (arr[n-1] / GCD(arr[n-1], arr[n-2])) * arr[n-2];
    return (arr[n - 1] / GCD(arr[n - 1], LCM(n-1))) * LCM(n-1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << LCM(N);
    return 0;
}