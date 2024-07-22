#include <bits/stdc++.h>
using namespace std;
int N, arr[100], ret;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int from = min(arr[i], arr[j]);
            int to = max(arr[i], arr[j]);
            for (int k = from; k <= to; k++) {
                if (abs(arr[i] - k) == abs(arr[j] - k)) ret++;
            }
        }
    }
    cout << ret;
    return 0;
}