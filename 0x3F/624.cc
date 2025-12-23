#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maxDistance(vector<vector<int>>& arrays)
    {
        int n       = arrays.size();
        int pre_max = arrays[0].back();
        int pre_min = arrays[0].front();
        int res     = 0;

        for(int i = 1; i < n; i++)
        {
            int cur_max = arrays[i].back();
            int cur_min = arrays[i].front();

            res = max({res, cur_max - pre_min, pre_max - cur_min});

            pre_max = max(pre_max, cur_max);
            pre_min = min(pre_min, cur_min);
        }

        return res;
    }
};

int main() { return 0; }