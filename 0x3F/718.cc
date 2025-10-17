#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLength(vector<int>& nums1, vector<int>& nums2)
    {
        size_t n = nums1.size(), m = nums2.size();
        int res = 0;
        vector dp(n + 1, vector(m + 1, 0));
        for (size_t i = 1; i <= n; i++)
        {
            for (size_t j = 1; j <= m; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

int main() { return 0; }