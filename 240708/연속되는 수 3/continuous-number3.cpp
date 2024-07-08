#include <bits/stdc++.h>
using namespace std;
int N, tmp, Minus, Plus;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        if (tmp < 0) Minus++;
        else Plus++;
    }
    cout << max(Minus, Plus);
    return 0;
}