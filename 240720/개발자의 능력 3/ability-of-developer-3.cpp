#include <bits/stdc++.h>
using namespace std;
int ability[6], sum, tmp, ret = INT_MAX;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 6; i++) {
        cin >> ability[i];
        sum += ability[i];
    }
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            for (int k = j + 1; k < 6; k++) {
                tmp = sum -  2*(ability[i] + ability[j] + ability[k]);
                ret = min(abs(tmp), ret);
            }
        }
    }
    cout << ret;
    return 0;
}