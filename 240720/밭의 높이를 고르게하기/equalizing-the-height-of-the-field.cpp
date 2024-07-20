#include <bits/stdc++.h>
using namespace std;
int N, T, H, arr[101], ret = INT_MAX, tmp;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> H >> T;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - T + 1; j++) {
            tmp = 0;
            for (int k = 0; k < T; k++) {
                tmp += abs(arr[j + k] - H);
            }
            ret = min(tmp, ret);
        }
    }
    cout << ret;
    return 0;
}