#include <bits/stdc++.h>
using namespace std;
int N, position, G, H, ret, mx = INT_MIN, mn = INT_MAX;
char arr[101], C;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    memset(arr, '\0', sizeof(arr));
    for (int i = 0; i < N; i++) {
        cin >> position >> C;
        mx = max(position, mx);
        mn = min(position, mn);
        arr[position] = C;
    }
    for (int i = mn; i <= mx; i++) {
        for (int j = i; j <= mx; j++) {
            G = 0; H = 0;
            if (arr[i] != '\0' && arr[j] != '\0') {
                for (int k = i; k <= j; k++) {
                    if (arr[k] == 'G') G++;
                    else if (arr[k] == 'H') H++;
                }
            }
            if ((G > 0 && H > 0 && G == H) || (G > 0 && H == 0) || (G == 0 && H > 0)) {
                ret = max(ret, j - i);
            }
        }
    }
    cout << ret;
    return 0;
}