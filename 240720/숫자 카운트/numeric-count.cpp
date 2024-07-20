#include <bits/stdc++.h>
using namespace std;
int N, guess, strike, ball, ret;
bool answer[1000];

int First(int n) {
    return n / 100;
}
int Second(int n) {
    return (n % 100) / 10;
}
int Third(int n) {
    return n % 10;
}

int checkStrike(int x, int y) {
    int tmp = 0;
    if (First(x) == First(y)) tmp++;
    if (Second(x) == Second(y)) tmp++;
    if (Third(x) == Third(y)) tmp++;
    return tmp;
}

int checkBall(int x, int y) {
    int tmp = 0;
    if (First(x) == Second(y) || First(x) == Third(y)) tmp++;
    if (Second(x) == First(y) || Second(x) == Third(y)) tmp++;
    if (Third(x) == First(y) || Third(x) == Second(y)) tmp++;
    return tmp;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    fill(answer + 123, answer + 988, true);
    for (int i = 123; i < 988; i++) {
        if (First(i) == Second(i) || Second(i) == Third(i) || Third(i) == First(i)) answer[i] = false;
        if (Second(i) == 0 || Third(i) == 0) answer[i] = false;
    }
    for (int i = 0; i < N; i++) {
        cin >> guess >> strike >> ball;
        for (int i = 111; i < 1000; i++) {
            if (checkStrike(guess, i) == strike && checkBall(guess, i) == ball) continue;
            answer[i] = false;
        }
    }
    for (int i = 123; i < 988; i++) {
        if (answer[i]) ret++;
    }
    cout << ret;
    return 0;
}

// 코드트리 풀이
#include <iostream>

#define MAX_N 10

using namespace std;

int n;
int a[MAX_N], b[MAX_N], c[MAX_N];

int main() {
    // 입력
    cin >> n;
	for(int i = 0; i < n; i++)
    	cin >> a[i] >> b[i] >> c[i];
    
    // 모든 숫자를 다 만들어 봅니다. (백의 자리수가 i, 십의 자리수가 j, 일의 자리수가 k)
    int cnt = 0;
    for(int i = 1; i <= 9; i++)
        for(int j = 1; j <= 9; j++)
            for(int k = 1; k <= 9; k++) {
				// 같은 수가 있는지 확인합니다.
				if(i == j || j == k || k == i)
					continue;
				
				// 해당 숫자가 정답일때, 모든 입력에 대해 올바른 답이 나왔는지 확인합니다.
				bool succeeded = true;
				for(int q = 0; q < n; q++) {
					// x : a[q]의 백의 자릿수, y : 십의 자릿수, z : 일의 자릿수
					int x = a[q] / 100;
					int y = a[q] / 10 % 10;
					int z = a[q] % 10;
					// cnt1 : 1번 카운트, cnt2 : 2번 카운트
					int cnt1 = 0, cnt2 = 0;
					if(x == i)
						cnt1++;
					if(y == j)
						cnt1++;
					if(z == k)
						cnt1++;
					if(x == j || x == k)
						cnt2++;
					if(y == i || y == k)
						cnt2++;
					if(z == i || z == j)
						cnt2++;
					
					// 만약 카운트 수가 다르다면 해당 숫자는 정답이 될 수 없습니다.
					if(cnt1 != b[q] || cnt2 != c[q]) {
						succeeded = false;
						break;
					}
				}
				
				if(succeeded) cnt++;
            }
    
    cout << cnt;
	
    return 0;
}
