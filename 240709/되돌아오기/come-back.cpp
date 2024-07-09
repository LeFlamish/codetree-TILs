#include <bits/stdc++.h>
using namespace std;
int N, x, y, dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 }, dir, t, ret;
char d;
int getDir(char d) {
    if (d == 'E') return 0;
    else if (d == 'S') return 1;
    else if (d == 'W') return 2;
    else return 3;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> d >> t;
        dir = getDir(d);
        for (int j = 0; j < t; j++) {
            x += dx[dir];
            y += dy[dir];
            ret++;
            if (x == 0 && y == 0) {
                cout << ret;
                return 0;
            }
        }
    }
    return 0;
}