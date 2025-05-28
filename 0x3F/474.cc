#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector dp(m + 1, vector(n + 1, 0));
        for (const auto &str : strs)
        {
            array<int, 2> cnt = {};
            for (const auto &ch : str)
            {
                cnt[ch - '0']++;
            }

            for (int i = m; i >= cnt[0]; i--)
            {
                for (int j = n; j >= cnt[1]; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - cnt[0]][j - cnt[1]] + 1);
                }
            }
        }
        return dp[m][n];
    }
};