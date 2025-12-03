#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    int findMaxK(vector<int>& nums)
    {
        unordered_set<int> set_nums(nums.begin(), nums.end());
        int res = -1;
        for(const auto& x : nums)
        {
            if(x > 0 and set_nums.count(-x))
                res = max(res, x);
        }
        return res;
    }
};

int main() { return 0; }