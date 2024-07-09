#include <bits/stdc++.h>
using namespace std;
int R, C, cnt, ret;
char board[16][16];

bool canJump(int x, int y, char Cur) {
    if (Cur != board[y][x]) return true;
    else return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 1; i < R - 2; i++) {
        for (int j = 1; j < C - 2; j++) {
            if (canJump(j, i, board[0][0])) {
                for (int y = i + 1; y < R - 1; y++) {
                    for (int x = j + 1; x < C - 1; x++) {
                        if (canJump(x, y, board[i][j])) {
                            if (canJump(C - 1, R - 1, board[y][x])) ret++;
                        }
                    }
                }
            }
        }
    }
    cout << ret;
    return 0;
}