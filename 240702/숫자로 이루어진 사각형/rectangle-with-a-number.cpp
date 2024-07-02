#include <iostream>
using namespace std;
int N;

void rectangle(int N) {
    for (int i = 1; i <= N * N; i++) {
        if (i % 9) cout << i % 9;
        else cout << 9;
        cout << ' ';
        if (!(i % N)) cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    rectangle(N);
    return 0;
}