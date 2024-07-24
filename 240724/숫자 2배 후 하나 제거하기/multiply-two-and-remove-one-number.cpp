#include <bits/stdc++.h>
using namespace std;
int N, arr[101], ret = INT_MAX;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++) { // 2배가 되는 원소
        arr[i] *= 2;
        for (int j = 0; j < N; j++) { // 제외되는 원소
            int tmp = 0;
            for (int k = 0; k < N - 1; k++) {
                if (k == j) continue;
                if (k + 1 == j) {
                    tmp += abs(arr[k] - arr[k + 2]);
                }
                else {
                    tmp += abs(arr[k] - arr[k + 1]);
                }
            }
            ret = min(ret, tmp);
        }
        arr[i] /= 2;
    }
    cout << ret;
    return 0;
}