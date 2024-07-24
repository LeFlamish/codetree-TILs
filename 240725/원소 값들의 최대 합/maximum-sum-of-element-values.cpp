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

// 코드트리 풀이
#include <iostream>
#include <algorithm>

#define MAX_N 100

using namespace std;

int n, m;
int arr[MAX_N + 1];

int main() {
    // 입력
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    int ans = 0;
    // 어느 지점에서 시작할지 전부 시도해 봅니다.
    // 모든 경우의 수에 대해 최대가 되도록 하는 수를 계산합니다.
    for(int i = 1; i <= n; i++) {
        // 시작점은 i입니다.
        int sum_element = 0;
        int cur = i;

        // m번 움직임을 반복합니다.
        for(int j = 1; j <= m; j++) {
            sum_element += arr[cur];
            cur = arr[cur];
        }
        
        ans = max(ans, sum_element);
    }

    cout << ans;
    return 0;
}
