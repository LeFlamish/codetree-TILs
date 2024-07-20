#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int N, ret;
vector<P> V;
bool flag;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    V.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i].first >> V[i].second;
    }
    for (int i = 0; i < N; i++) {
        flag = false;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (V[i].first > V[j].first) {
                if (V[i].second < V[j].second) {
                    flag = true;
                }
            }
            else {
                if (V[i].second > V[j].second) {
                    flag = true;
                }
            }
        }
        if (!flag) ret++;
    }
    cout << ret;
    return 0;
}