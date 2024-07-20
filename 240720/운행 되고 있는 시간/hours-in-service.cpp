#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int N, ret = INT_MIN;
vector<P> V;
bool Time[1000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    V.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i].first >> V[i].second;
    }
    for (int i = 0; i < N; i++) {
        int tmp = 0;
        memset(Time, false, sizeof(Time));
        for (int j = 0; j < N; j++) {
            if (j == i) continue;
            for (int k = V[j].first; k < V[j].second; k++) Time[k] = true;
        }
        for (int k = 1; k < 1000; k++) {
            if (Time[k]) tmp++;
        }
        ret = max(ret, tmp);
    }
    cout << ret;
    return 0;
}