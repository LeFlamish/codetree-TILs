#include <iostream>
using namespace std;

void printHello(int N) {
    if (N == 0) return;

    cout << "HelloWorld\n";
    printHello(N-1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    printHello(N);
    return 0;
}

// 코드트리 풀이 : 재귀함수 호출 위치가 다름.
#include <iostream>

using namespace std;

void PrintString(int n) { // 1부터 n번째 줄까지 문자열을 출력하는 함수
    if(n == 0)            // n이 0이라면, 더 이상 진행하지 않고
        return;           // 퇴각합니다.

    PrintString(n - 1);   // 1부터 n - 1번째 줄까지 출력하는 함수
    cout << "HelloWorld" << endl;
}

int main() {
    // 변수 선언 및 입력:
    int n;
    cin >> n;

    PrintString(n);
    return 0;
}
