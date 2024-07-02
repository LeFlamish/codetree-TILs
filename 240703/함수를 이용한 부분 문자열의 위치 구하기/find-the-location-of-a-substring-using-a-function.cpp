#include <iostream>
#include <string>
using namespace std;

string input, purpose;

int finding(string input, string purpose) {
    long long pos = 0;
    if ((pos = input.find(purpose)) == string::npos) return -1;
    else return pos;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> input >> purpose;
    cout << finding(input, purpose);
    return 0;
}