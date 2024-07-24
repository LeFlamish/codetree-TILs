#include <bits/stdc++.h>
using namespace std;
int a, b, c, mxa, mxb, ret;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b >> c;
    mxa = (c + a - 1) / a;
    mxb = (c + b - 1) / b;
    for (int i = 0; i < mxa; i++) {
        for (int j = 0; j < mxb; j++) {
            int tmp = i * a + j * b;
            if (tmp <= c) ret = max(ret, tmp);
        }
    }
    cout << ret;
    return 0;
}