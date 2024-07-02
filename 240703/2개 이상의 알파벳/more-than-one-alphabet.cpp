#include <iostream>
#include <string>
using namespace std;

string s;
int cnt[26];

void read(string s) {
    for(int i = 0; i < s.size(); i++) {
        cnt[s[i] - 'a']++;
    }
}

bool counting() {
    int flag = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0) flag++;
    }
    if (flag >= 2) return true;
    else return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    read(s);
    if (counting()) cout << "Yes";
    else cout << "No";
    return 0;
}