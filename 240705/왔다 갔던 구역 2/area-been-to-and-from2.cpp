#include <iostream>
using namespace std;
int n, arr[2002], cur = 1001, cnt;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        char y;
        cin >> x >> y;
        if (y == 'R') {
            for (int j = cur; j < cur + x; j++) arr[j]++;
            cur += x;
        }
        else {
            for (int j = cur; j > cur - x; j--) arr[j]++;
            cur -= x;
        }
    }
    for (int i = 1; i < 2002; i++) {
        if (arr[i] >= 2) cnt++;
    }
    cout << cnt;
    return 0;
}