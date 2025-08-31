#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int possibleStringCount(string word, int k)
    {
        const int kMod = 1e9 + 7;
        vector<int> segs;
        int n = word.size(), cnt = 0, tot = 1;
        if (k > n)
        {
            return 0;
        }
        for (int i = 0; i < n; i++)
        {
            cnt++;
            if (i == n - 1 or word[i] != word[i + 1])
            {
                if (cnt > 1)
                {
                    if (k > 0)
                    {
                        segs.push_back(cnt - 1);
                    }
                    tot = 1LL * tot * cnt % kMod;
                }
                cnt = 0;
                k--;
            }
        }

        if (k <= 0)
            return tot;

        vector<int> dp(k, 1);
        for (const auto& seg : segs)
        {
            for (int j = 1; j < k; j++)
            {
                dp[j] = (dp[j] + dp[j - 1]) % kMod;
            }
            for (int j = k - 1; j > seg; j--)
            {
                dp[j] = (dp[j] - dp[j - seg - 1] + kMod) % kMod;
            }
        }

        return (tot - dp[k - 1] + kMod) % kMod;
    }
};

int main()
{
    return 0;
}