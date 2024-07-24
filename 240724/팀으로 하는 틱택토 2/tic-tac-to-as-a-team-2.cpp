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

// 코드트리 풀이
#include <iostream>
#include <string>
#include <algorithm>

#define MAX_A 3
#define MAX_X 9

using namespace std;

string inp[MAX_A];
int board[MAX_A][MAX_A];

int main() {
    // 입력
    for(int i = 0; i < MAX_A; i++)
        cin >> inp[i];
    
    for(int i = 0; i < MAX_A; i++)
        for(int j = 0; j < MAX_A; j++)
            board[i][j] = inp[i][j] - '0';

    int ans = 0;

    // 모든 쌍에 대해 전부 시도해 봅니다.
    for(int i = 1; i <= MAX_X; i++)
        for(int j = i + 1; j <= MAX_X; j++) {
            // i, j 두 명이 팀이 됐을 때 이길 수 있는지를 확인합니다.
            // win : 두 명이 팀이 됐을 때 이길 수 있다면 true
            bool win = false;

            // num_i , num_j : 각 줄에 i, j가 나오는 개수
            int num_i = 0, num_j = 0;

            // 가로로 빙고가 만들어질 때
            for(int k = 0; k < MAX_A; k++) {
                num_i = 0, num_j = 0;
                for(int l = 0; l < MAX_A; l++) {
                    if(board[k][l] == i)
                        num_i++;
                    if(board[k][l] == j)
                        num_j++;
                }

                // 3개의 칸에 i, j가 총 3번 나오며
                // 둘 다 최소 1번 이상 나오면 승리
                if(num_i + num_j == 3 && num_i >= 1 && num_j >= 1)
                    win = true;
            }

            // 세로로 빙고가 만들어질 때
            for(int k = 0; k < MAX_A; k++) {
                num_i = 0, num_j = 0;
                for(int l = 0; l < MAX_A; l++) {
                    if(board[l][k] == i)
                        num_i++;
                    if(board[l][k] == j)
                        num_j++;
                }

                // 3개의 칸에 i, j가 총 3번 나오며
                // 둘 다 최소 1번 이상 나오면 승리
                if(num_i + num_j == 3 && num_i >= 1 && num_j >= 1)
                    win = true;
            }

            // 왼쪽 위에서 오른쪽 아래를 잇는 대각선으로 빙고가 만들어질 때
            num_i = 0, num_j = 0;
            for(int k = 0; k < MAX_A; k++) {
                if(board[k][k] == i)
                    num_i++;
                if(board[k][k] == j)
                    num_j++;
            }

            // 3개의 칸에 i, j가 총 3번 나오며
            // 둘 다 최소 1번 이상 나오면 승리
            if(num_i + num_j == 3 && num_i >= 1 && num_j >= 1)
                win = true;


            // 오른쪽 위에서 왼쪽 아래를 잇는 대각선으로 빙고가 만들어질 때
            num_i = 0, num_j = 0;
            for(int k = 0; k < MAX_A; k++) {
                if(board[k][MAX_A - k - 1] == i)
                    num_i++;
                if(board[k][MAX_A - k - 1] == j)
                    num_j++;
            }

            // 3개의 칸에 i, j가 총 3번 나오며
            // 둘 다 최소 1번 이상 나오면 승리
            if(num_i + num_j == 3 && num_i >= 1 && num_j >= 1)
                win = true;


            if(win)
                ans++;
        }

    cout << ans;
    
    return 0;
}
