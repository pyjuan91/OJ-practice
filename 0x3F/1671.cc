#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> get_lis(const vector<int>& nums)
    {
        vector<int> res;
        vector<int> tails;

        for (const auto& num : nums)
        {
            auto it = lower_bound(tails.begin(), tails.end(), num);
            res.push_back(static_cast<int>(it - tails.begin()) + 1);
            if (it == tails.end())
                tails.push_back(num);
            else
                *it = num;
        }

        return res;
    }

public:
    int minimumMountainRemovals(vector<int>& nums)
    {
        vector<int> lis = std::move(get_lis(nums));
        reverse(nums.begin(), nums.end());
        vector<int> lds = std::move(get_lis(nums));

        int len_ma = 3;
        for (size_t i = 1; i + 1 < nums.size(); i++)
        {
            if (lis[i] > 1 && lds[i] > 1)
                len_ma = max(len_ma, lis[i] + lds[i] - 1);
        }
        return static_cast<int>(nums.size()) - len_ma;
    }
};

int main()
{
    return 0;
}