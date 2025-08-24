#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int>& coins)
    {
        int n = coins.size();
        vector<int64_t> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            int coin = coins[i];
            for (int j = coin; j <= amount; j++)
            {
                if (dp[j] + dp[j - coin] <= INT32_MAX)
                    dp[j] += dp[j - coin];
            }
        }
        return static_cast<int32_t>(dp[amount]);
    }
};

int main() { return 0; }