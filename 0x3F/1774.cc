#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target)
    {
        const int kMax = max(target * 2 + 5, *max_element(baseCosts.begin(), baseCosts.end()) + 1);
        vector<bool> dp(kMax);
        for (auto baseCost : baseCosts)
            dp[baseCost] = true;
        for (auto toppingCost : toppingCosts)
        {
            for (int i = kMax - 1; i >= toppingCost; i--)
            {
                if (i >= toppingCost * 2)
                    dp[i] = dp[i] || dp[i - toppingCost * 2];
                dp[i] = dp[i] || dp[i - toppingCost];
            }
        }

        for (int diff = 0; diff <= target; diff++)
        {
            if (dp[target - diff])
                return target - diff;
            if (dp[target + diff])
                return target + diff;
        }

        for (int i = target * 2; i < kMax; i++)
        {
            if (dp[i])
                return i;
        }

        return target;
    }
};