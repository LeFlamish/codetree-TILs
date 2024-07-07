#include <iostream>
using namespace std;
int n, cur, nxt, white, black;
char tile[200002];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    cur = 100001;
    for (int i = 0; i < n; i++) {
        int x;
        char y;
        cin >> x >> y;
        if (y == 'R') {
            nxt = cur + x - 1;
            for (int index = cur; index <= nxt; index++) tile[index] = 'B';
        }
        else {
            nxt = cur - x + 1;
            for (int index = cur; index >= nxt; index--) tile[index] = 'W';
        }
        cur = nxt;
    }
    for (int i = 0; i < 200002; i++) {
        if (tile[i] == 'W') white++;
        else if (tile[i] == 'B') black++;
    }
    cout << white << ' ' << black;
    return 0;
}