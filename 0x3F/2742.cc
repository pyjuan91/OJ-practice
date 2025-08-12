#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int paintWalls(vector<int>& cost, vector<int>& time)
    {
        const int n = cost.size();
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;

        for (int i = 0; i < n; i++)
        {
            int cur_cost = cost[i];
            int cur_contri = time[i] + 1;
            if (cur_contri > n)
                dp[n] = min(dp[n], cur_cost);
            for (int j = n - 1; j >= 0; j--)
            {
                int cover = min(n, j + cur_contri);
                dp[cover] = min(dp[cover], dp[j] + cur_cost);
            }
        }

        return dp[n];
    }
};

int main() { return 0; }