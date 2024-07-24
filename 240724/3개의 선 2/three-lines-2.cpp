#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef pair<char, int> Info;
#define X first
#define Y second
int N;
vector<P> points;
vector<Info> line;
set<int> x_coord;
set<int> y_coord;
bool visited[20];

bool canCover(vector<Info>& tmp) {
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            if (tmp[i].first == 'x') {
                if (points[j].X == tmp[i].second) visited[j] = true;
            }
            if (tmp[i].first == 'y') {
                if (points[j].Y == tmp[i].second) visited[j] = true;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) return false;
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({ x, y });
        x_coord.insert(x);
        y_coord.insert(y);
    }
    for (int i : x_coord) {
        line.push_back({ 'x', i });
    }
    for (int i : y_coord) {
        line.push_back({ 'y', i });
    }
    for (int i = 0; i < line.size(); i++) {
        for (int j = i + 1; j < line.size(); j++) {
            for (int k = j + 1; k < line.size(); k++) {
                vector<Info> tmp = { line[i], line[j], line[k] };
                if (canCover) {
                    cout << 1;
                    return 0;
                }
            }
        }
    }
    cout << 0;
    return 0;
}