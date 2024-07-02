#include <iostream>
using namespace std;

void printHello(int N) {
    if (N == 0) return;

    cout << "HelloWorld\n";
    printHello(N-1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    printHello(N);
    return 0;
}