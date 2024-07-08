#include <bits/stdc++.h>
using namespace std;
const int OFFSET = 1001;
int a, b, x, y, board[2002][2002];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b >> x >> y;
    for (int i = a + OFFSET; i < x + OFFSET; i++) {
        for (int j = b + OFFSET; j < y + OFFSET; j++) {
            board[i][j] = 1;
        }
    }
    cin >> a >> b >> x >> y;
    for (int i = a + OFFSET; i < x + OFFSET; i++) {
        for (int j = b + OFFSET; j < y + OFFSET; j++) {
            board[i][j] = 0;
        }
    }
    a = INT_MAX;
    b = INT_MAX;
    x = INT_MIN;
    y = INT_MIN;
    for (int i = 0; i < 2002; i++) {
        for (int j = 0; j < 2002; j++) {
            if (board[i][j] == 1) {
                a = min(a, i);
                b = min(b, j);
                x = max(x, i);
                y = max(y, j);
            }
        }
    }
    cout << (x - a + 1) * (y - b + 1);
    return 0;
}