#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int, int> pos;
        for(int i = 0; i < nums.size(); i++)
        {
            if(pos.count(nums[i]) and i - pos[nums[i]] <= k)
                return true;
            pos[nums[i]] = i;
        }
        return false;
    }
};

int main() { return 0; }