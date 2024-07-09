#include <bits/stdc++.h>
using namespace std;
int n, house[101], ret = INT_MAX, tmp;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> house[i];
    }
    for (int i = 1; i <= n; i++) {
        int target = i;
        for (int j = 1; j <= n; j++) {
            tmp += abs(target - j) * house[j];
        }
        ret = min(tmp, ret);
        tmp = 0;
    }
    cout << ret;
    return 0;
}