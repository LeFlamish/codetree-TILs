#include <bits/stdc++.h>
using namespace std;
int n, board[101][101], dx[] = { 1, 0, -1, 0 }, dy[] = { 0, -1, 0, 1 }, cnt, ret;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt = 0;
            for (int dir = 0; dir < 4; dir++) {
                int x = j + dx[dir];
                int y = i + dy[dir];
                if (x < 0 || x >= n || y < 0 || y >= n) continue;
                if (board[y][x] == 1) cnt++;
            }
            if (cnt >= 3) ret++;
        }
    }
    cout << ret;
    return 0;
}