#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
#define present first
#define deli second
int N, B, ret, total, cnt;
vector<P> V;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        V.push_back({ x, y });
    }
    for (int i = 0; i < N; i++) {
        total = 0;
        cnt = 0;
        for (int j = 0; j < N; j++) {
            int tmp;
            if (i == j) tmp = V[j].present / 2 + V[j].deli;
            else tmp = V[j].present + V[j].deli;

            total += tmp;
            if (total > B) total -= tmp;
            else cnt++;
        }
        ret = max(ret, cnt);
    }
    cout << ret;
    return 0;
}