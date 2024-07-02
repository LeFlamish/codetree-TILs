#include <iostream>
using namespace std;

int n, m, arr[101], ret;

void process(int& m) {
    if(m & 1) m--;
    else m /= 2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ret += arr[m - 1];
    while(m != 1) {
        process(m);
        ret += arr[m - 1];
    }
    cout << ret;
    return 0;
}