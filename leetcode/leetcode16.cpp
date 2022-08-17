#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int first, second, third, sum, diff = INT32_MAX, ans;
        for (int i = 0; i < nums.size() - 2; i++) {
            first = i, second = i + 1, third = nums.size() - 1;
            while (second < third) {
                sum = nums[first] + nums[second] + nums[third];
                if (sum > target)
                    third--;
                if (sum < target)
                    second++;
                if (sum == target)
                    return target;
            }
            if (abs(target - sum) < diff) {
                diff = abs(target - sum);
                ans = sum;
            }
        }
        return ans;
    }
};
int main(void) { return 0; }