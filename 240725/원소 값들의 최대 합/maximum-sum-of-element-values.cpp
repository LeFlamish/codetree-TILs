#include <bits/stdc++.h>
using namespace std;
int N, M, arr[101], ret;

int move(int index, int cnt) {
    if (cnt == M) return arr[index];
    int answer = arr[index];
    return answer + move(arr[index], cnt + 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int start = 1; start <= N; start++) {
        ret = max(ret, move(start, 1));
    }
    cout << ret;
    return 0;
}