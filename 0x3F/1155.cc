#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRollsToTarget(int n, int k, int target)
    {
        const int kMod = 1e9 + 7;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int dice_idx = 1; dice_idx <= n; dice_idx++)
        {
            vector<int> dp_next(target + 1, 0);
            for (int face_number = 1; face_number <= k; face_number++)
            {
                for (int sum = target; sum >= face_number; sum--)
                {
                    dp_next[sum] = (dp_next[sum] + dp[sum - face_number]) % kMod;
                }
            }
            dp.swap(dp_next);
        }

        return dp[target];
    }
};

int main() { return 0; }