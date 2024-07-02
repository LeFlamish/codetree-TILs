#include <iostream>
using namespace std;

int pow(int a, int b) {
    long long answer = 1;
    for (int i = 0; i < b; i++) {
        answer *= a;
    }
    return answer;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b;
    cin >> a >> b;
    cout << pow(a, b);
    return 0;
}