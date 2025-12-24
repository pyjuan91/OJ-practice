#include <bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    int rev(int x)
    {
        int res = 0;
        while(x)
        {
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        return res;
    }
    static constexpr int kMod = 1e9 + 7;

    public:
    int countNicePairs(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int, int> cnt;

        int res = 0;

        for(int i = 0; i < n; i++)
        {
            int x = nums[i] - rev(nums[i]);
            res   = (res + cnt[x]) % kMod;
            cnt[x]++;
        }
        return res;
    }
};

int main() { return 0; }