#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target)
    {
        int n = mat.size(), m = mat[0].size();
        const int kMax = 4901;
        bitset<kMax> reachable;
        reachable.set(0);

        for (int i = 0; i < n; i++)
        {
            bitset<4901> next_rechable;
            for (int j = 0; j < m; j++)
            {
                next_rechable |= (reachable << mat[i][j]);
            }
            swap(reachable, next_rechable);
        }

        int res = INT32_MAX;
        for (int i = 0; i < kMax; i++)
        {
            if (reachable[i])
            {
                res = min(res, abs(target - i));
            }
        }
        return res;
    }
};

int main() { return 0; }