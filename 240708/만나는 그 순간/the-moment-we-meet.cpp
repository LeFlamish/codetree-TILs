#include <bits/stdc++.h>
using namespace std;
int N, M, A[1000001], B[1000001], t, idx = 1, total;
char d;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> d >> t;
        total += t;
        if (d == 'R') {
            for (int j = 0; j < t; j++) {
                A[idx] = A[idx - 1] + 1;
                idx++;
            }
        }
        else {
            for (int j = 0; j < t; j++) {
                A[idx] = A[idx - 1] - 1;
                idx++;
            }
        }
    }
    idx = 1;
    for (int i = 0; i < M; i++) {
        cin >> d >> t;
        if (d == 'R') {
            for (int j = 0; j < t; j++) {
                B[idx] = B[idx - 1] + 1;
                idx++;
            }
        }
        else {
            for (int j = 0; j < t; j++) {
                B[idx] = B[idx - 1] - 1;
                idx++;
            }
        }
    }
    for (int i = 1; i <= total; i++) {
        if (A[i] == B[i]) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}