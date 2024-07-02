#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[101];

int findMax(int n, int ret) {
    if (n == 0) return max(arr[n], ret);
    ret = max(arr[n], ret);
    return max(findMax(n - 1, ret), ret);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << findMax(N, 0);
    return 0;
}

// 코드트리 풀이
#include <iostream>
#include <algorithm>

#define MAX_N 100

using namespace std;

int arr[MAX_N];

// a번째 까지 인덱스의 숫자 중에 가장 큰 값을 반환합니다.
int MaxValue(int a) {
    if(a == 0)
        return arr[0];

    return max(MaxValue(a - 1), arr[a]);
}

int main() {
    // 변수 선언 및 입력:
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << MaxValue(n - 1);

    return 0;
}
