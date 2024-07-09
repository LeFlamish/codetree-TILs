#include <bits/stdc++.h>
using namespace std;
int n, x, y, dir, board[100][100], dx[] = { 1, 0, -1, 0 }, dy[] = { 0, -1, 0, 1 }; // 0 : →, 1 : ↑, 2 : ←, 3 : ↓

bool inRange(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < n) return true;
    else return false;
}

bool onLeft(int x, int y, int dir) {
    if (dir == 0) {
        int nx = x + dx[1];
        int ny = y + dy[1];
        if (inRange(nx, ny)) {
            if (board[ny][nx]) return true;
            else return false;
        }
        else return false;
    }
    else if (dir == 1) {
        int nx = x + dx[2];
        int ny = y + dy[2];
        if (inRange(nx, ny)) {
            if (board[ny][nx]) return true;
            else return false;
        }
        else return false;
    }
    else if (dir == 2) {
        int nx = x + dx[3];
        int ny = y + dy[3];
        if (inRange(nx, ny)) {
            if (board[ny][nx]) return true;
            else return false;
        }
        else return false;
    }
    else {
        int nx = x + dx[0];
        int ny = y + dy[0];
        if (inRange(nx, ny)) {
            if (board[ny][nx]) return true;
            else return false;
        }
        else return false;
    }
}

int changeDir(int x, int y, int dir) {
    if (onLeft(x, y, dir)) return dir;
    else return (dir + 1) % 4;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    x = n / 2;
    y = n / 2;
    for (int i = 1; i <= n * n; i++) {
        board[y][x] = i;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (inRange(nx, ny)) {
            x = nx;
            y = ny;
        }
        dir = changeDir(x, y, dir);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}