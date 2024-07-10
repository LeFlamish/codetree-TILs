#include <bits/stdc++.h>
using namespace std;
int N, M, A[101], B[101], tmp[101], cnt[101], ret;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= M; i++) {
        cin >> B[i];
        cnt[B[i]]++;
    }
    for (int i = 1; i <= N - M + 1; i++) {
        bool flag = true;
        memset(tmp, 0, sizeof(tmp));
        for (int j = 0; j < M; j++) {
            tmp[A[i + j]]++;
        }
        for (int i = 1; i < 101; i++) {
            if (tmp[i] != cnt[i]) {
                flag = false;
                break;
            }
        }
        if (flag) ret++;
    }
    cout << ret;
    return 0;
}

// 코드트리 풀이 : 정렬
#include <iostream>
#include <algorithm>

#define MAX_N 100

using namespace std;

int n, m;
int arr1[MAX_N], arr2[MAX_N];
int tmp[MAX_N];

int main() {
    // 입력
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr1[i];
	for(int i = 0; i < m; i++)
        cin >> arr2[i];
	
	sort(arr2, arr2 + m);
	
    // 모든 구간의 시작점을 잡아봅니다.
    int cnt = 0;
    for(int i = 0; i <= n - m; i++) {
        for(int j = 0; j < m; j++)
            tmp[j] = arr1[i + j];
		sort(tmp, tmp + m);
		
		bool issame = true;
		for(int j = 0; j < m; j++)
			if(tmp[j] != arr2[j]) {
				issame = false;
				break;
			}
		
		if(issame)
			cnt++;
    }
                        
    cout << cnt;
    return 0;
}
