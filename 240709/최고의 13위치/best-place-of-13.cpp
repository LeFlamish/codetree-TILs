#include <bits/stdc++.h>
using namespace std;
int N, board[21][21], ret, cnt;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 2; j++) {
            cnt = 0;
            cnt += board[i][j] + board[i][j + 1] + board[i][j + 2];
            ret = max(ret, cnt);
        }
    }
    cout << ret;
    return 0;
}