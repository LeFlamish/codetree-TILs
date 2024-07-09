#include <bits/stdc++.h>
using namespace std;
int N, T, board[100][100], dx[] = { 0, 1, 0, -1 }, dy[] = { -1, 0, 1, 0 }, dir, ret, x, y;
string order;

bool inRange(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) return false;
    else return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> T >> order;
    x = N / 2;
    y = N / 2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    ret += board[y][x];
    for (int i = 0; i < order.size(); i++) {
        if (order[i] == 'L') {
            dir = (dir + 3) % 4;
        }
        else if (order[i] == 'R') {
            dir = (dir + 1) % 4; 
        }
        else {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (inRange(nx, ny)) {
                x = nx;
                y = ny;
                ret += board[y][x];
            }
        }
    }
    cout << ret;
    return 0;
}