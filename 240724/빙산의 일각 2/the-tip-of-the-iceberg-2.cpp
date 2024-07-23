#include <bits/stdc++.h>
using namespace std;
int N, ice[101], mx, ret, cnt;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> ice[i];
        mx = max(mx, ice[i]);
    }
    for (int h = 0; h <= mx; h++) {
        bool prev = false;
        cnt = 0;
        for (int i = 1; i <= N; i++) {
            if (ice[i] > h) {
                if (!prev) {
                    cnt++;
                    prev = true;
                }
            }
            else prev = false;
        }
        ret = max(cnt, ret);
    }
    cout << ret;
    return 0;
}