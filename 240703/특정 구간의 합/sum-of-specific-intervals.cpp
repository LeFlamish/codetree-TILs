#include <iostream>
using namespace std;

int n, m, temp, from, to, psum[102];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        psum[i] = psum[i-1] + temp;
    }
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        cout << psum[to] - psum[from-1] << '\n';
    }
    return 0;
}