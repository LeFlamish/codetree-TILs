#include <iostream>
#include <utility>
using namespace std;

int n, m;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    swap(n, m);
    cout << n << ' ' << m;
    return 0;
}