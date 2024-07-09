#include <bits/stdc++.h>
using namespace std;
int N, M, A[1000001], B[1000001], v, t, idx = 1, total, Prev, Cur, ret; // 1 ; A, 2 : B, 0 : A, B
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int a = 0; a < N; a++) {
        cin >> v >> t;
        total += t;
        for (int i = 0; i < t; i++) {
            A[idx] = A[idx - 1] + v;
            idx++;
        }
    }
    idx = 1;
    for (int b = 0; b < M; b++) {
        cin >> v >> t;
        for (int i = 0; i < t; i++) {
            B[idx] = B[idx - 1] + v;
            idx++;
        }
    }
    for (int i = 0; i <= total; i++) {
        if (A[i] > B[i]) Cur = 1;
        else if (A[i] < B[i]) Cur = 2;
        else Cur = 0;
        if (Prev != Cur) ret++;
        Prev = Cur;
    }
    cout << ret;
    return 0;
}