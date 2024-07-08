#include <bits/stdc++.h>
using namespace std;
int N, cur, Prev, cnt = 1, ret = 1;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    cin >> Prev;
    for (int i = 1; i < N; i++) {
        cin >> cur;
        if (Prev == cur) cnt++;
        else {
            ret = max(ret, cnt);
            cnt = 1;
        }
        Prev = cur;
    }
    ret = max(ret, cnt);
    cout << ret;
    return 0;
}