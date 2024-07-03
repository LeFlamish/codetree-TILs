#include <bits/stdc++.h>
using namespace std;
int n, arr[101], middle;
vector<int> V;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        V.push_back(arr[i]);
        if (i & 1) {
            middle = (1 + i) / 2;
            sort(V.begin(), V.end());
            cout << V[middle - 1] << ' ';
        }
    }
    return 0;
}

// 코드트리 풀이
#include <iostream>
#include <algorithm>

#define MAX_N 100

using namespace std;

// 변수 선언
int n;
int arr[MAX_N];

int main() {
    // 입력:
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    // 홀수 번째 수를 지날때마다 정렬을 진행한 후 가운데 값을 출력합니다.
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            // 오름차순 정렬을 진행합니다.
            sort(arr, arr + i + 1);
            // 가운데 값을 출력합니다.
            cout << arr[i / 2] << " ";
        }
    }
    return 0;
}
