#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {
        int ascii_sum = 0;
        for (const auto& c : s1)
            ascii_sum += static_cast<int>(c);
        for (const auto& c : s2)
            ascii_sum += static_cast<int>(c);

        size_t n = s1.size(), m = s2.size();
        vector dp(n + 1, vector(m + 1, 0));
        s1 = " " + s1, s2 = " " + s2;
        for (size_t i = 1; i <= n; i++)
        {
            for (size_t j = 1; j <= m; j++)
            {
                if (s1[i] == s2[j])
                    dp[i][j] = dp[i - 1][j - 1] + static_cast<int>(s1[i]);
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return ascii_sum - 2 * dp[n][m];
    }
};

int main() { return 0; }