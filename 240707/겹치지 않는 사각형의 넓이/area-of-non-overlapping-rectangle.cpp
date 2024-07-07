#include <iostream>
using namespace std;
int board[2002][2002], a, b, c, d, ret;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 2; i++) {
        cin >> a >> b >> c >> d;
        for (int x = a + 1001; x < c + 1001; x++) {
            for (int y = b + 1001; y < d + 1001; y++) {
                board[x][y] = 1;
            }
        }
    }
    cin >> a >> b >> c >> d;
    for (int x = a + 1001; x < c + 1001; x++) {
        for (int y = b + 1001; y < d + 1001; y++) {
            board[x][y] = 0;
        }
    }

    for (int x = 0; x < 2002; x++) {
        for (int y = 0; y < 2002; y++) {
            if (board[x][y]) ret++;
        }
    }
    cout << ret;
    return 0;
}