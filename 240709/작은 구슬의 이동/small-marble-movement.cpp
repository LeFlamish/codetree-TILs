#include <bits/stdc++.h>
using namespace std;
int n, t, r, c, dir, dx[] = { 0, 1, 0, -1 }, dy[] = { -1, 0, 1, 0 }, x, y;
char d;

int GetDir(char d) {
    if (d == 'U') return 0;
    else if (d == 'R') return 1;
    else if (d == 'D') return 2;
    else return 3;
}

bool isWall(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > n) return true;
    else return false;
}

int changeDir(int dir) {
    return (dir + 2) % 4;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> t >> r >> c >> d;
    dir = GetDir(d);
    for (int i = 0; i < t; i++) {
        c += dx[dir];
        r += dy[dir];
        if (isWall(c, r)) {
            c -= dx[dir];
            r -= dy[dir];
            dir = changeDir(dir);
        }
    }
    cout << r << ' ' << c;
    return 0;
}