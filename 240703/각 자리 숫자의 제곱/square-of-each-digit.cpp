#include <iostream>
using namespace std;

int N;

int result(int N) {
    if (N < 10) return N * N;
    int temp = N % 10;
    return result(N / 10) + temp * temp;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    cout << result(N);
    return 0;
}