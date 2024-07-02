#include <iostream>
using namespace std;

bool evenNum(int n) {
    int Sum = 0;
    while(n > 0) {
        Sum += n % 10;
        n /= 10;
    }
    if (Sum & 1) return false;
    else return true;
}

bool isPrime(int n) {
    if (n == 0 || n == 1) return false;
    else {
        for (int i = 2; i < n; i++) {
            if (!(n % i)) return false;
        }
        return true;
    }
}

bool checkNum(int n) {
    if (isPrime(n) && evenNum(n)) return true;
    else return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    for (int i = a; i <= b; i++) {
        if (checkNum(i)) cnt++;
    }
    cout << cnt;
    return 0;
}