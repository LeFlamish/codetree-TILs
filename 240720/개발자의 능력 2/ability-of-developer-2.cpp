#include <bits/stdc++.h>
using namespace std;
int a[6], First, Second, Third, sum, mx, mn, ret = INT_MAX;
bool visited[6];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < 6; i++) {
        visited[i] = true;
        First = 0; Second = 0; Third = 0;
        for (int j = 0; j < 6; j++) {
            if (!visited[j]) {
                visited[j] = true;
                First = a[i] + a[j];
                for (int k = 0; k < 6; k++) {
                    if (!visited[k]) {
                        visited[k] = true;
                        for (int x = 0; x < 6; x++) {
                            if (!visited[x]) {
                                visited[x] = true;
                                Second = a[k] + a[x];
                                Third = sum - First - Second;
                                mx = max(max(First, Second), Third);
                                mn = min(min(First, Second), Third);
                                ret = min(abs(mx - mn), ret);
                                visited[x] = false;
                            }
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