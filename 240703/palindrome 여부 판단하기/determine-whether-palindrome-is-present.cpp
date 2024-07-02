#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s;

bool isPalindrome(string s) {
    string temp = s;
    reverse(temp.begin(), temp.end());
    if (temp == s) return true;
    else return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    if (isPalindrome(s)) cout << "Yes";
    else cout << "No";
    return 0;
}