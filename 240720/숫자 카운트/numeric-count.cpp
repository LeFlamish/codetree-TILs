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