#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int board[19][19], X, Y, win;
// 0 : ↗, 1 : →, 2 : ↘, 3 : ↓, 4 : ↙
int dx[] = { 1, 1, 1, 0, -1 };
int dy[] = { -1, 0, 1, 1, 1 };

P checkEnd(int X, int Y, int Cur) { // 찾는 데 성공하면 중간 돌의 위치를 리턴
    for (int dir = 0; dir < 5; dir++) {
        bool flag = true;
        int x = X;
        int y = Y;
        for (int a = 0; a < 4; a++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= 19 || ny < 0 || ny >= 19) {
                flag = false;
                break;
            }
            if (board[ny][nx] != Cur) {
                flag = false;
                break;
            }
            x = nx;
            y = ny;
        }
        if (flag) return { X + 2 * dx[dir], Y + 2 * dy[dir] };
    }
    return { -1, -1 };
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (board[i][j] != 0) {
                P answer = checkEnd(j, i, board[i][j]);
                if (answer.first != -1 && answer.second != -1) {
                    cout << board[i][j] << '\n' << answer.second + 1 << ' ' << answer.first + 1;
                    return 0;
                }
            }
        }
    }
    cout << 0;
    return 0;
}