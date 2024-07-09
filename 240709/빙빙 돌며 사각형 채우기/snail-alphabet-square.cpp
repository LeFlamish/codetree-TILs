#include <bits/stdc++.h>
using namespace std;
int n, m, dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 }, dir, x, y;
char board[101][101];

bool isWall(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n || board[y][x]) return true;
    else return false;
}

int changeDir(int dir) {
    return (dir + 1) % 4;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
        board[y][x] = 'A' + (i % 26);
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