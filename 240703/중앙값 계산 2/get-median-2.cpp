#include <bits/stdc++.h>
using namespace std;
int n, arr[101], middle;
vector<int> V;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        V.push_back(arr[i]);
        if (i & 1) {
            middle = (1 + i) / 2;
            sort(V.begin(), V.end());
            cout << V[middle - 1] << ' ';
        }
    }
    return 0;
}