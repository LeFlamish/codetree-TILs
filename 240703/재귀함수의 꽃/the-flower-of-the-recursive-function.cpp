#include <iostream>
using namespace std;

int N;

void printNum(int N) {
    if (N == 0) return;

    cout << N << ' ';
    printNum(N - 1);
    cout << N << ' ';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    printNum(N);
    return 0;
}