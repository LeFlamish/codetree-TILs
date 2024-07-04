#include <iostream>
#include <string>
using namespace std;
int m1, m2, d1, d2, x, y, gap, cnt;
int num_of_days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int psum[13];
string target;
string weekday[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> m1 >> d1 >> m2 >> d2 >> target;
    for (int i = 1; i <= 12; i++) {
        psum[i] = psum[i-1] + num_of_days[i];
    }
    x = psum[m1-1] + d1;
    y = psum[m2-1] + d2;
    gap = y - x + 1;
    cnt++;
    if (target == "Tue") gap -= 1;
    else if (target == "Wed") gap -= 2;
    else if (target == "Thu") gap -= 3;
    else if (target == "Fri") gap -= 4;
    else if (target == "Sat") gap -= 5;
    else if (target == "Sun") gap -= 6;
    cnt += gap / 7;
    cout << cnt;
    return 0;
}