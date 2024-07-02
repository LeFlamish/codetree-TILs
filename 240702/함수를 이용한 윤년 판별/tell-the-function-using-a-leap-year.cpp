#include <iostream>
using namespace std;
int y;

bool isYear(int n) {
    if (n % 4) return false;
    else {
        if (!(n % 100) && n % 400) return false;
        else return true;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> y;
    if (isYear(y)) cout << "true";
    else cout << "false";
    return 0;
}