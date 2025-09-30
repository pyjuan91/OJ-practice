#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxScore(vector<int>& a, vector<int>& b)
    {
        size_t n = b.size();
        vector dp(5, static_cast<long long>(-4e10));
        dp[0] = 0;

        for (size_t i = 1; i <= n; i++)
        {
            for (size_t j = 4; j >= 1; j--)
            {
                dp[j] = max(dp[j], dp[j - 1] + 1LL * b[i - 1] * a[j - 1]);
            }
        }

        return dp[4];
    }
};

int main() { return 0; }