#include <bits/stdc++.h>
using namespace std;
int N, arr[100], ret, mx = INT_MIN, mn = INT_MAX, cnt;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        mx = max(arr[i], mx);
        mn = min(arr[i], mn);
    }
    for (int k = mn; k <= mx; k++) {
        cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int from = min(arr[i], arr[j]);
                int to = max(arr[i], arr[j]);
                if (abs(arr[i] - k) == abs(arr[j] - k)) cnt++;
            }
        }
        ret = max(ret, cnt);
    }
    cout << ret;
    return 0;
}