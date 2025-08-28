#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int waysToReachTarget(int target, vector<vector<int>>& types)
    {
        const int kMod = 1e9 + 7;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (const auto& type : types)
        {
            int count = type[0], mark = type[1];
            vector<int> dp_next = dp;
            for (int i = 1; i <= count; i++)
            {
                int cur_mark = mark * i;
                for (int j = target; j >= cur_mark; j--)
                {
                    dp_next[j] = (dp_next[j] + dp[j - cur_mark]) % kMod;
                }
            }
            dp.swap(dp_next);
        }

        return dp[target];
    }
};

int main()
{
    return 0;
}