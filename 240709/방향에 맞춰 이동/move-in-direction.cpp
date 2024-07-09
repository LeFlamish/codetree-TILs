#include <bits/stdc++.h>
using namespace std;
int N, x, y;
// 동 서 남 북
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int t;
        char d;
        cin >> d >> t;
        if (d == 'E') {
            for (int j = 0; j < t; j++) {
                x += dx[0];
                y += dy[0];
            }
        }
        else if (d == 'W') {
            for (int j = 0; j < t; j++) {
                x += dx[1];
                y += dy[1];
            }
        }
        else if (d == 'S') {
            for (int j = 0; j < t; j++) {
                x += dx[2];
                y += dy[2];
            }
        }
        else {
            for (int j = 0; j < t; j++) {
                x += dx[3];
                y += dy[3];
            }
        }
    }
    cout << x << ' ' << y;
    return 0;
}