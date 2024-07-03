#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double a, b, ret;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b;
    cout << fixed << setprecision(2) << (a + b) / (a - b);
    return 0;
}