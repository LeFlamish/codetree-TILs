#include <bits/stdc++.h>
using namespace std;
int n, m, A[1000001], B[1000001], idx = 1, t, total, ret, tmp, idxA, idxB;
char d;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int a = 0; a < n; a++) {
        cin >> t >> d;
        total += t;
        if (d == 'R') {
            for (int i = 0; i < t; i++) {
                A[idx] = A[idx - 1] + 1;
                idx++;
            }
        }
        else {
            for (int i = 0; i < t; i++) {
                A[idx] = A[idx - 1] - 1;
                idx++;
            }
        }
    }
    idxA = idx;
    idx = 1;
    for (int b = 0; b < m; b++) {
        cin >> t >> d;
        tmp += t;;
        if (d == 'R') {
            for (int i = 0; i < t; i++) {
                B[idx] = B[idx - 1] + 1;
                idx++;
            }
        }
        else {
            for (int i = 0; i < t; i++) {
                B[idx] = B[idx - 1] - 1;
                idx++;
            }
        }
    }
    idxB = idx;
    if (idxA > idxB) for (int i = idxB; i < idxA; i++) B[i] = B[i - 1];
    else if (idxA < idxB) for (int i = idxA; i < idxB; i++) A[i] = A[i - 1];
    total = max(total, tmp);
    for (int i = 1; i <= total; i++) {
        if (A[i - 1] != B[i - 1] && A[i] == B[i]) ret++;
    }
    cout << ret;
    return 0;
}