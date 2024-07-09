#include <bits/stdc++.h>
using namespace std;
int N, M, x, y, board[101][101], dx[] = { 0, 1, 0, -1 }, dy[] = { -1, 0, 1, 0 }, cnt;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cnt = 0;
        cin >> y >> x;
        board[y][x] = 1;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (board[ny][nx]) cnt++;
        }
        if (cnt == 3) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}