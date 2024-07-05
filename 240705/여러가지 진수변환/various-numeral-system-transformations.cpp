#include <iostream>
using namespace std;
int N, B;
int ret[10];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> B;
    int i = 0;
    while (N > 0) {
        ret[i] = N % B;
        N /= B;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << ret[j];
    }
    return 0;
}