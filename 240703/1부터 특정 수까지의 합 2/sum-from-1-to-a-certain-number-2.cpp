#include <iostream>
using namespace std;

int N;

int sigma(int N) {
    if (N == 1 || N == 0) return N;
    return N + sigma(N-1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    cout << sigma(N);
    return 0;
}