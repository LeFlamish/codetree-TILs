#include <iostream>
using namespace std;

int N, nums[51];

void ABS(int* arr, int N) {
    for (int i = 0; i < N; i++) {
        if (arr[i] < 0) arr[i] *= -1;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    ABS(nums, N);
    for (int i = 0; i < N; i++) {
        cout << nums[i] << ' ';
    }
    return 0;
}