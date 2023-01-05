#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<pair<int, int>>& v, int target)
    {
        int pos = v.size() - 1, cur_arrow = v[pos].first;
        target -= 1;
        while (pos >= 0) {
            if (v[pos].second < cur_arrow) {
                if (target <= 0)
                    return false;
                target -= 1;
                cur_arrow = v[pos].first;
            }
            pos -= 1;
        }
        return true;
    }
    int findMinArrowShots(vector<vector<int>>& points)
    {
        vector<pair<int, int>> v;
        for (auto i : points) {
            v.push_back(make_pair(i[0], i[1]));
        }
        sort(v.begin(), v.end());
        int left = 0, right = v.size();
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (check(v, mid)) {
                right = mid;
            } else
                left = mid;
        }
        return right;
    }
};
int main(void) { return 0; }