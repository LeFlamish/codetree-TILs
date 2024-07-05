#include <iostream>
#include <string>
using namespace std;
string s;
int ret;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        ret = s[i] - '0' + ret*2;
    }
    cout << ret;
    return 0;
}