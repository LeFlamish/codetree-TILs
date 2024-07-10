#include <bits/stdc++.h>
using namespace std;
int N, M, A[101], B[101], tmp[101], cnt[101], ret;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= M; i++) {
        cin >> B[i];
        cnt[B[i]]++;
    }
    for (int i = 1; i <= N - M + 1; i++) {
        bool flag = true;
        memset(tmp, 0, sizeof(tmp));
        for (int j = 0; j < M; j++) {
            tmp[A[i + j]]++;
        }
        for (int i = 1; i < 101; i++) {
            if (tmp[i] != cnt[i]) {
                flag = false;
                break;
            }
        }
        if (flag) ret++;
    }
    cout << ret;
    return 0;
}