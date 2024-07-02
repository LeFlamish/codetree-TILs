#include <iostream>
using namespace std;

int N;

int calculate(int N, int cnt) {
    if (N == 1) return cnt;

    if (N % 2) return calculate(N / 2, cnt + 1);
    else return calculate(N / 3, cnt + 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    cout << calculate(N, 1);
    return 0;
}