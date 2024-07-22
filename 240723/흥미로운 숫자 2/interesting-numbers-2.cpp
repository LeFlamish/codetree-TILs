#include <bits/stdc++.h>
using namespace std;
int x, y, ret;
bool digit[10];

bool check(int i) {
    memset(digit, false, sizeof(digit));
    while (i > 0) {
        digit[i % 10]++;
        i /= 10;
    }
    int cnt = 0;
    for (int j = 0; j < 10; j++) {
        if (digit[j]) cnt++;
    }
    if (cnt == 2) return true;
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