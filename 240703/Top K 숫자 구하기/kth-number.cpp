#include <iostream>
#include <algorithm>
using namespace std;

int N, k, arr[1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> k;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    cout << arr[k-1];
    return 0;
}