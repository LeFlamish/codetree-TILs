#include <bits/stdc++.h>
using namespace std;
int T, a, b, d1, d2, ret;
char position[1001];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> T >> a >> b;
    for (int i = 0; i < T; i++) {
        char alphabet;
        int x;
        cin >> alphabet >> x;
        position[x] = alphabet;
    }
    for (int i = a; i <= b; i++) {
        d1 = INT_MAX; d2 = INT_MAX;
        for (int j = 1; j < 1001; j++) {
            if (position[j] == 'S') d1 = min(d1, abs(i - j));
        }
        for (int j = 1; j < 1001; j++) {
            if (position[j] == 'N') d2 = min(d2, abs(i - j));
        }
        if (d1 <= d2) ret++;
    }
    cout << ret;
    return 0;
}