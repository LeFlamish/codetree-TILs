#include <bits/stdc++.h>
using namespace std;
int n, arr[200002], cur, nxt, cnt[3];
char color[200002];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	cur = 100001;
	for (int t = 0; t < n; t++) {
		int x;
		char y;
		cin >> x >> y;
		if (y == 'R') {
			nxt = cur + x - 1;
			for (int i = cur; i <= nxt; i++) {
				arr[i]++;
				color[i] = 'B';
			}
		}
		else {
			nxt = cur - x + 1;
			for (int i = cur; i >= nxt; i--) {
				arr[i]++;
				color[i] = 'W';
			}
		}
		cur = nxt;
	}
	for (int i = 1; i < 200002; i++) {
		if (arr[i] >= 4) cnt[2]++;
		else if (arr[i] > 0) {
			if (color[i] == 'W') cnt[0]++;
			else cnt[1]++;
		}
	}
	for (int i = 0; i < 3; i++) {
		cout << cnt[i] << ' ';
	}
	return 0;
}