#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maximumDifference(vector<int>& nums)
    {
        int mi  = numeric_limits<int>::max();
        int res = -1;
        for(const auto& num : nums)
        {
            if(mi < num)
                res = max(res, num - mi);
            mi = min(mi, num);
        }
        return res;
    }
};

int main() { return 0; }