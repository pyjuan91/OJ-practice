#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
private:
    int dp[20005] = {};

public:
    int deleteAndEarn(vector<int>& nums)
    {
        int ans = INT_MIN, n = INT_MIN;
        for (int& i : nums) {
            dp[i] += 1;
            n = max(n, i);
        }
        // for (int i = 0; i <= n; i++) {
        //     cout << i << " " << dp[i] << endl;
        // }
        for (int i = 2; i <= n; i++) {
            dp[i] = i * dp[i];
            // cout << dp[i] << endl;
            dp[i] = max(dp[i - 1], dp[i - 2] + dp[i]);
            // cout << dp[i] << endl;
        }
        return dp[n];
    }
};
int main(void)
{
    Solution s;
    vector<int> nums = { 3, 4, 2 };
    s.deleteAndEarn(nums);
    return 0;
}