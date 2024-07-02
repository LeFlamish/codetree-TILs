#include <iostream>
using namespace std;

int a, b, cnt;

bool existThree(int n) {
    while(n > 0) {
        if ((n % 10) % 3 == 0) {
            return true;
        }
        n /= 10;
    }
    return false;
}

bool divThree(int n) {
    if (!(n % 3)) return true;
    else return false;
}

bool checkNum(int n) {
    if (existThree(n) || divThree(n)) return true;
    else return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b; 
    for (int i = a; i <= b; i++) {
        if (checkNum(i)) cnt++;
    }
    cout << cnt;
    return 0;
}