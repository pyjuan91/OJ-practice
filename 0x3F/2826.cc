#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int>& nums)
    {
        vector dp(4, 0);
        for (const auto& num : nums)
        {
            dp[num]++;
            for (int i = 1; i < num; i++)
                dp[num] = max(dp[num], dp[i] + 1);
        }
        return static_cast<int>(nums.size()) - *max_element(dp.begin(), dp.end());
    }
};

int main() { return 0; }