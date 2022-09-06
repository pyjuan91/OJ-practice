#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums)
    {
        vector<int> dp(nums.size());
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        dp[0] = nums[0], dp[1] = nums[1];
        dp[2] = nums[0] + nums[2];
        for (int i = 3; i < nums.size(); i++) {
            dp[i] = nums[i] + max(dp[i - 2], dp[i - 3]);
        }
        return max(dp[nums.size() - 1], dp[nums.size() - 2]);
    }
};
int main(void) { return 0; }