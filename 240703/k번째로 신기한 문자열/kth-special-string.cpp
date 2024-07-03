#include <bits/stdc++.h>
using namespace std;

int n, k;
string T, arr[101];
vector<string> ans;
bool flag;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> T;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (string x : arr) {
        flag = false;
        for (int i = 0; i < T.size(); i++) {
            if (x[i] != T[i]) {
                flag = true;
                break;
            }
        }
        if (!flag) ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    cout << ans[k - 1];
    return 0;
}