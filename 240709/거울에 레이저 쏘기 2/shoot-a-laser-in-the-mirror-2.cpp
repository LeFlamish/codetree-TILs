#include <bits/stdc++.h>
using namespace std;
int N, K, dir, dx[] = { 0, 1, 0, -1 }, dy[] = { -1, 0, 1, 0 }, cnt, x, y; // 북 동 남 서
string board[1001];

int changeDir(char mirror, int dir) {
    if (mirror == '\\') {
        if (dir == 0) return 3;
        else if (dir == 1) return 2;
        else if (dir == 2) return 1;
        else return 0;
    }
    else {
        if (dir == 0) return 1;
        else if (dir == 1) return 0;
        else if (dir == 2) return 3;
        else return 2;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    cin >> K;
    dir = ((K - 1) / N + 2) % 4;
    if ((K - 1) / N == 0) {
        x = (K - 1) % N;
        y = 0;
    }
    else if ((K - 1) / N == 1) {
        x = N - 1;
        y = (K - 1) % N;
    }
    else if ((K - 1) / N == 2) {
        x = N - 1 - (K - 1) % N;
        y = N - 1;
    }
    else {
        x = 0;
        y = N - 1 - (K - 1) % N;
    }
    
    while (true) {
        dir = changeDir(board[y][x], dir);
        cnt++;
        x += dx[dir];
        y += dy[dir];
        if (x < 0 || x >= N || y < 0 || y >= N) break;
    }
    cout << cnt;
    return 0;
}