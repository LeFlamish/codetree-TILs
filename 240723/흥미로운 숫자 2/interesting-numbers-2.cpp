#include <bits/stdc++.h>
using namespace std;
int x, y, ret;
int digit[10];

bool check(int i) {
    memset(digit, 0, sizeof(digit));
    while (i > 0) {
        digit[i % 10]++;
        i /= 10;
    }
    int flag = 0, cnt = 0;
    for (int j = 0; j < 10; j++) {
        if (digit[j] == 1) flag++;
        else if (digit[j] > 1) cnt++;
    }
    if (flag == 1 && cnt == 1) return true;
    else return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> x >> y;
    for (int i = x; i <= y; i++) {
        if (check(i)) ret++;
    }
    cout << ret;
    return 0;
}