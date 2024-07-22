#include <bits/stdc++.h>
using namespace std;
vector<int> V[21];
int K, N, ret;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> K >> N;
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            int member;
            cin >> member;
            V[member].push_back(j);
        }
    }
    for (int mem = 1; mem <= N; mem++) {
        for (int rival = 1; rival <= N; rival++) {
            bool flag = true;
            for (int game = 0; game < K; game++) {
                if (mem == rival) {
                    flag = false;
                    break;
                }

                if (V[mem][game] > V[rival][game]) {
                    flag = false;
                    break;
                }
            }
            if (flag) ret++;
        }
    }
    cout << ret;
    return 0;
}