#include <bits/stdc++.h>
using namespace std;
int N, Prev, Cur, tmp, cnt = 1, ret = 1;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    cin >> Prev;
    for (int i = 1; i < N; i++) {
        cin >> Cur;
        if (Prev < Cur) cnt++;
        else {
            ret = max(ret, cnt);
            cnt = 1;
        }
        Prev = Cur;
    }
    ret = max(ret, cnt);
    cout << ret;
    return 0;
}