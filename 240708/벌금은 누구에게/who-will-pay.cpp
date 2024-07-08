#include <bits/stdc++.h>
using namespace std;
int N, student[101], K, M, tmp, ret = -1;
bool flag;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        student[tmp]++;
        if (!flag) {
            for (int j = 1; j <= N; j++) {
                if (student[j] >= K) {
                    ret = j;
                    flag = true;
                }
            }
        }
    }
    cout << ret;
    return 0;
}