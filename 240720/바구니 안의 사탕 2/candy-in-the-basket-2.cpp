#include <bits/stdc++.h>
using namespace std;
int N, K, arr[101], ret, tmp;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int candy, position;
        cin >> candy >> position;
        arr[position] += candy;
    }
    if (K > 49) {
        for (int i = 0; i < 101; i++) {
            ret += arr[i];
        }
        cout << ret;
    }
    else {
        for (int i = K; i <= 100 - K; i++) {
            tmp = 0;
            for (int j = i - K; j <= i + K; j++) {
                tmp += arr[j];
            }
            ret = max(tmp, ret);
        }
        cout << ret;
    }
    return 0;
}