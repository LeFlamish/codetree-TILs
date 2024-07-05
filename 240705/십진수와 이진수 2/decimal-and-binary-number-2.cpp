#include <iostream>
using namespace std;
string input;
int ret[14], temp;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> input;
    for (int i = 0; i < input.size(); i++) {
        temp = input[i] - '0' + temp * 2;
    }
    temp *= 17;
    int i = 0;
    while(temp > 0) {
        ret[i] = temp % 2;
        temp /= 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << ret[j];
    }
    return 0;
}