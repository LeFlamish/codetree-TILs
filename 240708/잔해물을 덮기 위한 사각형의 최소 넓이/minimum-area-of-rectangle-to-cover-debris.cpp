#include <bits/stdc++.h>
using namespace std;
const int OFFSET = 1001;
int a, b, x, y, board[2002][2002];
bool flag;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b >> x >> y;
    for (int i = a + OFFSET; i < x + OFFSET; i++) {
        for (int j = b + OFFSET; j < y + OFFSET; j++) {
            board[i][j] = 1;
        }
    }
    cin >> a >> b >> x >> y;
    for (int i = a + OFFSET; i < x + OFFSET; i++) {
        for (int j = b + OFFSET; j < y + OFFSET; j++) {
            board[i][j] = 0;
        }
    }
    a = INT_MAX;
    b = INT_MAX;
    x = INT_MIN;
    y = INT_MIN;
    for (int i = 0; i < 2002; i++) {
        for (int j = 0; j < 2002; j++) {
            if (board[i][j] == 1) {
                flag = true;
                a = min(a, i);
                b = min(b, j);
                x = max(x, i);
                y = max(y, j);
            }
        }
    }
    if (flag) cout << (x - a + 1) * (y - b + 1);
    else cout << 0;
    return 0;
}

// 코드트리 풀이
#include <iostream>
#include <algorithm>

#define N 2
#define MAX_R 2000
#define OFFSET 1000

using namespace std;

int x1[N], y1[N];
int x2[N], y2[N];

int checked[MAX_R + 1][MAX_R + 1];

int main() {
    // 입력
    for(int i = 0; i < N; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        
        // OFFSET을 더해줍니다.
        x1[i] += OFFSET;
        y1[i] += OFFSET;
        x2[i] += OFFSET;
        y2[i] += OFFSET;
    }
    
    // 직사각형에 주어진 순으로 1, 2 번호를 붙여줍니다.
    // 격자 단위로 진행하는 문제이므로
    // x2, y2에 등호가 들어가지 않음에 유의합니다.
    for(int i = 0; i < N; i++)
        for(int x = x1[i]; x < x2[i]; x++)
            for(int y = y1[i]; y < y2[i]; y++)
                checked[x][y] = i + 1;
    
    // 1, 2 순으로 붙였는데도
    // 아직 숫자 1로 남아있는 곳들 중 최대 최소 x, y 값을 전부 계산합니다.
    int min_x = MAX_R, max_x = 0, min_y = MAX_R, max_y = 0;
    bool first_rect_exist = false;
    for(int x = 0; x <= MAX_R; x++)
        for(int y = 0; y <= MAX_R; y++)
            if(checked[x][y] == 1) {
                first_rect_exist = true;
                min_x = min(min_x, x);
                max_x = max(max_x, x);
                min_y = min(min_y, y);
                max_y = max(max_y, y);
            }
    
    // 넓이를 계산합니다.
    int area;
    // Case 1. 첫 번째 직사각형이 전혀 남아있지 않다면 넓이는 0입니다.
    if(!first_rect_exist)
        area = 0;
    // Case 2. 첫 번째 직사각형이 남아있다면, 넓이를 계산합니다.
    else
        area = (max_x - min_x + 1) * (max_y - min_y + 1);

    cout << area;
    return 0;
}
