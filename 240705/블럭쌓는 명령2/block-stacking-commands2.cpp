#include <iostream>
using namespace std;
int arr[101], N, K;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int from, to;
        cin >> from >> to;
        for (int j = from; j <= to; j++) {
            arr[j]++;
        }
    }
    int Max = arr[1];
    for (int i = 2; i <= N; i++) {
        if (Max < arr[i]) Max = arr[i];
    }
    cout << Max;
    return 0;
}