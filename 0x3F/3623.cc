#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int countTrapezoids(vector<vector<int>>& points)
    {
        const int kMod = 1e9 + 7;
        unordered_map<int, int> cnt;
        for(const auto& point : points)
        {
            cnt[point[1]]++;
        }
        vector<int> seq;
        for(const auto& [k, v] : cnt)
        {
            seq.push_back((1LL * v * (v - 1) / 2) % kMod);
        }
        int res = 0, pre_sum = 0;
        for(const auto& x : seq)
        {
            res     = (res + (1LL * pre_sum * x % kMod)) % kMod;
            pre_sum = (pre_sum + x) % kMod;
        }
        return res;
    }
};

int main() { return 0; }