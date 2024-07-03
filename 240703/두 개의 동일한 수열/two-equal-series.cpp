#include <iostream>
#include <algorithm>
using namespace std;

int n, A[101], B[101];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    sort(A, A + n);
    sort(B, B + n);
    for (int i = 0; i < n; i++) {
        if (A[i] != B[i]) {
            cout << "No";
            exit(0);
        }
    }
    cout << "Yes";
    return 0;
}