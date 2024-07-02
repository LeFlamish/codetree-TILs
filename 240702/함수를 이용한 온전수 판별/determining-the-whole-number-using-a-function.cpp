#include <iostream>
using namespace std;

bool isNum(int n) {
    if (!(n % 2)) return false;
    if (n % 10 == 5) return false;
    if (!(n % 3) && (n % 9)) return false;
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    for (int i = a; i <= b; i++) {
        if (isNum(i)) cnt++;
    }
    cout << cnt;
    return 0;
}