#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
#define X first
#define Y second
int N, x, y, quadrant1, quadrant2, quadrant3, quadrant4, ret = INT_MAX, mx;
vector<P> points;

int count1(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (points[i].X > x && points[i].Y > y) cnt++;
    }
    return cnt;
}

int count2(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (points[i].X < x && points[i].Y > y) cnt++;
    }
    return cnt;
}

int count3(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (points[i].X < x && points[i].Y < y) cnt++;
    }
    return cnt;
}

int count4(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (points[i].X > x && points[i].Y < y) cnt++;
    }
    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        points.push_back({ x, y });
    }
    for (int i = 2; i <= 100; i += 2) {
        for (int j = 2; j <= 100; j += 2) {
            mx = 0;
            mx = max(max(max(count1(i, j), count2(i, j)), count3(i, j)), count4(i, j));
            ret = min(ret, mx);
        }
    }
    cout << ret;
    return 0;
}