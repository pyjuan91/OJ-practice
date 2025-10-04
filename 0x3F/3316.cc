#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices)
    {
        size_t n = source.size(), m = pattern.size(), k = targetIndices.size();
        vector dp(n + 1, vector(m + 1, -1));
        unordered_set<int> us(targetIndices.begin(), targetIndices.end());

        source = " " + source, pattern = " " + pattern;
        for (size_t i = 0; i <= n; i++)
        {
            dp[i][0] = (i ? dp[i - 1][0] : 0);
            if (us.count(i - 1))
                dp[i][0]++;
        }

        for (size_t i = 1; i <= n; i++)
        {
            for (size_t j = 1; j <= m; j++)
            {
                if (us.count(i - 1) and dp[i - 1][j] != -1)
                {
                    dp[i][j] = dp[i - 1][j] + 1;
                }
                else if (dp[i - 1][j] != -1)
                {
                    dp[i][j] = dp[i - 1][j];
                }

                if (source[i] == pattern[j] && dp[i - 1][j - 1] != -1)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};

int main() { return 0; }