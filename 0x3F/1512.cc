#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int numIdenticalPairs(vector<int>& nums)
    {
        vector<int> cnt(101);
        int res = 0;
        for(const auto& num : nums)
        {
            res += cnt[num];
            cnt[num]++;
        }
        return res;
    }
};

int main() { return 0; }