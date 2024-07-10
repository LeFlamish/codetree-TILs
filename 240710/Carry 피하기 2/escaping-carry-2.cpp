#include <bits/stdc++.h>
using namespace std;
int n, arr[21], ret = INT_MIN;

bool carryCheck(int x, int y) {
    bool flag = true;
    string X = to_string(x);
    string Y = to_string(y);
    int len = min(X.size(), Y.size());
    for (int i = 0; i < len; i++) {
        char xnum = X[X.size() - 1 - i];
        char ynum = Y[Y.size() - 1 - i];
        if (xnum - '0' + ynum - '0' > 9) {
            flag = false;
            break;
        }
    }
    if (flag) return true;
    else return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    bool flag = false;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (carryCheck(arr[i], arr[j])) {
                    if (carryCheck(arr[i] + arr[j], arr[k])) {
                        ret = max(ret, arr[i] + arr[j] + arr[k]);
                        flag = true;
                    }
                }
            }
        }
    }
    if (flag) cout << ret;
    else cout << -1;
    return 0;
}