#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string x, y;
bool flag;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> x >> y;
    if (x.length() != y.length()) flag = false;
    else {
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        if (x == y) flag = true;
    }
    if (flag) cout << "Yes";
    else cout << "No";
    return 0;
}