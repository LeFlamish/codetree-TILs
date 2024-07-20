#include <bits/stdc++.h>
using namespace std;
int ability[5], mx, mn, First, Second, Third, sum, ret = INT_MAX;
bool visited[5];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 5; i++) {
        cin >> ability[i];
        sum += ability[i];
    }
    for (int i = 0; i < 5; i++) {
        visited[i] = true;
        First = 0; Second = 0; Third = 0;
        for (int j = 0; j < 5; j++) {
            if (!visited[j]) {
                visited[j] = true;
                First = ability[i] + ability[j];
                for (int k = 0; k < 5; k++) {
                    if (!visited[k]) {
                        visited[k] = true;
                        for (int l = 0; l < 5; l++) {
                            visited[l] = true;
                            Second = ability[k] + ability[l];
                            Third = sum - First - Second;
                            if (First != Second && Second != Third && Third != First) {
                                mx = max(max(First, Second), Third);
                                mn = min(min(First, Second), Third);
                                ret = min(ret, mx - mn);
                            }
                            visited[l] = false;
                        }
                        visited[k] = false;
                    }
                }
                visited[j] = false;
            }
        }
        visited[i] = false;
    }
    cout << ret;
    return 0;
}