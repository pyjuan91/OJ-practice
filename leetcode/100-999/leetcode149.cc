#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points)
    {
        int res = 0;
        for (auto point : points) {
            map<double, int> m;
            for (auto point2 : points) {
                if (point2 == point)
                    continue;

                m[atan2(((double)point2[1] - point[1]),
                    (double)point2[0] - point[0])]
                    += 1;
            }
            for (auto i : m)
                res = max(i.second, res);
        }
        return res + 1;
    }
};
int main(void) { return 0; }