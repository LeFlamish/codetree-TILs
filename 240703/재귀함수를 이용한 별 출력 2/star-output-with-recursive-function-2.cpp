#include <iostream>
using namespace std;

int N;

void printStar(int N) {
    if (N == 0) return;

    for (int i = 0; i < N; i++) cout << '*' << ' ';
    cout << '\n';
    printStar(N - 1);
    for (int i = 0; i < N; i++) cout << '*' << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    printStar(N);
    return 0;
}