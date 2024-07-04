#include <iostream>
#include <string>
using namespace std;
int m1, m2, d1, d2, x, y;
int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int psum[13];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> m1 >> d1 >> m2 >> d2;
    for (int i = 1; i <= 12; i++) {
        psum[i] = psum[i-1] + num_of_days[i];
    }
    x = psum[m1-1] + d1;
    y = psum[m2-1] + d2;
    cout << y - x + 1;
    return 0;
}