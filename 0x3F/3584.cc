#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long maximumProduct(vector<int>& nums, int m)
    {
        long long res = numeric_limits<long long>::min();
        long long ma  = numeric_limits<long long>::min();
        long long mi  = numeric_limits<long long>::max();

        for(int i = m - 1; i < nums.size(); i++)
        {
            ma  = max(ma, 1LL * nums[i - m + 1]);
            mi  = min(mi, 1LL * nums[i - m + 1]);
            res = max({res, nums[i] * ma, nums[i] * mi});
        }

        return res;
    }
};

int main() { return 0; }