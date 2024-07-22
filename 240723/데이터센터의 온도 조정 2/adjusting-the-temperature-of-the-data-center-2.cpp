#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
vector<P> V;
int N, C, G, H, ret;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> C >> G >> H;
    for (int i = 0; i < N; i++) {
        int Ta, Tb, work = 0;
        cin >> Ta >> Tb;
        V.push_back({ Ta, Tb });
    }
    for (int t = -1; t <= 1001; t++) {
        int work = 0;
        for (int i = 0; i < N; i++) {
            int Ta = V[i].first, Tb = V[i].second;
            if (t < Ta) work += C;
            else if (Ta <= t && Tb >= t) work += G;
            else if (Tb < t) work += H;
        }
        ret = max(work, ret);
    }
    cout << ret;
    return 0;
}