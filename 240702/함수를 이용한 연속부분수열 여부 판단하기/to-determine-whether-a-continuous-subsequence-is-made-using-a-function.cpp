#include <iostream>
using namespace std;
int A[101], B[101], n1, n2;

void subseq() {
    for (int i = 0; i < n1 - n2 + 1; i++) {
        bool flag = true;
        for (int j = 0; j < n2; j++) {
            if (A[i + j] != B[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Yes";
            return;
        }
    }
    cout << "No";
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n1 >> n2;
    for (int i = 0; i < n1; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n2; i++) {
        cin >> B[i];
    }
    subseq();
    return 0;
}