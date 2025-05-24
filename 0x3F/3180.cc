#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int maxTotalReward(vector<int> &rewardValues)
    {
        sort(rewardValues.begin(), rewardValues.end());
        const int kMax = 2 * rewardValues.back();
        vector<bool> dp(kMax);
        dp[0] = true;

        for (const auto &value : rewardValues)
        {
            for (int i = value - 1; i >= 0; i--)
                dp[i + value] = dp[i + value] || dp[i];
        }

        int res = 0;
        for (int i = kMax - 1; i >= 0; i--)
        {
            if (dp[i])
            {
                res = i;
                break;
            }
        }

        return res;
    }
};
