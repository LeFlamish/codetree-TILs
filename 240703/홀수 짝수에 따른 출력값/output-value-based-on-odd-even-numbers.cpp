#include <iostream>
using namespace std;

int N;

int Sum(int n, int ret) {
    if (n == 1 || n == 2) return ret + n;

    return Sum(n - 2, ret + n);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    cout << Sum(N, 0);
    return 0;
}

// 코드트리 풀이
#include <iostream>

using namespace std;

// 1부터 n까지의 n과 홀짝이 같은 수들의 합을 반환합니다.
int GetNum(int n) {
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;

    // n과 홀짝이 같은 수만을 재귀함수로 호출합니다.
    return GetNum(n - 2) + n;
}

int main() {
    // 변수 선언 및 입력:
    int n;
    cin >> n;

    cout << GetNum(n);
    return 0;
}
