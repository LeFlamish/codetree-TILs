#include <iostream>
using namespace std;
int a;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    if (a % 3 == 0) cout << "YES\n";
    else cout << "NO\n";
    if (a % 5 == 0) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}