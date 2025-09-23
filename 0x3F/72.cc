#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        size_t n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, numeric_limits<int>::max()));
        for (size_t i = 0; i <= m; i++)
            dp[0][i] = i;
        for (size_t i = 0; i <= n; i++)
            dp[i][0] = i;
        word1 = " " + word1, word2 = " " + word2;

        for (size_t i = 1; i <= n; i++)
        {
            for (size_t j = 1; j <= m; j++)
            {
                if (word1[i] == word2[j])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min({ dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j] }) + 1;
            }
        }

        return dp[n][m];
    }
};

int main() { return 0; }