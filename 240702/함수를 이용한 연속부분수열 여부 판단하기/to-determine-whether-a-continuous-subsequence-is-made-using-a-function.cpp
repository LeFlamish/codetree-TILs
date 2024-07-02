#include <iostream>

#define MAX_N 100

using namespace std;

int n1, n2;
int a[MAX_N], b[MAX_N];

// n번째 인덱스부터 시작하는 n2길이의 a수열과
// b수열이 완전히 일치하는지 확인합니다..
bool IsSame(int n) {
    for(int i = 0; i < n2; i++)
        if(a[i + n] != b[i])
            return false;

    return true;
}

// b가 a의 연속부분수열인지 확인합니다.
bool IsSubsequence() {
    for(int i = 0; i <= n1 - n2; i++)
        if(IsSame(i))
            return true;
    
    return false;
}

int main() {
    // 변수 선언 및 입력:
    cin >> n1 >> n2;

    for(int i = 0; i < n1; i++)
        cin >> a[i];
    
    for(int i = 0; i < n2; i++)
        cin >> b[i];

    
    if(IsSubsequence())
        cout << "Yes";
    else
        cout << "No";

    return 0;
}