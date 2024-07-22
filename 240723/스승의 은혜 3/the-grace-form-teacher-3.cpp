#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
#define present first
#define deli second
int N, B, ret, total, cnt;
vector<P> V;

bool compare(const P& x, const P& y) {
    if (x.present + x.deli == y.present + y.deli) {
        if (x.present == y.present) return x.deli < y.deli;
        return x.present < y.present;
    }
    return x.present + x.deli < y.present + y.deli;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        V.push_back({ x, y });
    }
    sort(V.begin(), V.end(), compare);
    for (int i = 0; i < N; i++) {
        total = 0;
        cnt = 0;
        for (int j = 0; j <= i; j++) {
            int tmp;
            if (i == j) tmp = V[j].present / 2 + V[j].deli;
            else tmp = V[j].present + V[j].deli;

            total += tmp;
            cnt++;
        }
        if (total > B) break;
        ret = max(ret, cnt);
    }
    cout << ret;
    return 0;
}