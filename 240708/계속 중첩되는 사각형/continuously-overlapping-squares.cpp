#include <bits/stdc++.h>
using namespace std;
const int OFFSET = 100;
int n, board[200][200], ret, a, b, c, d;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c >> d;
        if (i & 1) { // 홀수
            for (int x = a + OFFSET; x < c + OFFSET; x++) {
                for (int y = b + OFFSET; y < d + OFFSET; y++) {
                    board[x][y] = 0;
                }
            }
        }
        else {
            for (int x = a + OFFSET; x < c + OFFSET; x++) {
                for (int y = b + OFFSET; y < d + OFFSET; y++) {
                    board[x][y] = 1;
                }
            }
        }
    }
    for (int x = 0; x < 200; x++) {
        for (int y = 0; y < 200; y++) {
            if (board[x][y]) ret++;
        }
    }
    cout << ret;
    return 0;
}