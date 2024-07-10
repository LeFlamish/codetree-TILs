#include <bits/stdc++.h>
using namespace std;
int N, arr[100], S, ret = INT_MAX, tmp, total;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            tmp = total - arr[i] - arr[j];
            ret = min(abs(S - tmp), ret);
        }
    }
    cout << ret;
    return 0;
}