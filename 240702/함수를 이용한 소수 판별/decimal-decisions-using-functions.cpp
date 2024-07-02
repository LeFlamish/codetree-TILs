#include <iostream>
using namespace std;
int a, b, answer;

bool isPrime(int n) {
    if (n == 0 || n == 1) return false;
    else {
        for (int i = 2; i < n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if (isPrime(i)) answer += i;
    }
    cout << answer;
    return 0;
}