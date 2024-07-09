#include <bits/stdc++.h>
using namespace std;
string order;
int dir, dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 }, x, y;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> order;
    for (int i = 0; i < order.size(); i++) {
        if (order[i] == 'L') dir = (dir - 1 + 4) % 4;
        else if (order[i] == 'R') dir = (dir + 1) % 4;
        else {
            x += dx[dir];
            y += dy[dir];
        }
    }
    cout << x << ' ' << y;
    return 0;
}