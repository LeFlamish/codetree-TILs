#include <iostream>
using namespace std;
int digit[20], n;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int i = 0;
    if (n == 0) digit[i] = 0;
    while (n > 0) {
        digit[i] = n % 2;
        n /= 2;
        i++;
    }
    if (n != 0) i--;
    for (int j = 0; j <= i; j++) {
        cout << digit[i - j];
    }
    return 0;
}