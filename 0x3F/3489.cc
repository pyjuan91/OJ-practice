#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size(), m = queries.size();
        vector dp(n, bitset<1001>());
        for (int i = 0; i < n; i++)
        {
            dp[i][nums[i]] = true;
        }

        auto is_zero_array = [&]() {
            for (int i = 0; i < n; i++)
            {
                if (!dp[i][0])
                    return false;
            }
            return true;
        };

        if (is_zero_array())
            return 0;

        for (int j = 0; j < m; j++)
        {
            int left = queries[j][0], right = queries[j][1], val = queries[j][2];
            for (int i = left; i <= right; i++)
                dp[i] |= (dp[i] >> val);

            if (is_zero_array())
                return j + 1;
        }

        return -1;
    }
};

int main()
{
    return 0;
}