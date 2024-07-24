#include <bits/stdc++.h>
using namespace std;
int N, board[3][3], visited[10], ret;
bool team[10][10];

bool checkHorizontal(int start) {
    memset(visited, 0, sizeof(visited));
    int a = 0, b = 0;
    for (int i = 0; i < 3; i++) {
        visited[board[start][i]]++;
    }
    for (int i = 1; i <= 9; i++) {
        if (visited[i] == 2) a = i;
        if (visited[i] == 1) b = i;
    }
    if (a && b) {
        if (!team[a][b] && !team[b][a]) {
            team[a][b] = true;
            team[b][a] = true;
            return true;
        }
    }
    return false;
}

bool checkVertical(int start) {
    memset(visited, 0, sizeof(visited));
    int a = 0, b = 0;
    for (int i = 0; i < 3; i++) {
        visited[board[i][start]]++;
    }
    for (int i = 1; i <= 9; i++) {
        if (visited[i] == 2) a = i;
        if (visited[i] == 1) b = i;
    }
    if (a && b) {
        if (!team[a][b] && !team[b][a]) {
            team[a][b] = true;
            team[b][a] = true;
            return true;
        }
    }
    return false;
}

bool checkDiagonal1() {
    memset(visited, 0, sizeof(visited));
    int a = 0, b = 0;
    for (int i = 0; i < 3; i++) {
        visited[board[i][i]]++;
    }
    for (int i = 1; i <= 9; i++) {
        if (visited[i] == 2) a = i;
        if (visited[i] == 1) b = i;
    }
    if (a && b) {
        if (!team[a][b] && !team[b][a]) {
            team[a][b] = true;
            team[b][a] = true;
            return true;
        }
    }
    return false;
}

bool checkDiagonal2() {
    memset(visited, 0, sizeof(visited));
    int a = 0, b = 0;
    for (int i = 0; i < 3; i++) {
        visited[board[i][2 - i]]++;
    }
    for (int i = 1; i <= 9; i++) {
        if (visited[i] == 2) a = i;
        if (visited[i] == 1) b = i;
    }
    if (a && b) {
        if (!team[a][b] && !team[b][a]) {
            team[a][b] = true;
            team[b][a] = true;
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 3; i++) {
        cin >> N;
        board[i][0] = N / 100;
        board[i][1] = (N % 100) / 10;
        board[i][2] = N % 10;
    }
    for (int i = 0; i < 3; i++) {
        if (checkHorizontal(i)) ret++;
        if (checkVertical(i)) ret++;
    }
    if (checkDiagonal1()) ret++;
    if (checkDiagonal2()) ret++;
    cout << ret;
    return 0;
}