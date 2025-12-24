#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long countBadPairs(vector<int>& nums)
    {
        long long res = 0;
        int n         = nums.size();

        unordered_map<int, int> cnt;
        for(int i = 0; i < n; i++)
        {
            res += 1LL * i - cnt[i - nums[i]];
            cnt[i - nums[i]]++;
        }
        return res;
    }
};

int main() { return 0; }