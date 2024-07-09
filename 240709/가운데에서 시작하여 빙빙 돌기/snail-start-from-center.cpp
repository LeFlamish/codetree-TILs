#include <bits/stdc++.h>
using namespace std;
int n, x, y, dir, board[100][100], dx[] = { 1, 0, -1, 0 }, dy[] = { 0, -1, 0, 1 }; // 0 : →, 1 : ↑, 2 : ←, 3 : ↓

bool inRange(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < n) return true;
    else return false;
}

bool onLeft(int x, int y, int dir) {
    if (dir == 0) {
        int nx = x + dx[1];
        int ny = y + dy[1];
        if (inRange(nx, ny)) {
            if (board[ny][nx]) return true;
            else return false;
        }
        else return false;
    }
    else if (dir == 1) {
        int nx = x + dx[2];
        int ny = y + dy[2];
        if (inRange(nx, ny)) {
            if (board[ny][nx]) return true;
            else return false;
        }
        else return false;
    }
    else if (dir == 2) {
        int nx = x + dx[3];
        int ny = y + dy[3];
        if (inRange(nx, ny)) {
            if (board[ny][nx]) return true;
            else return false;
        }
        else return false;
    }
    else {
        int nx = x + dx[0];
        int ny = y + dy[0];
        if (inRange(nx, ny)) {
            if (board[ny][nx]) return true;
            else return false;
        }
        else return false;
    }
}

int changeDir(int x, int y, int dir) {
    if (onLeft(x, y, dir)) return dir;
    else return (dir + 1) % 4;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    x = n / 2;
    y = n / 2;
    for (int i = 1; i <= n * n; i++) {
        board[y][x] = i;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (inRange(nx, ny)) {
            x = nx;
            y = ny;
        }
        dir = changeDir(x, y, dir);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

// 코드트리 풀이
#include <iostream>

#define DIR_NUM 4
#define MAX_N 100

using namespace std;

// 전역 변수 선언:
int n;

int curr_x, curr_y;
int move_dir, move_num;

int grid[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

// 한 칸 움직입니다.
void Move() {
    // 문제에서 원하는 진행 순서대로 
    // 오른쪽 위 왼쪽 아래 방향이 되도록 정의합니다.
    int dx[DIR_NUM] = {0, -1, 0, 1};
    int dy[DIR_NUM] = {1, 0, -1, 0};

    curr_x += dx[move_dir]; curr_y += dy[move_dir];
}

bool End() {
    return !InRange(curr_x, curr_y);
}

int main() {
    // 입력:
    cin >> n;
    
    // 시작 위치와 방향, 
    // 해당 방향으로 이동할 횟수를 설정합니다. 
    curr_x = n / 2; curr_y = n / 2;
    move_dir = 0; move_num = 1;
    
    int cnt = 1;

    while(!End()) {
        // move_num 만큼 이동합니다.
        for(int i = 0; i < move_num; i++) {
            grid[curr_x][curr_y] = cnt++;
            Move();
            
            // 이동하는 도중 격자를 벗어나게 되면,
            // 움직이는 것을 종료합니다.
            if(End())
                break;
        }
        
        // 방향을 바꿉니다.
        move_dir = (move_dir + 1) % 4;
        // 만약 현재 방향이 왼쪽 혹은 오른쪽이 된 경우에는
        // 특정 방향으로 움직여야 할 횟수를 1 증가시킵니다.
        if(move_dir == 0 || move_dir == 2)
            move_num++;
    }
    
    // 출력:
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }

    return 0;
}
