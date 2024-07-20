#include <bits/stdc++.h>
using namespace std;
int N, B, money[1001], sum, ret, tmp;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        cin >> money[i];
    }
    sort(money, money + N);
    for (int i = 0; i < N; i++) {
        sum = 0;
        tmp = 0;
        for (int j = 0; j <= i; j++) {
            if (j == i) sum += money[j] / 2;
            else sum += money[j];
            tmp++;
        }
        if (sum > B) {
            tmp--;
            break;
        }
        ret = max(ret, tmp);
    }
    cout << ret;
    return 0;
}