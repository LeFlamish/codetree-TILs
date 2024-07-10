#include <bits/stdc++.h>
using namespace std;
int N, board[20][20], cnt, ret;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int a = 0; a < N - 2; a++) {
                for (int b = 0; b < N - 2; b++) {
                    if (i != j) ret = max(board[i][a] + board[i][a + 1] + board[i][a + 2] + board[j][b] + board[j][b + 1] + board[j][b + 2], ret);
                    else {
                        if (abs(a - b) > 2) ret = max(board[i][a] + board[i][a + 1] + board[i][a + 2] + board[j][b] + board[j][b + 1] + board[j][b + 2], ret);
                    }
                }
            }
        }
    }
    cout << ret;
    return 0;
}