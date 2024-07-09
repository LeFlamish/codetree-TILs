#include <bits/stdc++.h>
using namespace std;
int N, room[1004], tmp, ret = INT_MAX;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> room[i];
    }
    for (int start = 1; start <= N; start++) {
        tmp = 0;
        for (int j = 1; j <= N; j++) {
            int move = (N + j - start) % N;
            tmp += move * room[j];
        }
        ret = min(tmp, ret);
    }
    cout << ret;
    return 0;
}