#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPartitions(vector<int>& nums, int k)
    {
        int32_t const kMod = 1e9 + 7;
        auto fast_power = [&](int32_t base, int32_t expo) {
            int32_t res = 1;
            while (expo)
            {
                if (expo & 1)
                {
                    res = 1LL * base * res % kMod;
                }
                base = 1LL * base * base % kMod;
                expo >>= 1;
            }
            return res;
        };

        int64_t sum_of_nums = accumulate(nums.begin(), nums.end(), 0LL);
        if (sum_of_nums < 2 * k)
        {
            return 0;
        }

        vector dp(k, 0);
        dp[0] = 1;
        for (const auto& num : nums)
        {
            for (int i = k - 1; i >= num; i--)
            {
                dp[i] = (dp[i] + dp[i - num]) % kMod;
            }
        }

        int32_t bad_count = 0;
        for (int i = 0; i < k; i++)
        {
            bad_count = (bad_count + dp[i]) % kMod;
        }

        int res = (1LL * fast_power(2, nums.size()) - 2 * bad_count + kMod) % kMod;
        return res;
    }
};

int main()
{
    return 0;
}