#include <bits/stdc++.h>
using namespace std;
int n, m, board[101][101], dir, dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 }, x, y;
int changeDir(int dir) {
    return (dir + 1) % 4;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        board[y][x] = i;
        x += dx[dir];
        y += dy[dir];
        if (x < 0 || x >= m || y < 0 || y >= n || board[y][x]) {
            x -= dx[dir];
            y -= dy[dir];
            dir = changeDir(dir);
            x += dx[dir];
            y += dy[dir];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}