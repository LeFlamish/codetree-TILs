#include <iostream>
using namespace std;
int a;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a;
    char ans = (a == 1) ? 't' : 'f';
    cout << ans;
    return 0;
}