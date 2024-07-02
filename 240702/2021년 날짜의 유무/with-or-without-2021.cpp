#include <iostream>
using namespace std;
int M, D;

bool existDate(int month, int day) {
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return true;
    else {
        if (day > 30) return false;
        if (month == 2) {
            if (day > 28) return false;
        }
        return true;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> M >> D;
    if (existDate(M, D)) cout << "Yes";
    else cout << "No";
    return 0;
}