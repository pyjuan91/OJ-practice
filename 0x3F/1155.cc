#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRollsToTarget(int n, int k, int target)
    {
        if (target < n or target > n * k)
        {
            return 0;
        }
        const int kMod = 1e9 + 7;
        vector<int> dp(target - n + 1, 0);
        dp[0] = 1;

        for (int dice_idx = 1; dice_idx <= n; dice_idx++)
        {
            int max_j = min(target - n, dice_idx * (k - 1));
            for (int j = 1; j <= max_j; j++)
            {
                dp[j] = (dp[j] + dp[j - 1]) % kMod;
            }
            for (int j = max_j; j >= k; j--)
            {
                dp[j] = (dp[j] - dp[j - k] + kMod) % kMod;
            }
        }

        return dp[target - n];
    }
};

int main() { return 0; }