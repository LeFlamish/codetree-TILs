#include <iostream>
using namespace std;

int calculator(int a, char o, int b) {
    if (o == '+') return a + b;
    else if (o == '-') return a - b;
    else if (o == '/') return a / b;
    else if (o == '*') return a * b;
    else {
        cout << "False";
        exit(0);
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b;
    char o;
    cin >> a >> o >> b;
    int ret = calculator(a, o, b);
    cout << a << ' ' << o << ' ' << b << " = " << ret;
    return 0;
}