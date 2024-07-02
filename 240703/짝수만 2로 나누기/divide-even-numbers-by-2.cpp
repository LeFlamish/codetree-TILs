#include <iostream>
using namespace std;

int N, nums[101];

void divEven(int* nums, int N) {
    for (int i = 0; i < N; i++) {
        if (!(nums[i] & 1)) {
            nums[i] /= 2;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    divEven(nums, N);
    for (int i = 0; i < N; i++) {
        cout << nums[i] << ' ';
    }
    return 0;
}