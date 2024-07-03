#include <iostream>
using namespace std;

int n;

int counting(int n) {
    if (n == 1) return 0;

    if (n & 1) return counting(3*n + 1) + 1;
    else return counting(n / 2) + 1;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    cout << counting(n);
    return 0;
}