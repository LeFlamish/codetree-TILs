#include <iostream>
#include <string>
using namespace std;
int a, b, temp, ret[10];
string n;
int main() {
    cin >> a >> b >> n;
    for (int i = 0; i < n.size(); i++) {
        temp = n[i] - '0' + a * temp;
    }
    int i = 0;
    while(temp > 0) {
        ret[i] = temp % b;
        temp /= b;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << ret[j];
    }
    return 0;
}