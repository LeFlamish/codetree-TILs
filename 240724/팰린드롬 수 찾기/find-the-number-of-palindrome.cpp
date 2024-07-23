#include <bits/stdc++.h>
using namespace std;
int x, y, ret;

bool check(int i) {
    string s = to_string(i);
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
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