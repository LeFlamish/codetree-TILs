#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    sort(s.begin(), s.end());
    for (char x : s) cout << x;
    return 0;
}