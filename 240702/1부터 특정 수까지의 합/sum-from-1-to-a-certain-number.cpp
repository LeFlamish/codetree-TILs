#include <iostream>
using namespace std;
int N;

int cal(int N) {
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += i;
    }
    return sum / 10;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    cout << cal(N);
    return 0;
}