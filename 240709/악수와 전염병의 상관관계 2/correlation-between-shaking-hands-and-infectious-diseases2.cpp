#include <bits/stdc++.h>
using namespace std;
int N, K, P, T, dev[101], hand[101], t, x, y, process[251][2], maxT;
bool infect[101];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K >> P >> T;
    infect[P] = true;
    for (int i = 0; i < T; i++) {
        cin >> t >> x >> y;
        maxT = max(maxT, t);
        process[t][0] = x;
        process[t][1] = y;
    }
    for (int i = 1; i <= maxT; i++) {
        if (process[i][0] && process[i][1]) {
            int P1 = process[i][0], P2 = process[i][1];
            hand[P1]++;
            hand[P2]++;
            if (infect[P1]) {
                if (hand[P1] <= K) infect[P2] = true;
            }
            else if (infect[P2]) {
                if (hand[P2] <= K) infect[P1] = true;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << infect[i];
    }
    return 0;
}