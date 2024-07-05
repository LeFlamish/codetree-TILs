#include <bits/stdc++.h>
using namespace std;
int n, arr[2002], cur, nxt, cnt;
int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    cur = 1001;
    for (int i = 0; i < n; i++) {
        int x;
        char y;
        cin >> x >> y;
        if (y == 'R') {
            nxt = cur + x;
            for (int j = cur; j < nxt; j++) arr[j]++;
        }
        else {
            nxt = cur - x;
            for (int j = cur - 1; j >= nxt; j--) arr[j]++;
        }
        cur = nxt;
    }
    for (int i = 1; i < 2002; i++) {
        if (arr[i] >= 2) cnt++;
    }
    cout << cnt;
	return 0;
}