#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector<vector<int>> res;
        if (intervals.size() == 0) {
            res.push_back(newInterval);
            return res;
        }

        if (newInterval[1] < intervals[0][0])
            res.push_back(newInterval);
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][1] < newInterval[0]) {
                res.emplace_back(intervals[i]);
                continue;
            }
            // if (intervals[i][0] > newInterval[1]) {
            //     res.emplace_back(intervals[i]);
            //     continue;
            // }
            int mi = min(newInterval[0], intervals[i][0]);
            int ma = newInterval[1], j;
            for (j = i; j < intervals.size(); j++) {
                if (intervals[j][0] <= newInterval[1])
                    ma = max(intervals[j][1], newInterval[1]);
                else
                    break;
            }
            res.push_back({ mi, ma });
            for (j; j < intervals.size(); j++) {
                res.push_back(intervals[j]);
            }
            break;
        }
        if (newInterval[0] > intervals[intervals.size() - 1][1])
            res.push_back(newInterval);
        return res;
    }
};
int main(void)
{
    return 0;
}