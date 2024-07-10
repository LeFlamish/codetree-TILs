#include <bits/stdc++.h>
using namespace std;
int N, K, position[10001], tmp, ret;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int p;
        char score;
        cin >> p >> score;
        if (score == 'G') position[p] = 1;
        else position[p] = 2;
    }
    for (int i = 1; i < 10001 - K; i++) {
        tmp = 0;
        for (int j = 0; j <= K; j++) {
            tmp += position[i + j];
        }
        ret = max(ret, tmp);
    }
    cout << ret;
    return 0;
}