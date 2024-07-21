#include <bits/stdc++.h>
using namespace std;
int K, N, ret;
int score[11][21];
bool check[21][11][11];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            cin >> score[i][j];
        }
    }
    for (int i = 0; i < K; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = j + 1; k <= N; k++) {
                check[i][score[i][j]][score[i][k]] = true;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            bool flag = false;
            for (int k = 0; k < K; k++) {
                if (!check[k][i][j]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) ret++;
        }
    }
    cout << ret;
    return 0;
}