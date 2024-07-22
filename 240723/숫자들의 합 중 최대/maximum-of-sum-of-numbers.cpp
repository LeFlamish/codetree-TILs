#include <bits/stdc++.h>
using namespace std;
int X, Y, ret;

int getSum(int i) {
    int tmp = 0;
    while (i > 0) {
        tmp += i % 10;
        i /= 10;
    }
    return tmp;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> X >> Y;
    for (int i = X; i <= Y; i++) {
        ret = max(ret, getSum(i));
    }
    cout << ret;
    return 0;
}