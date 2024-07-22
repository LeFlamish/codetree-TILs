#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
#define Start first
#define End second
int N, line[101], ret;
vector<P> V;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        V.push_back({ s, e });
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                memset(line, 0, sizeof(line));
                for (int x = 0; x < N; x++) {
                    if (x == i || x == j || x == k) continue;

                    for (int y = V[x].Start; y <= V[x].End; y++) line[y]++;
                }
                bool flag = true;
                for (int y = 0; y < 101; y++) {
                    if (line[y] > 1) {
                        flag = false;
                        break;
                    }
                }
                if (flag) ret++;
            }
        }
    }
    cout << ret;
    return 0;
}