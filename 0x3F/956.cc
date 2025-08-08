#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int tallestBillboard(vector<int>& rods)
    {
        vector dp(5005, INT32_MIN);
        dp[0] = 0;
        for (auto const& rod : rods)
        {
            vector dp_next = dp;
            for (int diff = 0; diff < 5005; diff++)
            {
                int bar_short = dp[diff], bar_long = dp[diff] + diff;
                if (bar_short < 0)
                    continue;
                // add to short
                int tmp_bar_short = bar_short + rod;
                int new_diff = abs(tmp_bar_short - bar_long);
                int new_short = min(tmp_bar_short, bar_long);
                if (new_diff < 5005)
                    dp_next[new_diff] = max(dp_next[new_diff], new_short);
                // add to long
                int tmp_bar_long = bar_long + rod;
                new_diff = abs(tmp_bar_long - bar_short);
                if (new_diff < 5005)
                    dp_next[new_diff] = max(dp_next[new_diff], bar_short);
            }
            dp.swap(dp_next);
        }
        return dp[0];
    }
};

int main()
{
    return 0;
}