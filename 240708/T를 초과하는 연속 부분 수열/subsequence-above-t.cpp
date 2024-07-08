#include <bits/stdc++.h>
using namespace std;
int n, t, Cur, cnt, ret;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> Cur;
        if (Cur > t) cnt++;
        else {
            ret = max(ret, cnt);
            cnt = 0;
        }
    }
    cout << ret;
    return 0;
}