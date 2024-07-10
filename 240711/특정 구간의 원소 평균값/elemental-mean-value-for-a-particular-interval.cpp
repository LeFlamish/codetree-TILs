#include <bits/stdc++.h>
using namespace std;
int N, arr[101], ret;
double tmp;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            tmp = 0;
            for (int k = i; k <= j; k++) {
                tmp += arr[k];
            }
            tmp /= (j - i + 1);
            for (int k = i; k <= j; k++) {
                if (arr[k] == tmp) {
                    ret++;
                    break;
                }
            }
        }
    }
    cout << ret;
    return 0;
}