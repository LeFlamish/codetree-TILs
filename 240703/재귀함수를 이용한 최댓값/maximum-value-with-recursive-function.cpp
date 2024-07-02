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