#include <bits/stdc++.h>
using namespace std;
int N, CP[101][2], tmp, ret = INT_MAX;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> CP[i][0] >> CP[i][1];
    }
    for (int i = 2; i < N; i++) {
        tmp = 0;
        for (int p = 1; p < N; p++) {
            if (p + 1 == i) {
                tmp += abs(CP[p][0] - CP[p + 2][0]) + abs(CP[p][1] - CP[p + 2][1]);
                p++;
            }
            else {
                tmp += abs(CP[p][0] - CP[p + 1][0]) + abs(CP[p][1] - CP[p + 1][1]);
            }
        }
        ret = min(ret, tmp);
    }
    cout << ret;
    return 0;
}