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
        int mxX = INT_MIN, mnX = INT_MAX, mxY = INT_MIN, mnY = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (j == i) continue;
            mxX = max(mxX, V[j].X);
            mnX = min(mnX, V[j].X);
            mxY = max(mxY, V[j].Y);
            mnY = min(mnY, V[j].Y);
        }
        ret = min(ret, (mxX - mnX) * (mxY - mnY));
    }
    cout << ret;
    return 0;
}