#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
using namespace std;

class Solution
{
    static constexpr int kMod = 1e9 + 7;

public:
    int profitableSchemes(int n, int min_profit, vector<int>& group, vector<int>& profit)
    {
        int m = group.size();
        vector dp(n + 1, vector(min_profit + 1, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++)
        {
            int people_required = group[i];
            int cur_profit = profit[i];

            for (int j = n; j >= people_required; j--)
            {
                for (int prv_profit = min_profit; (prv_profit >= min_profit - cur_profit) && (prv_profit >= 0);
                     prv_profit--)
                {
                    dp[j][min_profit] = (dp[j - people_required][prv_profit] + dp[j][min_profit]) % kMod;
                }
                for (int k = min_profit - 1; k >= cur_profit; k--)
                {

                    dp[j][k] = (dp[j - people_required][k - cur_profit] + dp[j][k]) % kMod;
                }
            }
        }

        int res = 0;
        for (int i = 0; i <= n; i++)
            res = (res + dp[i][min_profit]) % kMod;
        return res;
    }
};

int main()
{
    Solution s;
    int n = 10, min_profit = 5;
    vector<int> group = {2, 3, 5};
    vector<int> profit = {6, 7, 8};
    cout << s.profitableSchemes(n, min_profit, group, profit);
    return 0;
}