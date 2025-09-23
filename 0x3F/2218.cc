#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k)
    {
        vector<int> dp(k + 1, 0);
        for (const auto& pile : piles)
        {
            vector<int> next_dp = dp;
            int cur_sum = 0;
            for (size_t i = 0; i < pile.size(); i++)
            {
                cur_sum += pile[i];
                for (size_t j = i + 1; j <= k; j++)
                {
                    next_dp[j] = max(next_dp[j], dp[j - i - 1] + cur_sum);
                }
            }
            dp = next_dp;
        }
        return dp[k];
    }
};

int main() { return 0; }