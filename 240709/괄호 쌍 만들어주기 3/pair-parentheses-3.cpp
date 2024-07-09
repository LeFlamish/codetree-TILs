#include <bits/stdc++.h>
using namespace std;
string s;
int ret;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] == ')') ret++;
            }
        }
    }
    cout << ret; 
    return 0;
}