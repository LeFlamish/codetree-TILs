#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

// 함수 정의: 주어진 좌표들을 x축 또는 y축에 평행한 직선 3개로 커버할 수 있는지 확인
bool canCoverAllPoints(const vector<pair<int, int>>& points) {
    set<int> x_coords, y_coords;
    for (const auto& point : points) {
        x_coords.insert(point.first);
        y_coords.insert(point.second);
    }

    vector<int> x_vec(x_coords.begin(), x_coords.end());
    vector<int> y_vec(y_coords.begin(), y_coords.end());

    int n = x_vec.size();
    int m = y_vec.size();

    // 최대 3개의 직선 조합을 사용해 모든 점을 커버할 수 있는지 확인
    for (int x1 = 0; x1 < n; ++x1) {
        for (int x2 = x1; x2 < n; ++x2) {
            for (int x3 = x2; x3 < n; ++x3) {
                for (int y1 = 0; y1 < m; ++y1) {
                    for (int y2 = y1; y2 < m; ++y2) {
                        for (int y3 = y2; y3 < m; ++y3) {
                            set<pair<int, int>> covered_points;
                            // x = x_vec[x1]
                            for (const auto& point : points) {
                                if (point.first == x_vec[x1] || point.first == x_vec[x2] || point.first == x_vec[x3] ||
                                    point.second == y_vec[y1] || point.second == y_vec[y2] || point.second == y_vec[y3]) {
                                    covered_points.insert(point);
                                }
                            }
                            if (covered_points.size() == points.size()) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    if (canCoverAllPoints(points)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}