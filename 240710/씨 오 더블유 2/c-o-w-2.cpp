#include <bits/stdc++.h>
using namespace std;
int N, ret;
string s;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> s;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'C') {
            for (int j = i + 1; j < N; j++) {
                if (s[j] == 'O') {
                    for (int k = j + 1; k < N; k++) {
                        if (s[k] == 'W') ret++;
                    }
                }
            }
        }
    }
    cout << ret;
    return 0;
}