#include <bits/stdc++.h>
using namespace std;
int N, M, ret;
string board[50];
// 0 : →, 1 : ↘, 2 : ↓, 3 : ↙, 4 : ←, 5 : ↖, 6 : ↑, 7 : ↗
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int checkLEE(int X, int Y) {
    int cnt = 0;
    for (int dir = 0; dir < 8; dir++) {
        int x = X;
        int y = Y;
        bool flag = true;
        for (int a = 0; a < 2; a++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
                flag = false;
                break;
            }
            if (board[ny][nx] != 'E') {
                flag = false;
                break;
            }
            x = nx;
            y = ny;
        }
        if (flag) cnt++;
    }
    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'L') {
                ret += checkLEE(j, i);
            }
        }
    }
    cout << ret;
    return 0;
}