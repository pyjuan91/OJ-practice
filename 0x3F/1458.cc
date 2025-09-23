#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2)
    {
        size_t n = nums1.size(), m = nums2.size();
        vector dp(n, vector(m, numeric_limits<int>::min()));
        dp[0][0] = nums1[0] * nums2[0];
        for (size_t i = 1; i < n; i++)
            dp[i][0] = max(dp[i - 1][0], nums1[i] * nums2[0]);
        for (size_t i = 1; i < m; i++)
            dp[0][i] = max(dp[0][i - 1], nums1[0] * nums2[i]);
        for (size_t i = 1; i < n; i++)
        {
            for (size_t j = 1; j < m; j++)
            {
                dp[i][j] = max({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + nums1[i] * nums2[j], nums1[i] * nums2[j] });
            }
        }
        return dp[n - 1][m - 1];
    }
};

int main() { return 0; }