#include <iostream>
using namespace std;

int N;

void printNum(int N) {
    if (N == 0) return;
    
    printNum(N - 1);
    cout << N << ' ';
}

void printReverse(int N) {
    if (N == 0) return;
    
    cout << N << ' ';
    printReverse(N - 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    printNum(N);
    cout << '\n';
    printReverse(N);
    return 0;
}