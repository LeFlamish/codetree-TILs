#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[1001], ret;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N * 2; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + 2 * N);
    for (int i = 0; i < N; i++) {
        ret = max(ret, arr[i] + arr[2*N - 1 - i]);
    }
    cout << ret;
    return 0;
}