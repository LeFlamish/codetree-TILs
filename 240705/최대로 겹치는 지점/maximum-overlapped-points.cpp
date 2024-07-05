#include <iostream>
using namespace std;
int n, arr[101];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = x; j <= y; j++) {
            arr[j]++;
        }
    }
    int Max = arr[1];
    for (int i = 2; i <= 100; i++) {
        if (Max < arr[i]) Max = arr[i];
    }
    cout << Max;
    return 0;
}