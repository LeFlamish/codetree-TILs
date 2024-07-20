#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
#define X first
#define Y second
int N, ret = INT_MAX;
vector<P> V;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    V.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i].X >> V[i].Y;
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ret = min(ret, (V[i].X - V[j].X) * (V[i].X - V[j].X) + (V[i].Y - V[j].Y) * (V[i].Y - V[j].Y));
        }
    }
    cout << ret;
    return 0;
}