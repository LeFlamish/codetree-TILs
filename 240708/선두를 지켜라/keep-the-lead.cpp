#include <bits/stdc++.h>
using namespace std;
int N, M, A[1000001], B[1000001], v, t, idx = 1, total, cnt;
char Prev, Cur;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> v >> t;
        total += t;
        for (int j = 0; j < t; j++) {
            A[idx + j] = A[idx + j - 1] + v;
        }
        idx += t;
    }
    idx = 1;
    for (int i = 0; i < M; i++) {
        cin >> v >> t;
        for (int j = 0; j < t; j++) {
            B[idx + j] = B[idx + j - 1] + v;
        }
        idx += t;
    }
    for (int i = 0; i <= total; i++) {
        if (A[i] < B[i]) Cur = 'B';
        else if (A[i] > B[i]) Cur = 'A';
        if (Prev != Cur) cnt++;
        Prev = Cur;
    }
    if (cnt) cout << cnt - 1;
    else cout << 0;
    return 0;
}