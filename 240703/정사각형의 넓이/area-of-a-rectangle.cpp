#include <iostream>
using namespace std;
int n;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    if (n < 5) cout << "tiny\n" << n * n;
    else cout << n * n;
    return 0;
}