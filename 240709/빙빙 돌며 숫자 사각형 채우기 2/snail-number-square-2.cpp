#include <bits/stdc++.h>
using namespace std;
int n, m, board[101][101], dx[] = { 0, -1, 0, 1 }, dy[] = { 1, 0, -1, 0 }, x, y, dir;

bool isWall(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n || board[y][x]) return true;
    else return false;
}

int changeDir(int dir) {
    return (dir + 3) % 4;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        board[y][x] = i;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (isWall(nx, ny)) {
            dir = changeDir(dir);
            x += dx[dir];
            y += dy[dir];
        }
        else {
            x = nx;
            y = ny;
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