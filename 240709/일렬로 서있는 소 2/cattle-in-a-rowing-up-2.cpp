#include <bits/stdc++.h>
using namespace std;
int N, cow[101], ret;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cow[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (cow[k] >= cow[j] && cow[j] >= cow[i]) ret++;
            }
        }
    }
    cout << ret;
    return 0;
}