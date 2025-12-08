#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes)
    {
        int res = 0;
        map<pair<int, int>, int> mp;
        for(const auto& domino : dominoes)
        {
            int a = domino[0], b = domino[1];
            if(a > b)
                swap(a, b);
            res += mp[make_pair(a, b)];
            mp[make_pair(a, b)]++;
        }
        return res;
    }
};

int main() { return 0; }