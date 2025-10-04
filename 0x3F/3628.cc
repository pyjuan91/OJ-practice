#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    long long patty(string s)
    {
        size_t n = s.size();
        s = " " + s + " ";
        string_view t = " LCT ";
        vector dp(n + 2, vector(4, static_cast<long long>(0)));
        for (size_t i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (size_t i = 1; i <= n; i++)
        {
            for (size_t j = 1; j <= 3; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (s[i] == t[j])
                    dp[i][j] += dp[i - 1][j - 1];
            }
        }
        return dp[n][3];
    }

public:
    long long numOfSubsequences(string s)
    {
        long long kase_l = patty("L" + s);
        long long kase_c = patty(s);
        long long kase_t = patty(s + "T");

        size_t n = s.size();
        s = " " + s + " ";
        string_view t = " LCT ";
        vector pref(n + 2, vector(4, 0LL)), suff(n + 2, vector(4, 0LL));

        for (size_t i = 1; i <= n; i++)
        {
            for (size_t j = 1; j <= 3; j++)
            {
                pref[i][j] = pref[i - 1][j] + (s[i] == t[j]);
            }
        }

        for (size_t i = n; i >= 1; i--)
        {
            for (size_t j = 1; j <= 3; j++)
            {
                suff[i][j] = suff[i + 1][j] + (s[i] == t[j]);
            }
        }

        long long kase_c_buff = 0;
        for (size_t i = 1; i <= n; i++)
        {
            kase_c_buff = max(kase_c_buff, pref[i][1] * suff[i][3]);
        }
        kase_c += kase_c_buff;

        return max({ kase_l, kase_c, kase_t });
    }
};

int main() { return 0; }