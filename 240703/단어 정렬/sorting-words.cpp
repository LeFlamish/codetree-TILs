#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string arr[101];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (string x : arr) cout << x << '\n';
    return 0;
}