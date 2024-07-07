#include <iostream>
using namespace std;
int N, board[202][202], X1, Y1, X2, Y2, cnt;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int n = 0; n < N; n++) {
        cin >> X1 >> Y1 >> X2 >> Y2;
        for (int i = X1 + 101; i < X2 + 101; i++) {
            for (int j = Y1 + 101; j < Y2 + 101; j++) {
                board[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < 202; i++) {
        for (int j = 0; j < 202; j++) {
            if (board[i][j]) cnt++;
        }
    }
    cout << cnt;
    return 0;
}