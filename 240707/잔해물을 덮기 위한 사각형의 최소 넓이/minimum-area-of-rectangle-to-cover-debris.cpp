#include <iostream>
using namespace std;
const int Offset = 1001;
int board[2002][2002], a, b, c, d, ret, X1, Y1, X2, Y2;
bool flag;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b >> c >> d;
    for (int i = a + Offset; i < c + Offset; i++) {
        for (int j = b + Offset; j < d + Offset; j++) {
            board[i][j] = 1;
        }
    }
    X1 = a + Offset;
    X2 = c + Offset;
    Y1 = b + Offset;
    Y2 = d + Offset;
    cin >> a >> b >> c >> d;
    for (int i = a + Offset; i < c + Offset; i++) {
        for (int j = b + Offset; j < d + Offset; j++) {
            board[i][j] = 0;
        }
    }
    for (int i = 0; i < 2002; i++) {
        for (int j = 0; j < 2002; j++) {
            if (board[i][j] == 1) {
                X1 = min(X1, i);
                X2 = max(X2, i);
                Y1 = min(Y1, j);
                Y2 = max(Y2, j);
                flag = true;
            }
        }
    }
    if (flag) cout << (X2 - X1) * (Y2 - Y1);
    else cout << 0;
    return 0;
}