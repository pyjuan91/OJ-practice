#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int minimumCardPickup(vector<int>& cards)
    {
        const int n = cards.size();
        unordered_map<int, int> pos;
        int res = numeric_limits<int>::max();

        for(int i = 0; i < n; i++)
        {
            if(pos.count(cards[i]))
            {
                res = min(res, i - pos[cards[i]]);
            }
            pos[cards[i]] = i;
        }

        return res == numeric_limits<int>::max() ? -1 : res + 1;
    }
};

int main() { return 0; }