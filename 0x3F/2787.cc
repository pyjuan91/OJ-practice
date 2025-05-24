#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int numberOfWays(int n, int x)
    {
        constexpr int kMod = 1e9 + 7;

        auto big_pow = [&](int base) -> __uint128_t {
            __uint128_t res = 1;
            for (int i = 0; i < x; i++)
                res *= base;
            return res;
        };

        vector<int> cnt(n + 1, 0);
        cnt[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            auto big_num = big_pow(i);
            if (big_num > static_cast<__uint128_t>(n)) break;
            auto num = static_cast<int>(big_num);
            for (int j = n; j >= num; j--)
            {
                cnt[j] += cnt[j - num];
                cnt[j] %= kMod;
            }
        }

        return cnt[n];
    }
};