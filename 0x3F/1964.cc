#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles)
    {
        int n = obstacles.size();
        vector<int> res(n), lnds;
        for (int i = 0; i < n; i++)
        {
            int h = obstacles[i];
            int idx = upper_bound(lnds.begin(), lnds.end(), h) - lnds.begin();
            if (idx == lnds.size())
            {
                lnds.push_back(h);
            }
            else
            {
                lnds[idx] = h;
            }
            res[i] = idx + 1;
        }
        return res;
    }
};

int main() { return 0; }