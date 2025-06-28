#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lastStoneWeightII(vector<int>& stones)
    {
        // [a, b, c, d] -> [a, b, (d-c)] -> [(b-d+c), a] -> [(b-d+c-a)];
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<bool> dp(sum + 1);
        dp[0] = true;
        for (auto stone : stones)
        {
            for (int i = sum; i >= stone; i--)
                dp[i] = dp[i] || dp[i - stone];
        }
        for (int plus = sum / 2 + sum % 2; plus <= sum; plus++)
        {
            if (dp[plus])
                return 2 * plus - sum;
        }
        return 0;
    }
};