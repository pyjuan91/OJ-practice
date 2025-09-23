#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
    {
        size_t n = nums1.size(), m = nums2.size();
        nums1.insert(nums1.begin(), 0);
        nums2.insert(nums2.begin(), 1);
        vector dp(n + 1, vector(m + 1, 0));
        for (size_t i = 1; i <= n; i++)
        {
            for (size_t j = 1; j <= m; j++)
            {
                if (nums1[i] == nums2[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};

int main() { return 0; }