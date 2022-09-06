#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums)
    {
        int ans = INT_MIN;
        vector<int> dp(nums.size()), passZero(nums.size());
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        if (nums.size() == 3)
            return max(max(nums[0], nums[1]), nums[2]);
        dp[0] = nums[0], dp[1] = nums[1];
        dp[2] = nums[0] + nums[2];
        passZero[0] = passZero[2] = 1;
        for (int i = 3; i < nums.size() - 1; i++) {
            if (dp[i - 2] >= dp[i - 3]) {
                dp[i] = dp[i - 2] + nums[i];
                passZero[i] = passZero[i - 2];
            } else {
                dp[i] = dp[i - 3] + nums[i];
                passZero[i] = passZero[i - 3];
            }
        }
        if (passZero[nums.size() - 3] == 0) {
            ans = max(dp[nums.size() - 2], dp[nums.size() - 3] + nums[nums.size() - 1]);
        } else {
            ans = max(dp[nums.size() - 2], dp[nums.size() - 3]);
        }

        dp[1] = nums[1], dp[2] = nums[2];
        dp[3] = dp[1] + nums[3];
        for (int i = 4; i < nums.size(); i++) {
            dp[i] = nums[i] + max(dp[i - 2], dp[i - 3]);
        }

        ans = max(ans, dp[nums.size() - 1]);
        ans = max(ans, dp[nums.size() - 2]);
        return ans;
    }
};
int main(void)
{
    Solution s;
    vector<int> nums = { 1, 2, 1, 1 };
    s.rob(nums);
    return 0;
}