#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        const int kImpossible = INT32_MAX >> 1;
        vector<int> dp(amount + 1, kImpossible);
        dp[0] = 0;

        for (int i = 0; i < amount; i++)
        {
            for (const auto& coin : coins)
            {
                if (1LL * i + coin <= 1LL * amount)
                {
                    dp[i + coin] = min(dp[i + coin], dp[i] + 1);
                }
            }
        }

        return dp[amount] == kImpossible ? -1 : dp[amount];
    }
};

int main()
{
    return 0;
}