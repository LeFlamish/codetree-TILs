#include <bits/stdc++.h>
using namespace std;
string s;
int ret;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == '(' && s[i + 1] == '(') {
            for (int j = i + 2; j < s.size(); j++) {
                if (s[j] == ')' && s[j + 1] == ')') ret++;
            }
        }
    }
    cout << ret;
    return 0;
}