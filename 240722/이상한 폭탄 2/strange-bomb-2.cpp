#include <bits/stdc++.h>
using namespace std;
int N, K, bomb[101], ret, mx;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> bomb[i];
    }
    for (int stand = 1; stand <= N; stand++) {
        int num = bomb[stand];
        for (int dist = 1; dist <= K; dist++) {
            if (stand - dist < 1) break;

            if (bomb[stand - dist] == num) ret = max(ret, num);
        }
        for (int dist = 1; dist <= K; dist++) {
            if (stand + dist > N) break;

            if (bomb[stand + dist] == num) ret = max(ret, num);
        }
    }
    cout << ret;
    return 0;
}