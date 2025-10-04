#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        size_t n = s.size(), m = t.size();
        s = " " + s, t = " " + t;
        vector dp(n + 1, vector(m + 1, 0ULL));
        for (size_t i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (size_t i = 1; i <= n; i++)
        {
            for (size_t j = 1; j <= m; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (s[i] == t[j])
                    dp[i][j] += dp[i - 1][j - 1];
            }
        }
        return dp[n][m];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}