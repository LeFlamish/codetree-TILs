#include <iostream>
using namespace std;
int N, x, y, board[202][202], ret;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                board[x + 101 + j][y + 101 + k] = 1;
            }
        }
    }
    for (int j = 0; j < 202; j++) {
        for (int k = 0; k < 202; k++) {
            if (board[j][k]) ret++;
        }
    }
    cout << ret;
    return 0;
}