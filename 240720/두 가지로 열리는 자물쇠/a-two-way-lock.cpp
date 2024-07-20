#include <bits/stdc++.h>
using namespace std;
int N, a[3], b[3], ret;

bool is_nearby(int x, int y) {
    if (x == y) return true;
    if ((x - y + N) % N <= 2 || (y - x + N) % N <= 2) return true;
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int i = 0; i < 3; i++) cin >> b[i];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if ((is_nearby(a[0], i) && is_nearby(a[1], j) && is_nearby(a[2], k)) || (is_nearby(b[0], i) && is_nearby(b[1], j) && is_nearby(b[2], k))) ret++;
            }
        }
    }
    cout << ret;
    return 0;
}