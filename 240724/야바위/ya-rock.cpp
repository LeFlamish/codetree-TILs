#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> T;
int N, from, to, open, cup[4], ret;
vector<T> V;

void swap(int i, int j) {
    int tmp = cup[i];
    cup[i] = cup[j];
    cup[j] = tmp;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> from >> to >> open;
        V.push_back({ from, to, open });
    }
    for (int i = 1; i <= 3; i++) {
        int cnt = 0;
        memset(cup, 0, sizeof(cup));
        cup[i] = 1;
        for (int j = 0; j < N; j++) {
            int change1 = get<0>(V[j]);
            int change2 = get<1>(V[j]);
            int Open = get<2>(V[j]);
            swap(change1, change2);
            cnt += cup[Open];
        }
        ret = max(ret, cnt);
    }
    cout << ret;
    return 0;
}