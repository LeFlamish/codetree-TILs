#include <bits/stdc++.h>
using namespace std;
int n, arr[101], tmp, ret = INT_MIN;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 2; j < n; j++) {
            tmp = arr[i] + arr[j];
            ret = max(ret, tmp);
        }
    }
    cout << ret;
    return 0;
}