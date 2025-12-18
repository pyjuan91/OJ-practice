#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maxOperations(vector<int>& nums, int k)
    {
        int res = 0;
        unordered_map<int, int> cnt;
        for(const auto& num : nums)
        {
            if(cnt.count(k - num))
            {
                res++;
                cnt[k - num]--;
                if(cnt[k - num] == 0)
                {
                    cnt.erase(k - num);
                }
            }
            else
            {
                cnt[num]++;
            }
        }
        return res;
    }
};

int main() { return 0; }