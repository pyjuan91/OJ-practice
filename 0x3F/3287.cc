#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxValue(vector<int>& nums, int len)
    {
        const int n = nums.size();
        // pre_dp[i][j][k] = for the first i's element, select j of them, whether it
        // constructs or value equal to k
        vector pre_dp(n + 2, vector(len + 1, bitset<128>()));
        pre_dp[0][0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            int num = nums[i - 1];
            pre_dp[i][0] = pre_dp[i - 1][0];
            for (int j = 1; j <= i && j <= len; j++)
            {
                pre_dp[i][j] = pre_dp[i - 1][j];
                for (int k = 0; k < 128; k++)
                {
                    pre_dp[i][j][k | num] = pre_dp[i][j][k | num] || pre_dp[i - 1][j - 1][k];
                }
            }
        }

        // suf_dp is the similar mirror way
        vector suf_dp(n + 2, vector(len + 1, bitset<128>()));
        suf_dp[n + 1][0][0] = true;
        for (int i = n; i >= 1; i--)
        {
            int num = nums[i - 1];
            suf_dp[i][0] = suf_dp[i + 1][0];
            for (int j = 1; j <= min(len, n - i + 1); ++j)
            {
                suf_dp[i][j] = suf_dp[i + 1][j];
                for (int k = 0; k < 128; k++)
                {
                    suf_dp[i][j][k | num] = suf_dp[i][j][k | num] || suf_dp[i + 1][j - 1][k];
                }
            }
        }

        const int kMax = (1 << 7) - 1;
        int res = 0;
        for (int i = len; i <= n - len; i++)
        {
            for (int k1 = 0; k1 < 128; k1++)
            {
                if (pre_dp[i][len][k1])
                {
                    for (int k2 = 0; k2 < 128; k2++)
                    {
                        if (suf_dp[i + 1][len][k2])
                        {
                            res = max(res, k1 ^ k2);
                            if (res == kMax)
                                return res;
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main() { return 0; }