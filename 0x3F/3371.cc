#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int getLargestOutlier(vector<int>& nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        multiset<int> ms(nums.begin(), nums.end());
        for(int i = n - 1; i >= 0; i--)
        {
            ms.erase(ms.find(nums[i]));
            int tw_sum = sum - nums[i];
            if(tw_sum % 2 == 0 && ms.count(tw_sum / 2))
            {
                return nums[i];
            }
            ms.insert(nums[i]);
        }
        return -1;
    }
};

int main() { return 0; }