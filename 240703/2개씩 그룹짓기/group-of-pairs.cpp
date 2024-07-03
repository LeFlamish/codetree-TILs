#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000

int main(){
    int n;
    cin >> n;

    int nums[2 * MAX_N];

    for(int i = 0; i < 2 * n; i++)
        cin >> nums[i];

    // nums[0]부터 nums[2n - 1]까지를 정렬함
    sort(nums, nums + 2 * n);

    int group_max = 0;
    for(int i = 0; i < n; i++) {
        // i번째와 2n - 1 - i번째 원소를 매칭
        int group_sum = nums[i] + nums[2*n - 1 - i];
        if(group_sum > group_max)
            // 최댓값 갱신
            group_max = group_sum;
    }

    cout << group_max;

    return 0;
}