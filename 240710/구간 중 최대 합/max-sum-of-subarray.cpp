#include <bits/stdc++.h>
using namespace std;
int n, k, arr[101], psum[101], ret;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        psum[i] = psum[i - 1] + arr[i];
    }
    for (int i = 0; i < n - k + 1; i++) {
        ret = max(ret, psum[i + k] - psum[i]);
    }
    cout << ret;
    return 0;
}