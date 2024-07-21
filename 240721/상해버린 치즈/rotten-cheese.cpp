#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
#define when first
#define what second
int N, M, D, S, ret;
vector<P> record[51];
vector<int> problem;
int sick[51], cheese[51];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> D >> S;
    for (int i = 0; i < D; i++) {
        int p, m, t;
        cin >> p >> m >> t;
        record[p].push_back({ t, m });
    }
    for (int i = 0; i < S; i++) {
        int p, t;
        cin >> p >> t;
        sick[p] = t;
    }
    for (int i = 1; i <= N; i++) {
        if (sick[i]) {
            for (int j = 0; j < record[i].size(); j++) {
                if (record[i][j].when < sick[i]) cheese[record[i][j].what]++;
            }
        }
    }
    for (int i = 1; i <= M; i++) {
        if (cheese[i] == S) problem.push_back(i);
    }
    for (int i = 0; i < problem.size(); i++) {
        int cnt = 0;
        for (int p = 1; p <= N; p++) {
            for (int t = 0; t < record[p].size(); t++) {
                if (record[p][t].what == problem[i]) {
                    cnt++;
                    break;
                }
            }
        }
        ret = max(cnt, ret);
    }
    cout << ret;
    return 0;
}