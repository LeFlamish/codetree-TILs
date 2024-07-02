#include <iostream>
using namespace std;

bool check(int n) {
    if (!(n & 1) && (n % 10 + n / 10) % 5 == 0) return true;
    else return false;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    if (check(n)) cout << "Yes";
    else cout << "No";
    return 0;
}