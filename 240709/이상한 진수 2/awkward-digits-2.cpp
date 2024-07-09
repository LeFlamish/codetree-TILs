#include <bits/stdc++.h>
using namespace std;
string s;
int ret;
bool flag;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            s[i] = '1';
            flag = true;
            break;
        }
    }
    if (!flag) {
        s[s.size() - 1] = '0';
    }
    for (int i = 0; i < s.size(); i++) {
        ret = (s[i] - '0') + 2 * ret;
    }
    cout << ret;
    return 0;
}