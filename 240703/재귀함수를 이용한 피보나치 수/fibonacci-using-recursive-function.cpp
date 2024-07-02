#include <iostream>
using namespace std;

int N;

int fibb(int N) {
    if (N == 0 || N == 1) return N;

    return fibb(N - 1) + fibb(N - 2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    cout << fibb(N);
    return 0;
}