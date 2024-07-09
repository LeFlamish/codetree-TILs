#include <bits/stdc++.h>
using namespace std;
string order;
int x, y, dir, dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 }, cnt;
char d;
int changeDir(char d) {
    if (d == 'L') return (dir - 1 + 4) % 4;
    else return (dir + 1) % 4;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> order;
    for (int i = 0; i < order.size(); i++) {
        if (order[i] == 'L') {
            dir = changeDir('L');
        }
        else if (order[i] == 'R') {
            dir = changeDir('R');
        }
        else {
            x += dx[dir];
            y += dy[dir];
        }
        cnt++;
        if (x == 0 && y == 0) {
            cout << cnt;
            return 0;
        }
    }
    cout << -1;
    return 0;
}