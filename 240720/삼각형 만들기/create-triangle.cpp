#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
#define X first
#define Y second
int N, ret;
vector<P> V;

bool isTri(P x, P y, P z) {
    if ((x.X == y.X && y.X == z.X && z.X == x.X) || (x.Y == y.Y && y.Y == z.Y && z.Y == x.Y)) return false;
    if ((x.X != y.X && y.X != z.X && z.X != x.X) || (x.Y != y.Y && y.Y != z.Y && z.Y != x.Y)) return false;
    return true;
}

int Area(P x, P y, P z) {
    int mxX = INT_MIN, mnX = INT_MAX, mxY = INT_MIN, mnY = INT_MAX;
    mxX = max(max(x.X, y.X), z.X);
    mnX = min(min(x.X, y.X), z.X);
    mxY = max(max(x.Y, y.Y), z.Y);
    mnY = min(min(x.Y, y.Y), z.Y);
    return (mxX - mnX) * (mxY - mnY);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    V.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i].X >> V[i].Y;
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (isTri(V[i], V[j], V[k])) {
                    ret = max(ret, Area(V[i], V[j], V[k]));
                }
            }
        }
    }
    cout << ret;
    return 0;
}