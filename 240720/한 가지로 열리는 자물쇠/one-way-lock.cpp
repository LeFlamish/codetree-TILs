#include <bits/stdc++.h>
using namespace std;
int N, x, y, z, ret;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> x >> y >> z;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (fabs(i - x) < 3 || fabs(j - y) < 3 || fabs(k - z) < 3) ret++;
            }
        }
    }
    cout << ret;
    return 0;
}