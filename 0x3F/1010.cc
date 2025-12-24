#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int numPairsDivisibleBy60(vector<int>& time)
    {
        array<int, 60> cnt = {};
        int res            = 0;

        for(const auto& x : time)
        {
            res += cnt[(60 - (x % 60)) % 60];
            cnt[x % 60]++;
        }

        return res;
    }
};

int main() { return 0; }