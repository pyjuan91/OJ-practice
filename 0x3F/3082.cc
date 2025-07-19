#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    static constexpr int kMod = 1e9 + 7;

    int fast_power(int base, int expo)
    {
        int res = 1;
        while (expo)
        {
            if (expo & 1)
                res = 1LL * res * base % kMod;
            base = 1LL * base * base % kMod;
            expo >>= 1;
        }
        return res;
    }

public:
    int sumOfPower(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector dp(n + 1, vector(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > k)
                continue;
            for (int len = i; len >= 0; len--)
            {
                for (int new_sum = k; new_sum >= nums[i]; new_sum--)
                {
                    dp[len + 1][new_sum] = (dp[len + 1][new_sum] + dp[len][new_sum - nums[i]]) % kMod;
                }
            }
        }

        int res = 0;
        for (int len = 1; len <= n; len++)
        {
            res = (res + 1LL * dp[len][k] * fast_power(2, n - len) % kMod) % kMod;
        }
        return res;
    }
};